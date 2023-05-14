#include "signup.h"
#include "ui_signup.h"

SignUp::SignUp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SignUp)
{
    ui->setupUi(this);
}

SignUp::~SignUp()
{
    delete ui;
}

void SignUp::on_register_2_clicked()
{
    QString username = ui->username->text();
    QString password = ui->password->text();
    QJsonObject obj;
    QFile file(":/resources/users.json");
    if(file.open(QIODevice::ReadWrite)){
        QString str = file.readAll();
        QJsonDocument doc = QJsonDocument::fromJson(str.toUtf8());
        obj = doc[0].toObject();
        obj.insert(username,password);
        doc.setObject(obj);
        QByteArray arr = "["+QJsonDocument(obj).toJson()+"]";
        QTextStream stream(&file);
        file.write(arr);
        QMessageBox box;
        box.setText(QString::number(obj.size()));
        box.exec();
        file.close();
    }else{
        QMessageBox box;
        box.setText("aaa");
        box.exec();
    }
}


void SignUp::on_back_clicked()
{

}

