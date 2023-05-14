#include "collection.h"
#include "ui_collection.h"

Collection::Collection(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Collection)
{
    ui->setupUi(this);
    ui->label->setText("Hello,");
    std::string path = "C:/Users/zhika/OneDrive/Desktop/cs180/180DB/zk123";

    // show all the file names
    for(const auto &entry : std::filesystem::directory_iterator(path)){
        std::string str = entry.path().filename().u8string();
        ui->listWidget->addItem(QString::fromStdString(str));
    }
}

Collection::~Collection()
{
    delete ui;
}
