#include "deletecollection.h"
#include "ui_deletecollection.h"
#include <QFile>
#include "path.h"
DeleteCollection::DeleteCollection(QString p,QString name,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeleteCollection)
{
    ui->setupUi(this);
    folder = p;
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
    QFile file(folderPath + folder + "/" + filename);
    if(file.remove()){
        reject();
    }
}


void DeleteCollection::on_cancel_clicked()
{
    reject();
}

