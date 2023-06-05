#ifndef ADDKEY_H
#define ADDKEY_H

#include <QDialog>

namespace Ui {
class addKey;
}

class addKey : public QDialog
{
    Q_OBJECT

public:
    explicit addKey(QString username, QString fileName, QWidget *parent = nullptr);
    ~addKey();

private:
    Ui::addKey *ui;
    QString username;
    QString fileName;

private slots:
    void on_keyConfirm_clicked();
    void on_keyCancel_clicked();
};

#endif // ADDKEY_H
