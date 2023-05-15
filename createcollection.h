#ifndef CREATECOLLECTION_H
#define CREATECOLLECTION_H

#include <QDialog>

namespace Ui {
class createcollection;
}

class createcollection : public QDialog
{
    Q_OBJECT

public:
    explicit createcollection(QWidget *parent = nullptr);
    ~createcollection();

private:
    Ui::createcollection *ui;
};

#endif // CREATECOLLECTION_H
