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
    explicit displayCollection(QString username,QString filename,QWidget *parent = nullptr);
    QString getUsingPath() const;
    ~displayCollection();

private slots:
    void on_back_clicked();
    void on_add_clicked();
    void refreshKeyList();
    void on_open_clicked();
    void on_find_clicked();

signals:
    void openButtonClicked(const QString& key);

private:
    Ui::displayCollection *ui;
    QString username;
    QString fileName;
    QString selectedKey;
    QString usingPath;
};

#endif // DISPLAYCOLLECTION_H
