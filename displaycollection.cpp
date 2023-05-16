#include "displaycollection.h"
#include "ui_displaycollection.h"
#include <QFileInfo>
displayCollection::displayCollection(QString s,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::displayCollection)
{
    ui->setupUi(this);
    fileName = s;
    QString str;
    ui->label->setText("Collection: " + fileName);
    QString path = "C:/Users/zhika/OneDrive/Desktop/cs180/180DB/zk123/" + fileName;
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

