#include "finddocument.h"
#include "ui_finddocument.h"
#include "displaycollection.h"
#include "path.h"
#include <QFileInfo>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

findDocument::findDocument(QString usingPath, QWidget *parent) :
    QDialog(parent),
    usingPath(usingPath),
    ui(new Ui::findDocument)
{
    ui->setupUi(this);
    qDebug() << "usingpath: " << usingPath;

    connect(ui->deleteButton, SIGNAL(clicked()), this, SLOT(on_delete_clicked()));
}

findDocument::~findDocument()
{
    delete ui;
}

void findDocument::on_search_clicked()
{
    matchedItems.clear();
    QString searchTerm = ui->searchInput->text();
    ui->print->clear();


    QFile file(usingPath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Error", "Unable to open the file!");
        return;
    }

    QByteArray jsonData = file.readAll();
    file.close();

    QJsonParseError jsonError;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData, &jsonError);

    if (jsonError.error != QJsonParseError::NoError) {
        QMessageBox::critical(this, "Error", "Invalid JSON!");
        return;
    }

    jsonObject = jsonDoc.object();

    for (auto it = jsonObject.constBegin(); it != jsonObject.constEnd(); ++it) {
        QString key = it.key();
        QJsonValue value = it.value();

        if (value.isArray()) {
            QJsonArray jsonArray = value.toArray();

            int index = 0;
            for (const QJsonValue& arrayValue : jsonArray) {
                if (arrayValue.isObject()) {
                    QJsonObject itemObject = arrayValue.toObject();

                    for (auto itemIt = itemObject.constBegin(); itemIt != itemObject.constEnd(); ++itemIt) {
                        QString itemKey = itemIt.key();
                        QJsonValue itemValue = itemIt.value();

                        if (itemValue.isString() && itemValue.toString().contains(searchTerm, Qt::CaseInsensitive)) {
                            ui->print->append(QString("Key: %1").arg(key));

                            for (auto matchIt = itemObject.constBegin(); matchIt != itemObject.constEnd(); ++matchIt) {
                                QString matchKey = matchIt.key();
                                QJsonValue matchValue = matchIt.value();

                                if (matchValue.isString()) {
                                    ui->print->append(QString("%1: %2").arg(matchKey).arg(matchValue.toString()));
                                }
                            }
                            matchedItems.append({key, index, itemObject});
                            ui->print->append("-------------------");
                            break;
                        }
                    }
                }
                ++index;
            }
        }
    }
}

void findDocument::on_overwrite_clicked()
{
    QString newContent = ui->editInput->toPlainText();

    QJsonParseError jsonError;
    QJsonDocument newJsonDoc = QJsonDocument::fromJson(newContent.toUtf8(), &jsonError);

    if (jsonError.error != QJsonParseError::NoError) {
        QMessageBox::critical(this, "Error", "Invalid JSON!");
        return;
    }

    QJsonObject newJsonObject = newJsonDoc.object();

    // Assume matchedItems is a member variable that holds all matched items
    if (matchedItems.size() == 1) {
        MatchedItem& matchedItem = matchedItems[0];

        // Update the item in jsonObject
        QJsonArray parentArray = jsonObject[matchedItem.parentKey].toArray();
        parentArray[matchedItem.index] = newJsonObject;
        jsonObject[matchedItem.parentKey] = parentArray;

        QJsonDocument doc(jsonObject);
        // Write jsonObject back to file
        QFile file(usingPath);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QMessageBox::critical(this, "Error", "Unable to open the file!");
            return;
        }

        file.write(doc.toJson());

        file.close();

        QMessageBox::information(this, "Success", "The item has been overwritten successfully.");
    } else {
        QMessageBox::critical(this, "Error", "No item or more than one item were found, unable to overwrite.");
    }
}

void findDocument::on_delete_clicked()
{
    // Assume matchedItems is a member variable that holds all matched items
    if (matchedItems.size() == 1) {
        MatchedItem& matchedItem = matchedItems[0];

        // Update the item in jsonObject
        QJsonArray parentArray = jsonObject[matchedItem.parentKey].toArray();
        parentArray.removeAt(matchedItem.index);
        jsonObject[matchedItem.parentKey] = parentArray;

        QJsonDocument doc(jsonObject);
        // Write jsonObject back to file
        QFile file(usingPath);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QMessageBox::critical(this, "Error", "Unable to open the file!");
            return;
        }

        file.write(doc.toJson());

        file.close();

        QMessageBox::information(this, "Success", "The item has been deleted successfully.");
    } else {
        QMessageBox::critical(this, "Error", "No item or more than one item were found, unable to delete.");
    }
}


void findDocument::on_back_clicked()
{
    jsonObject = QJsonObject();
    matchedItems.clear();
    reject();
}

