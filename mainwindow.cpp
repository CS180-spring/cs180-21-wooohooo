#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix(":/resources/database.jpg");
    int w = ui->label->width();
    int h = ui->label->height();
    ui->label->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
    QFont font = ui->title->font();
    font.setBold(true);
    font.setPointSize(20);
    ui->title->setFont(font);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_login_clicked()
{
    QString username = ui->username->text();
    QString password = ui->password->text();
    std::vector<QJsonObject> users;
    QFile myFile("C:/Users/zhika/OneDrive/Desktop/cs180/180DB/users.json");
    std::ofstream f(":/resources/zk123.json");
    QString jsonStr;
    QJsonObject jsonObj;
    if(myFile.open(QIODevice::ReadOnly | QIODevice::Text)){
        jsonStr = myFile.readAll();
        myFile.close();
        QJsonDocument doc = QJsonDocument::fromJson(jsonStr.toUtf8());
        jsonObj = doc[0].toObject();
        if(jsonObj.contains(username)){
            if(jsonObj.take(username).toString() != password){
                QMessageBox msg;
                msg.setText("Wrong password!");
                msg.exec();
            }else{
                this->hide();
                Collection c;
                c.setModal(true);
                c.exec();
                if(c.close()){
                    this->show();
                }
            }
        }else{
            QMessageBox msg;
            msg.setText("Username doesn't exist!");
            msg.exec();
        }
    }
}


void MainWindow::on_signup_clicked()
{
    this->hide();
    SignUp s;
    s.setModal(true);
    s.exec();
    if(s.close()){
        this->show();
    }
}

