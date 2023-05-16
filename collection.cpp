#include "collection.h"
#include "ui_collection.h"
#include <QDir>
#include <QFileInfoList>
Collection::Collection(QString s,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Collection)
{
    username = s;
    ui->setupUi(this);
    ui->label->setText("Hello, " + username + "!");
    QFont font = ui->label->font();
    font.setBold(true);
    font.setPointSize(10);
    ui->label->setFont(font);

    QString path = "C:/Users/zhika/OneDrive/Desktop/cs180/180DB/" + username;
    QDir folder(path);
    QFileInfoList list = folder.entryInfoList(QDir::Files);
    if(list.empty()){
        ui->listWidget->addItem("No collections!");
    }else{
        for(const QFileInfo& info : list){
            QString filename = info.fileName();
            ui->listWidget->addItem(filename);
        }
    }
}

Collection::~Collection()
{
    delete ui;
}

void Collection::on_open_clicked()
{
    QListWidgetItem *currentItem = ui->listWidget->currentItem();
    QString str = currentItem->text();
    if(str != "No collections!"){
        displayCollection dc(str);
        dc.setModal(true);
        dc.exec();
        if(dc.close()){
            this->show();
        }
    }
}


void Collection::on_create_clicked()
{

}


void Collection::on_delete_2_clicked()
{
    QListWidgetItem *currentItem = ui->listWidget->currentItem();
    QString str = currentItem->text();
    QMessageBox msg;
    msg.setText(str);
    msg.exec();
}


void Collection::on_back_clicked()
{
    reject();
}

