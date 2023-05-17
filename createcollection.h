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
    explicit CreateCollection(QString p,QWidget *parent = nullptr);
    ~CreateCollection();

private slots:
    void on_confirm_clicked();

    void on_pushButton_clicked();

private:
    Ui::CreateCollection *ui;
    QString path;
};

#endif // CREATECOLLECTION_H
