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

void displayCollection::on_open_clicked() {
    // 检查是否选中了某个键
    QListWidgetItem* selectedItem = ui->keyList->currentItem();
    if (!selectedItem) {
        return; // 如果没有选中键，则直接返回
    }

    // 获取选中的键名
    QString selectedKeyName = selectedItem->text();

    // 存储选中键的所有内容的新 vector
    std::vector<FieldAndValue> selectedKeyContents;

    // 获取选中键的内容
    QString path = folderPath + this->username + "/" + this->fileName;
    QFile file(path);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QString str = file.readAll();
        file.close();

        QJsonDocument doc = QJsonDocument::fromJson(str.toUtf8());
        if (!doc.isNull() && doc.isObject()) {
            QJsonObject obj = doc.object();

            // 检查选中键是否存在于集合中
            if (obj.contains(selectedKeyName)) {
                QJsonValue selectedValue = obj.value(selectedKeyName);

                // 检查选中键的值是否为数组类型
                if (selectedValue.isArray()) {
                    QJsonArray selectedArray = selectedValue.toArray();

                    // 遍历数组中的每个元素
                    for (const QJsonValue& item : selectedArray) {
                        if (item.isObject()) {
                            QJsonObject itemObj = item.toObject();

                            // 创建 FieldAndValue 对象，并将字段和值添加到 selectedKeyContents 中
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

    // 在这里可以使用 selectedKeyContents 做进一步的处理，根据需求进行操作

    // 创建并显示 DisplayDocument 窗口
    displayDocument* displayDoc = new displayDocument();
    displayDoc->displayKeyContents(selectedKeyContents);
    displayDoc->show();
    this->close();
}


displayCollection::~displayCollection()
{
    delete ui;
}

void displayCollection::on_back_clicked()
{
    reject();
}


