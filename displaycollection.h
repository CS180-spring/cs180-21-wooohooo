#ifndef DISPLAYCOLLECTION_H
#define DISPLAYCOLLECTION_H

#include <QDialog>
#include <string>
#include <QFile>
#include <QMessageBox>
namespace Ui {
class displayCollection;
}

class displayCollection : public QDialog
{
    Q_OBJECT

public:
    explicit displayCollection(QString s,QWidget *parent = nullptr);
    ~displayCollection();

private slots:
    void on_back_clicked();

private:
    Ui::displayCollection *ui;
    QString fileName;
};

#endif // DISPLAYCOLLECTION_H