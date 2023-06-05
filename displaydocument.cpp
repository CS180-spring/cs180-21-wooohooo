#include "displaydocument.h"
#include "ui_displaydocument.h"
#include "ui_adddocument.h"
#include "fieldandvalue.h"
#include "path.h"
#include <QFileInfo>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>


displayDocument::displayDocument(QString usingPath, QString selectedKeyName, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::displayDocument),
    addDoc(nullptr),
    usingPath(usingPath),
    selectedKeyName(selectedKeyName)
{
    ui->setupUi(this);
}

void displayDocument::displayKeyContents(const std::vector<FieldAndValue>& keyContents)
{
    QString text;

    QFile file(usingPath);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QString str = file.readAll();
        file.close();

        QJsonDocument doc = QJsonDocument::fromJson(str.toUtf8());
        if (!doc.isNull() && doc.isObject()) {
            QJsonObject obj = doc.object();

            if (obj.contains(selectedKeyName)) {
                QJsonValue selectedValue = obj.value(selectedKeyName);

                if (selectedValue.isArray()) {
                    QJsonArray selectedArray = selectedValue.toArray();

                    for (const QJsonValue& value : selectedArray) {
                        if (value.isObject()) {
                            QJsonObject itemObj = value.toObject();

                            for (const QString& key : itemObj.keys()) {
                                QJsonValue fieldValue = itemObj.value(key);

                                if (fieldValue.isString()) {
                                    text += key + ": " + fieldValue.toString() + "\n";
                                } else if (fieldValue.isDouble()) {
                                    text += key + ": " + QString::number(fieldValue.toInt()) + "\n";
                                }
                            }

                            text += "\n";
                        }
                    }
                }
            }
        }
    }

    ui->document->setPlainText(text);
}


void displayDocument::refreshKeyContents()
{
    displayKeyContents(keyContents);
}

void displayDocument::on_add_clicked()
{

    addDocument addDoc(usingPath,selectedKeyName,this);
    addDoc.exec();
}



void displayDocument::on_refresh_clicked()
{
    refreshKeyContents();
}



void displayDocument::on_back_clicked()
{
    reject();
}


displayDocument::~displayDocument()
{
    delete ui;
    if (addDoc) {
        delete addDoc;
    }
}
