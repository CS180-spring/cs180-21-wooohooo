#ifndef CREATECOLLECTION_H
#define CREATECOLLECTION_H

#include <QDialog>

namespace Ui {
class CreateCollection;
}

class CreateCollection : public QDialog
{
    Q_OBJECT

public:
    explicit CreateCollection(QString s,QWidget *parent = nullptr);
    ~CreateCollection();

private slots:
    void on_confirm_clicked();

    void on_pushButton_clicked();

private:
    Ui::CreateCollection *ui;
    QString username;
};

#endif // CREATECOLLECTION_H
