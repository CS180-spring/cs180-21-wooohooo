#ifndef SEARCHDOCUMENT_H
#define SEARCHDOCUMENT_H

#include <QDialog>

namespace Ui {
class searchdocument;
}

class searchdocument : public QDialog
{
    Q_OBJECT

public:
    explicit searchdocument(QWidget *parent = nullptr);
    ~searchdocument();

private:
    Ui::searchdocument *ui;
};

#endif // SEARCHDOCUMENT_H
