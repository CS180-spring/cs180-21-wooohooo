#include "displaycollection.h"
#include "ui_displaycollection.h"
#include <QFileInfo>
#include "path.h"
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
        ui->plainTextEdit->insertPlainText("Empty!");
    }else{
        if(file.open(QIODevice::ReadOnly | QIODevice::Text)){
            str = file.readAll();
            ui->plainTextEdit->insertPlainText(str);
            file.close();
        }
    }

}

displayCollection::~displayCollection()
{
    delete ui;
}

void displayCollection::on_back_clicked()
{
    reject();
}

