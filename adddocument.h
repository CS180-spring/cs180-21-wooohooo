#ifndef ADDDOCUMENT_H
#define ADDDOCUMENT_H

#include <QDialog>

namespace Ui {
class addDocument;
}

class addDocument : public QDialog
{
    Q_OBJECT

public:
    explicit addDocument(QString usingPath, QString selectedKeyName, QWidget *parent = nullptr);
    ~addDocument();

private slots:
    void on_save_clicked();

private:
    Ui::addDocument *ui;
    QString usingPath;
    QString selectedKeyName;
};

#endif // ADDDOCUMENT_H
