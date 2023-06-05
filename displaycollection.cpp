#include "path.h"
#include "displaycollection.h"
#include "ui_displaycollection.h"
#include <QFileInfo>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include "addkey.h"
#include "fieldAndValue.h"
#include "displaydocument.h"
#include "finddocument.h"

displayCollection::displayCollection(QString username,QString filename,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::displayCollection),
    username(username),
    fileName(filename)
{
    ui->setupUi(this);
    this->username = username;
    this->fileName = filename;
    setWindowTitle(fileName);
    QString str;
    ui->label->setText("Collection: " + fileName);
    QString path = folderPath + this->username + "/" + fileName;
    QFile file(path);
    if(file.size() == 0){
        ui->keyList->addItem("Empty!");
    }else{
        if(file.open(QIODevice::ReadOnly | QIODevice::Text)){
            str = file.readAll();
            file.close();

            QJsonDocument doc = QJsonDocument::fromJson(str.toUtf8());
            if(!doc.isNull()){
                if(doc.isObject()){
                    QJsonObject obj = doc.object();
                    QStringList keys = obj.keys();
                    for(const auto &key : keys){
                        ui->keyList->addItem(key);
                    }
                }
            }else{
                ui->keyList->addItem("Invalid JSON!");
            }
        }
    }
    connect(ui->refresh, &QPushButton::clicked, this, &displayCollection::refreshKeyList);
    usingPath = folderPath + this->username + "/" + fileName;
}

void displayCollection::refreshKeyList() {
    ui->keyList->clear();

    QString path = folderPath + this->username + "/" + this->fileName;
    QFile file(path);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QString str = file.readAll();
        file.close();

        QJsonDocument doc = QJsonDocument::fromJson(str.toUtf8());
        if (!doc.isNull() && doc.isObject()) {
            QJsonObject obj = doc.object();
            QStringList keys = obj.keys();
            for (const QString &key : keys) {
                ui->keyList->addItem(key);
            }
        }
    }
}

void displayCollection::on_add_clicked() {
    addKey addKeyDialog(this->username, this->fileName, this);
    addKeyDialog.exec();
}

void displayCollection::on_open_clicked() {
    QListWidgetItem* selectedItem = ui->keyList->currentItem();
    if (!selectedItem) {
        return;
    }

    QString selectedKeyName = selectedItem->text();

    std::vector<FieldAndValue> selectedKeyContents;

    QString path = folderPath + this->username + "/" + this->fileName;
    QFile file(path);
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

                    for (const QJsonValue& item : selectedArray) {
                        if (item.isObject()) {
                            QJsonObject itemObj = item.toObject();

                            FieldAndValue fieldValue;

                            for (const QString& key : itemObj.keys()) {
                                QJsonValue value = itemObj.value(key);

                                if (value.isString()) {
                                    fieldValue.setField(key, value.toString());
                                } else if (value.isDouble()) {
                                    fieldValue.setField(key, value.toInt());
                                }
                            }

                            selectedKeyContents.push_back(fieldValue);
                        }
                    }
                }
            }
        }
    }
    displayDocument* displayDoc = new displayDocument(usingPath, selectedKeyName, this);
    displayDoc->displayKeyContents(selectedKeyContents);
    displayDoc->exec();
    delete displayDoc;
}

void displayCollection::on_find_clicked() {
    findDocument* findDoc = new findDocument(usingPath, this);
    findDoc->exec();
    delete findDoc;
}



displayCollection::~displayCollection()
{
    delete ui;
}

void displayCollection::on_back_clicked()
{
    reject();
}


