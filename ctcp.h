#ifndef CTCP_H
#define CTCP_H

#include <QObject>
#include <QTcpSocket>
#include <QHostAddress>
#include <QDebug>

class CTCP : public QObject
{
    Q_OBJECT
public:
    explicit CTCP(QObject *parent = nullptr);

    bool open(QHostAddress ip, quint16 port);
    bool close();
    bool state();

private:
    QTcpSocket *tcpSocket;
};

#endif // CTCP_H
