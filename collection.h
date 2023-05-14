#ifndef COLLECTION_H
#define COLLECTION_H

#include <QDialog>
#include <iostream>
#include <filesystem>
#include <string>
#include <dirent.h>
#include <sys/types.h>
namespace Ui {
class Collection;
}

class Collection : public QDialog
{
    Q_OBJECT

public:
    explicit Collection(QWidget *parent = nullptr);
    ~Collection();

private:
    Ui::Collection *ui;
};

#endif // COLLECTION_H
