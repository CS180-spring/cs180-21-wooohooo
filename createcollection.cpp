#include "createcollection.h"
#include "ui_createcollection.h"
#include <fstream>
#include <QFile>
#include <QMessageBox>
CreateCollection::CreateCollection(QString p,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateCollection)
{
    ui->setupUi(this);
    path = p;
    setWindowTitle("Create new collection");
}

CreateCollection::~CreateCollection()
{
    delete ui;
}

void CreateCollection::on_confirm_clicked()
{
    QString name = ui->name->text();
    QString filePath = path + "/" + name;
    QFile file(filePath);
    if(file.exists()){
        QMessageBox msg;
        msg.setText("File exists!");
        msg.exec();
    }else{
        QByteArray str = filePath.toLatin1();
        char* c = str.data();
        std::ofstream file(c);
        file.close();
        reject();
    }

}


void CreateCollection::on_pushButton_clicked()
{
    reject();
}

