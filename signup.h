#ifndef SIGNUP_H
#define SIGNUP_H

#include <QDialog>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <vector>
#include <QFile>
#include <QMessageBox>
#include <sys/stat.h>
namespace Ui {
class SignUp;
}

class SignUp : public QDialog
{
    Q_OBJECT

public:
    explicit SignUp(QWidget *parent = nullptr);
    ~SignUp();

private slots:
    void on_register_2_clicked();

    void on_back_clicked();

private:
    Ui::SignUp *ui;
};

#endif // SIGNUP_H
