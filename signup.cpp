#include "signup.h"
#include "ui_signup.h"
#include "path.h"
SignUp::SignUp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SignUp)
{
    ui->setupUi(this);
    setWindowTitle("Sign up");
}

SignUp::~SignUp()
{
    delete ui;
}

void SignUp::on_register_2_clicked()
{
    QString username = ui->username->text();
    QString password = ui->password->text();

    if(username.trimmed().isEmpty() || password.trimmed().isEmpty()) {
        QMessageBox msg;
        msg.setText("Username or password cannot be empty!");
        msg.exec();
        return;  // If username or password is empty, return from this function
    }

    QJsonObject obj;
    QFile file(folderPath + "users.json");
    file.open(QIODevice::ReadOnly);
    QByteArray data = file.readAll();
    file.close();
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonArray arr = doc.array();
    obj = arr.at(0).toObject();
    if(obj.contains(username)){
        QMessageBox msg;
        msg.setText("Username already exist!");
        msg.exec();
    }else{
        obj.insert(username,password);
        arr.pop_front();
        arr.append(obj);
        QJsonDocument doc2(arr);
        file.open(QIODevice::WriteOnly);
        file.write(doc2.toJson());
        file.close();
        QString path = folderPath + username;
        QByteArray str = path.toLatin1();
        char* c = str.data();
        mkdir(c,0777);
        QMessageBox msg;
        msg.setText("Successful!");
        msg.exec();
    }
}


void SignUp::on_back_clicked()
{
    reject();
}

