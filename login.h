#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include "collection.h"

namespace Ui {
class login;
}

class login : public QDialog
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();

private slots:
    void on_btn_login_real_clicked();

private:
    Ui::login *ui;
    collection *ptrcollection;
};

#endif // LOGIN_H
