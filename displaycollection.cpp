#include "displaycollection.h"
#include "ui_displaycollection.h"

displaycollection::displaycollection(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::displaycollection)
{
    ui->setupUi(this);
}

displaycollection::~displaycollection()
{
    delete ui;
}
