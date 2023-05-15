#include "editdocument.h"
#include "ui_editdocument.h"

editdocument::editdocument(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editdocument)
{
    ui->setupUi(this);
}

editdocument::~editdocument()
{
    delete ui;
}
