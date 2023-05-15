#include "createcollection.h"
#include "ui_createcollection.h"

createcollection::createcollection(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::createcollection)
{
    ui->setupUi(this);
}

createcollection::~createcollection()
{
    delete ui;
}
