#ifndef DISPLAYDOCUMENT_H
#define DISPLAYDOCUMENT_H

#include <QWidget>
#include "fieldAndValue.h"
#include <QTextBrowser>
#include <vector>


namespace Ui {
class displayDocument;
}

class displayDocument : public QWidget
{
    Q_OBJECT

public:
    explicit displayDocument(QWidget *parent = nullptr);
    ~displayDocument();
    void displayKeyContents(const std::vector<FieldAndValue> &keyContents);

private:
    Ui::displayDocument *ui;
};

#endif // DISPLAYDOCUMENT_H
