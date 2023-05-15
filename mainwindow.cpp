#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ptrlogin = new login();
    ptrsign_up = new sign_up();

    ptrdisplaycollection = new displaycollection();
    ptradddocument = new adddocument();
    ptreditdocument = new editdocument();
}

MainWindow::~MainWindow()
{
    delete ptrlogin;
    delete ptrsign_up;

    delete ptrdisplaycollection;
    delete ptradddocument;
    delete ptreditdocument;
    delete ui;

}




void MainWindow::on_btn_login_main_clicked()
{
    ptrlogin->show();
}


void MainWindow::on_btn_sign_up_main_clicked()
{
    ptrsign_up->show();
}

