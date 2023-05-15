#include "login.h"
#include "ui_login.h"

login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    ptrcollection = new collection();
}

login::~login()
{
    delete ui;
}

void login::on_btn_login_real_clicked()
{
    ptrcollection->show();
}

