#include "displaycollection.h"
#include "ui_displaycollection.h"

displayCollection::displayCollection(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::displayCollection)
{
    ui->setupUi(this);
}

displayCollection::~displayCollection()
{
    delete ui;
}
void displayCollection::set_filename(std::string s){
    fileName = s;
}
