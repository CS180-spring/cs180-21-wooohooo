#include "searchdocument.h"
#include "ui_searchdocument.h"

searchdocument::searchdocument(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::searchdocument)
{
    ui->setupUi(this);
}

searchdocument::~searchdocument()
{
    delete ui;
}
