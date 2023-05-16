#include "displaycollection.h"
#include "ui_displaycollection.h"

displayCollection::displayCollection(QString s,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::displayCollection)
{
    ui->setupUi(this);
    fileName = s;
    QString str;
     QFile file("C:/Users/zhika/OneDrive/Desktop/cs180/180DB/zk123/" + fileName);
    if(file.open(QIODevice::ReadOnly | QIODevice::Text)){
        str = file.readAll();
        ui->plainTextEdit->insertPlainText(str);
        file.close();
    }

}

displayCollection::~displayCollection()
{
    delete ui;
}
