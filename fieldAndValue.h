#ifndef FIELDANDVALUE_H
#define FIELDANDVALUE_H

#include <QString>
#include <QMap>

class FieldAndValue {
public:
    void setField(const QString& name, int value) {
        intFields[name] = value;
    }

    void setField(const QString& name, const QString& value) {
        stringFields[name] = value;
    }

    const QMap<QString, int>& getIntFields() const {
        return intFields;
    }

    const QMap<QString, QString>& getStringFields() const {
        return stringFields;
    }

private:
    QMap<QString, int> intFields;
    QMap<QString, QString> stringFields;
};


#endif // FIELDANDVALUE_H
