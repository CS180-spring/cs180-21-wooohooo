#ifndef EDITDOCUMENT_H
#define EDITDOCUMENT_H

#include <QDialog>

namespace Ui {
class editdocument;
}

class editdocument : public QDialog
{
    Q_OBJECT

public:
    explicit editdocument(QWidget *parent = nullptr);
    ~editdocument();

private:
    Ui::editdocument *ui;
};

#endif // EDITDOCUMENT_H
