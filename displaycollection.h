#ifndef DISPLAYCOLLECTION_H
#define DISPLAYCOLLECTION_H

#include <QDialog>
#include <string>
namespace Ui {
class displayCollection;
}

class displayCollection : public QDialog
{
    Q_OBJECT

public:
    explicit displayCollection(QWidget *parent = nullptr);
    ~displayCollection();
    void set_filename(std::string s);

private:
    Ui::displayCollection *ui;
    std::string fileName;
};

#endif // DISPLAYCOLLECTION_H
