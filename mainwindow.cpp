#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix(":/img/database.jpg");
    int w = ui->label->width();
    int h = ui->label->height();
    ui->label->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
    QFont font = ui->title->font();
    font.setBold(true);
    font.setPointSize(20);
    ui->title->setFont(font);
}

MainWindow::~MainWindow()
{
    delete ui;
}
