#ifndef DISPLAYDOCUMENT_H
#define DISPLAYDOCUMENT_H

#include <QDialog>
#include "fieldAndValue.h"
#include <QTextBrowser>
#include <vector>
#include "adddocument.h"


namespace Ui {
class displayDocument;
}

class displayDocument : public QDialog
{
    Q_OBJECT

public:
    explicit displayDocument(QString usingPath, QString selectedKeyName, QWidget *parent = nullptr);
    void displayKeyContents(const std::vector<FieldAndValue> &keyContents);
    ~displayDocument();

private slots:
    void on_back_clicked();
    void on_refresh_clicked();
    void on_add_clicked();

private:
    Ui::displayDocument *ui;
    std::vector<FieldAndValue> keyContents;
    void refreshKeyContents();
    addDocument* addDoc;
    QString usingPath;
    QString selectedKeyName;

};

#endif // DISPLAYDOCUMENT_H
