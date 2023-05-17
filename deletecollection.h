#ifndef DELETECOLLECTION_H
#define DELETECOLLECTION_H

#include <QDialog>

namespace Ui {
class DeleteCollection;
}

class DeleteCollection : public QDialog
{
    Q_OBJECT

public:
    explicit DeleteCollection(QString p,QString name,QWidget *parent = nullptr);
    ~DeleteCollection();

private slots:
    void on_confirm_clicked();

    void on_cancel_clicked();

private:
    Ui::DeleteCollection *ui;
    QString path;
    QString filename;
};

#endif // DELETECOLLECTION_H
