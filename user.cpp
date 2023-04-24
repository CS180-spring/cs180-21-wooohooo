#include "user.h"
#include "ui_user.h"

User::User(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::User)
{
    ui->setupUi(this);
}

User::~User()
{
    delete ui;
}

void User::on_pushButton_clicked()
{
    QString user,password;
    user = ui->Username->text();
    password = ui->Password->text();

}
