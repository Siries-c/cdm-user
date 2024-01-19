#include "ctcp.h"

CTCP::CTCP(QObject *parent)
    : QObject(parent), tcpSocket(new QTcpSocket(this))
{

}

bool CTCP::open(QHostAddress ip, quint16 port)
{
    if (tcpSocket->state() == QAbstractSocket::UnconnectedState) {
        tcpSocket->connectToHost(ip, port);

        if (tcpSocket->waitForConnected()) {
            qDebug() << "Connected to" << ip.toString() << "on port" << port;
            return true;
        } else {
            qDebug() << "Connection failed.";
            return false;
        }
    } else {
        qDebug() << "Socket is already open.";
        return false;
    }
}

bool CTCP::close()
{
    if (tcpSocket->state() != QAbstractSocket::UnconnectedState) {
        tcpSocket->disconnectFromHost();
        if (tcpSocket->waitForDisconnected()) {
            qDebug() << "Disconnected.";
            return true;
        } else {
            qDebug() << "Disconnecting failed.";
            return false;
        }
    } else {
        qDebug() << "Socket is already closed.";
        return false;
    }
}

bool CTCP::state()
{
    return tcpSocket->state();
}
