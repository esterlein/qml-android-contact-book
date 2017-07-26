#include <QByteArray>
#include <QDataStream>
#include "network.h"

Network::Network(QObject *parent) : QObject(parent)
{
    socket.bind(serveradress, serverport);
    connect(&socket, SIGNAL(readyRead()), SLOT(read()));
}

void Network::send(qint8 type)
{
    QByteArray data;
    QDataStream out(&data, QIODevice::WriteOnly);
    out << qint64(0);
    out << qint8(type);
    out.device()->seek(qint64(0));
    out << qint64(data.size() - sizeof(qint64));
    socket.writeDatagram(data, serveradress, serverport);
}

void Network::read()
{
    QByteArray datagram;
    datagram.resize(socket.pendingDatagramSize());
    socket.readDatagram(datagram.data(), datagram.size(), &serveradress);

    QDataStream in(&datagram, QIODevice::ReadOnly);
    qint64 size = -1;
    if(in.device()->size() > sizeof(qint64)){

    }
}

const bool& Network::connected() const
{

}

void Network::connectToServer()
{

}
