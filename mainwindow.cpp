#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    this->hide();
    admin = new Admin(nullptr);
    admin->setModal(true);
    admin->exec();
    if(admin->close())
        this->show();
}

void MainWindow::on_pushButton_2_clicked()
{
    this->hide();
    user = new User(nullptr);
    user->setModal(true);
    user->exec();
    if(user->close())
        this->show();
}
