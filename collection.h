#ifndef COLLECTION_H
#define COLLECTION_H

#include <QDialog>
#include "createcollection.h"

namespace Ui {
class collection;
}

class collection : public QDialog
{
    Q_OBJECT

public:
    explicit collection(QWidget *parent = nullptr);
    ~collection();

private slots:
    void on_create_allcollection_clicked();

private:
    Ui::collection *ui;
    createcollection *ptrcreatecollection;
};

#endif // COLLECTION_H
