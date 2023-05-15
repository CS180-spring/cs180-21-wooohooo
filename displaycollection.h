#ifndef DISPLAYCOLLECTION_H
#define DISPLAYCOLLECTION_H

#include <QDialog>

namespace Ui {
class displaycollection;
}

class displaycollection : public QDialog
{
    Q_OBJECT

public:
    explicit displaycollection(QWidget *parent = nullptr);
    ~displaycollection();

private:
    Ui::displaycollection *ui;
};

#endif // DISPLAYCOLLECTION_H
