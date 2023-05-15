#ifndef ADDDOCUMENT_H
#define ADDDOCUMENT_H

#include <QDialog>

namespace Ui {
class adddocument;
}

class adddocument : public QDialog
{
    Q_OBJECT

public:
    explicit adddocument(QWidget *parent = nullptr);
    ~adddocument();

private:
    Ui::adddocument *ui;
};

#endif // ADDDOCUMENT_H
