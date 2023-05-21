#include "displaydocument.h"
#include "ui_displaydocument.h"
#include "fieldandvalue.h"




displayDocument::displayDocument(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::displayDocument)
{
    ui->setupUi(this);
}

void displayDocument::displayKeyContents(const std::vector<FieldAndValue>& keyContents)
{
    QString text;

    for (const FieldAndValue& fieldValue : keyContents)
    {
        const QMap<QString, int>& intFields = fieldValue.getIntFields();
        const QMap<QString, QString>& stringFields = fieldValue.getStringFields();

        // 输出整数字段
        for (auto iter = intFields.constBegin(); iter != intFields.constEnd(); ++iter)
        {
            text += iter.key() + ": " + QString::number(iter.value()) + "\n";
        }

        // 输出字符串字段
        for (auto iter = stringFields.constBegin(); iter != stringFields.constEnd(); ++iter)
        {
            text += iter.key() + ": " + iter.value() + "\n";
        }

        // 输出空行分隔符
        text += "\n";
    }

    ui->document->setPlainText(text);
}

displayDocument::~displayDocument()
{
    delete ui;
}
