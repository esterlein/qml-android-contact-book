#ifndef NETWORK_H
#define NETWORK_H

#include <QObject>
#include <QUdpSocket>
#include <QHostAddress>

class Network : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool connected READ connected NOTIFY connectedChanged)

public:
    explicit Network(QObject *parent = 0);
    const bool& connected() const;
    void send(qint8 type);
    void read();

signals:
    void connectedChanged();

public slots:
    void connectToServer();

private:
    QUdpSocket socket;
    QHostAddress serveradress;
    int serverport;
    bool b_connected;
};

#endif // NETWORK_H
