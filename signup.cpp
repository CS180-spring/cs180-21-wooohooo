#include <QStandardPaths>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <fstream>
#include <iostream>
#include "signup.h"
#include "ui_signup.h"

signUp::signUp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::signUp)
{
    ui->setupUi(this);
}

signUp::~signUp()
{
    delete ui;
}

void signUp::on_registerButton_clicked()
{
    QString newUsername = ui->newUsername->text();
    QString newPassword = ui->newPassword->text();

    QString documentsPath = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);
    QFile file(documentsPath + "/information.txt");
    if (file.open(QIODevice::Append | QIODevice::Text))
    {
        QTextStream out(&file);
        out << newUsername << " " << newPassword << "\n";
        file.close();
    }

    // Display a message to indicate that the sign-up was successful
    QMessageBox::information(this, tr("Message"), tr("Sign up successful!"));

    // Emit the registrationSuccessful signal
    emit registrationSuccessful();

    // Close the sign-up window
    this->close();
}
