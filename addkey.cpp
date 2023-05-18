#include "addkey.h"
#include "ui_addkey.h"
#include <QFileInfo>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include "path.h"
#include "displaycollection.h"

addKey::addKey(QString username, QString fileName, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addKey),
    username(username),
    fileName(fileName)
{
    ui->setupUi(this);
    connect(ui->keyConfirm, &QPushButton::clicked, this, &addKey::on_keyConfirm_clicked);
}

void addKey::on_keyConfirm_clicked() {
    QString newKey = ui->keyname->text();

    // 打开你的 JSON 文件
    QString path = folderPath + this->username + "/" + this->fileName;
    QFile file(path);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        // TODO: 添加错误处理代码
        return;
    }

    // 读取 JSON 数据
    QString str = file.readAll();
    QJsonDocument doc = QJsonDocument::fromJson(str.toUtf8());
    file.close();

    // 修改 JSON 数据
    if(!doc.isNull()){
        if(doc.isObject()){
            QJsonObject obj = doc.object();
            obj.insert(newKey, QJsonValue());  // 插入一个新的键，值为 null
            doc.setObject(obj);
        }
    }

    // 保存 JSON 数据
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        // TODO: 添加错误处理代码
        return;
    }
    file.write(doc.toJson());
    file.close();

    this->close();
}

void addKey::on_keyCancel_clicked(){
    reject();
}


addKey::~addKey()
{
    delete ui;
}
