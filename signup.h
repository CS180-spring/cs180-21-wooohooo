#ifndef SIGNUP_H
#define SIGNUP_H

#include <QDialog>

namespace Ui {
class signUp;
}

class signUp : public QDialog
{
    Q_OBJECT

public:
    explicit signUp(QWidget *parent = nullptr);
    ~signUp();

signals:
    void registrationSuccessful();

private slots:
    void on_registerButton_clicked();

private:
    Ui::signUp *ui;
};

#endif // SIGNUP_H
