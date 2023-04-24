#include "admin.h"
#include "ui_admin.h"
#include <QMessageBox>
Admin::Admin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Admin)
{
    ui->setupUi(this);
}

Admin::~Admin()
{
    delete ui;
}

void Admin::on_pushButton_clicked()
{
    QString user,password;
    user = ui->Username->text();
    password = ui->Password->text();
    if(user == "123" && password == "12345"){
        QMessageBox msg;
        msg.setText("Login successfully!");
        msg.exec();

    }
    else{
        QMessageBox msg;
        msg.setText("Incorrect username/password.");
        msg.exec();
    }
}
