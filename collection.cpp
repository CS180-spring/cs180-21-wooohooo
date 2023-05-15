#include "collection.h"
#include "ui_collection.h"

collection::collection(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::collection)
{
    ui->setupUi(this);
    ptrcreatecollection = new createcollection();
}

collection::~collection()
{
    delete ui;
    delete ptrcreatecollection;
}

void collection::on_create_allcollection_clicked()
{
    ptrcreatecollection->show();
}

