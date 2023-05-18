#include "createcollection.h"
#include "ui_createcollection.h"
#include <fstream>
#include <QFile>
#include <QMessageBox>
#include "path.h"
CreateCollection::CreateCollection(QString s,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateCollection)
{
    ui->setupUi(this);
    username = s;
    setWindowTitle("Create new collection");
}

CreateCollection::~CreateCollection()
{
    delete ui;
}

void CreateCollection::on_confirm_clicked()
{
    QString name = ui->name->text();
    QString filePath = folderPath + username + "/" + name;
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

