#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "sign_up.h"
#include "login.h"

#include "displaycollection.h"
#include "adddocument.h"
#include "editdocument.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_btn_login_main_clicked();

    void on_btn_sign_up_main_clicked();

private:
    Ui::MainWindow *ui;
    login *ptrlogin;
    sign_up *ptrsign_up;

    displaycollection *ptrdisplaycollection;
    adddocument *ptradddocument;
    editdocument *ptreditdocument;

};
#endif // MAINWINDOW_H
