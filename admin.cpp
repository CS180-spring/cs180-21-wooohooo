#include "admin.h"
#include "ui_admin.h"
#include <QMessageBox>
#include <QStandardPaths>
#include <QFile>

Admin::Admin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Admin)
{
    ui->setupUi(this);
}

Admin::~Admin()
{
    delete ui;
}

void Admin::on_pushButton_clicked()
{
    QString username = ui->Username->text();
    QString password = ui->Password->text();

    // Get the path to the documents folder
    QString documentsPath = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);

    // Open the file containing the user information
    QFile file(documentsPath + "/information.txt");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream in(&file);
        QString line;
        bool success = false;

        // Read the file line by line and search for a matching username and password
        while (!in.atEnd())
        {
            line = in.readLine();
            QStringList fields = line.split(" ");
            if (fields.size() == 2 && fields.at(0) == username && fields.at(1) == password)
            {
                success = true;
                break;
            }
        }

        file.close();

        // Display a message indicating whether the login was successful or not
        if (success)
        {
            QMessageBox msg;
            msg.setText("Login successfully!");
            msg.exec();
        }
        else
        {
            QMessageBox msg;
            msg.setText("Incorrect username/password.");
            msg.exec();
        }
    }
}



