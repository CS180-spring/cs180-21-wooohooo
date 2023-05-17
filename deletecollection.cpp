#include "deletecollection.h"
#include "ui_deletecollection.h"
#include <QFile>
DeleteCollection::DeleteCollection(QString p,QString name,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeleteCollection)
{
    ui->setupUi(this);
    path = p;
    filename = name;
    setWindowTitle("Delete Collection");
    ui->label->setText("Delete '" + filename + "' ?");
}

DeleteCollection::~DeleteCollection()
{
    delete ui;
}

void DeleteCollection::on_confirm_clicked()
{
    QFile file(path + "/" + filename);
    if(file.remove()){
        reject();
    }
}


void DeleteCollection::on_cancel_clicked()
{
    reject();
}

