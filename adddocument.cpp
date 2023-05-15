#include "adddocument.h"
#include "ui_adddocument.h"

adddocument::adddocument(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adddocument)
{
    ui->setupUi(this);
}

adddocument::~adddocument()
{
    delete ui;
}
