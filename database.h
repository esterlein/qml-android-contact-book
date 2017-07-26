#ifndef DATABASE_H
#define DATABASE_H

#define ZERO 0
#define ONE 1

#include <QObject>

class DataBase : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool connected READ connected NOTIFY connectedChanged)

public:
    explicit DataBase(QObject* parent = 0);
    const bool& connected() const;

signals:
    void connectedChanged();

public slots:
    void connectToDatabase();
    void sendQuery(int query);

private:
    bool b_connected;
    const QString host, database, username, password;
    const int port;
};

#endif // DATABASE_H
