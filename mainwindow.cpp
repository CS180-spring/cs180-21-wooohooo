#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    signUpWindow = new signUp(this);

    connect(signUpWindow, SIGNAL(registrationSuccessful()), this, SLOT(handleRegistrationSuccessful()));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete signUpWindow;
}


void MainWindow::on_pushButton_clicked()
{
    this->hide();
    admin = new Admin(nullptr);
    admin->setModal(true);
    admin->show();
}

void MainWindow::on_pushButton_2_clicked()
{
    this->hide();
    signUpWindow->setModal(true);
    signUpWindow->show();
}

void MainWindow::handleRegistrationSuccessful()
{
    this->show();
}

