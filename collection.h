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
    explicit Collection(QWidget *parent = nullptr);
    ~Collection();

private slots:
    void on_open_clicked();

    void on_create_clicked();

    void on_delete_2_clicked();

private:
    Ui::Collection *ui;
};

#endif // COLLECTION_H
