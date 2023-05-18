//#include "displaycollection.h"
//#include "ui_displaycollection.h"
//#include <QFileInfo>
#include "path.h"
//displayCollection::displayCollection(QString username,QString filename,QWidget *parent) :
//    QDialog(parent),
//    ui(new Ui::displayCollection)
//{
//    ui->setupUi(this);
//    this->username = username;
//    this->fileName = filename;
//    setWindowTitle(fileName);
//    QString str;
//    ui->label->setText("Collection: " + fileName);
//    QString path = folderPath + this->username + "/" + fileName;
//    QFile file(path);
//    if(file.size() == 0){
//        ui->keyList->insertPlainText("Empty!");
//    }else{
//        if(file.open(QIODevice::ReadOnly | QIODevice::Text)){
//            str = file.readAll();
//            ui->keyList->insertPlainText(str);
//            file.close();
//        }
//    }

//}

//displayCollection::~displayCollection()
//{
//    delete ui;
//}

//void displayCollection::on_back_clicked()
//{
//    reject();
//}

#include "displaycollection.h"
#include "ui_displaycollection.h"
#include <QFileInfo>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include "addkey.h"

displayCollection::displayCollection(QString username,QString filename,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::displayCollection)
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
}

void displayCollection::refreshKeyList() {
    ui->keyList->clear(); // 清空 keyList

    // 重新加载 keyList 的内容
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
    addKey addKeyDialog(this->username, this->fileName, this);  // 创建 addKey 对话框
    addKeyDialog.exec();        // 显示 addKey 对话框
}



displayCollection::~displayCollection()
{
    delete ui;
}

void displayCollection::on_back_clicked()
{
    reject();
}


