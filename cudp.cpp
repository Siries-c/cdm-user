#include "cudp.h"

CUDP::CUDP(QObject *parent)
    : QObject(parent), udpSocket(new QUdpSocket(this))
{

}

bool CUDP::open(QHostAddress ip, quint16 port)
{
    if (udpSocket->state() == QAbstractSocket::UnconnectedState) {
        udpSocket->connectToHost(ip, port);
    } else {
        qDebug() << "Socket is already open.";
        return false;
    }
}

bool CUDP::close()
{
//    if (udpSocket->state() != QAbstractSocket::UnconnectedState) {
//        udpSocket->close();
//        qDebug() << "Socket closed.";
        return true;
//    } else {
//        qDebug() << "Socket is already closed.";
//        return false;
//    }
}

bool CUDP::state()
{
    qDebug() << "连接状态：" << udpSocket->state();
    if(udpSocket->state() == QAbstractSocket::ConnectedState)
    {
        return true;
    }else{
        return false;
    }
}


void CUDP::sendMessage(QByteArray message)
{

        udpSocket->write(message);

}
