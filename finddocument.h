#ifndef FINDDOCUMENT_H
#define FINDDOCUMENT_H

#include <QDialog>
#include <QFile>
#include <QMessageBox>
#include <QDebug>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonParseError>
#include <QJsonValue>
#include "path.h"
#include "displaycollection.h"
#include "ui_finddocument.h"

struct MatchedItem {
    QString parentKey;
    int index;
    QJsonObject object;
};

namespace Ui {
class findDocument;
}

class findDocument : public QDialog
{
    Q_OBJECT

public:
    explicit findDocument(QString usingPath, QWidget *parent = nullptr);
    ~findDocument();

private slots:
    void on_search_clicked();
    void on_overwrite_clicked();
    void on_back_clicked();
    void on_delete_clicked();

private:
    Ui::findDocument *ui;
    QString usingPath;
    QJsonObject jsonObject;
    QVector<MatchedItem> matchedItems;
};

#endif // FINDDOCUMENT_H

