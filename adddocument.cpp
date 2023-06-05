#include "adddocument.h"
#include "ui_adddocument.h"
#include "displaydocument.h"
#include "path.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonParseError>
#include <QMessageBox>

addDocument::addDocument(QString usingPath, QString selectedKeyName, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addDocument),
    usingPath(usingPath),
    selectedKeyName(selectedKeyName)
{
    ui->setupUi(this);
    qDebug() << "usingpath: " << usingPath;
    qDebug() << "keyname: " << selectedKeyName;

}

addDocument::~addDocument()
{
    delete ui;
}

void addDocument::on_save_clicked()
{
    QString inputText = ui->input->toPlainText();
    QJsonParseError jsonError;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(inputText.toUtf8(), &jsonError);

    if (jsonError.error != QJsonParseError::NoError) {
        QMessageBox::critical(this, "Error", "Invalid JSON!");
        return;
    }

    QFile file(usingPath);
    if (!file.open(QIODevice::ReadWrite | QIODevice::Text)) {
        QMessageBox::critical(this, "Error", "Unable to open the file!");
        return;
    }

    QJsonDocument existingDoc = QJsonDocument::fromJson(file.readAll());
    QJsonObject obj = existingDoc.object();

    if (obj.contains(selectedKeyName)) {
        QJsonValue selectedValue = obj.value(selectedKeyName);

        QJsonArray selectedArray;
        if (selectedValue.isArray()) {
            selectedArray = selectedValue.toArray();
        } else if (selectedValue.isNull()) {
            // If the value is null, we create an empty array
        } else {
            QMessageBox::critical(this, "Error", "Unsupported JSON type!");
            return;
        }

        if (jsonDoc.isArray()) {
            // Add new items to the existing array
            QJsonArray newArray = jsonDoc.array();
            for (const QJsonValue& value : newArray) {
                if (value.isObject()) {
                    selectedArray.append(value.toObject());
                }
            }
        } else if (jsonDoc.isObject()) {
            selectedArray.append(jsonDoc.object());
        }

        obj[selectedKeyName] = selectedArray;
    } else {
        // If the key doesn't exist, directly add new key-value pair
        obj[selectedKeyName] = jsonDoc.object();
    }

    file.resize(0);
    file.seek(0);
    file.write(QJsonDocument(obj).toJson());
    file.close();

    this->accept();
}












