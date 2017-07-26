#ifndef MODEL_H
#define MODEL_H

#include <QObject>
#include <QString>
#include <QVariantList>
#include <QTime>
#include <QDateTime>
#include <QJsonObject>

class Model : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QVariantList listContacts READ getContacts NOTIFY contactsChanged)

public:
    explicit Model(QObject* parent = 0);
    QVariantList getContacts();
    QVariantList listContacts;

signals:
    void contactsChanged();

public slots:
    void jsonLoader(int type);
    void saveContact(QString name, QString phone, QString email, const int number);
    void delContact(const int number);

private:
    void jsonParser(QJsonObject jsonObject, int type);
};

#endif // MODEL_H
