#ifndef COLLECTION_H
#define COLLECTION_H

#include <QDialog>
#include <iostream>
#include <filesystem>
#include <string>
#include <QMessageBox>
#include <displaycollection.h>
namespace Ui {
class Collection;
}

class Collection : public QDialog
{
    Q_OBJECT

public:
    explicit Collection(QString s,QWidget *parent = nullptr);
    ~Collection();

private slots:
    void on_open_clicked();

    void on_create_clicked();

    void on_delete_2_clicked();

    void on_back_clicked();

    void on_show_clicked();

private:
    Ui::Collection *ui;
    QString username;
};

#endif // COLLECTION_H
