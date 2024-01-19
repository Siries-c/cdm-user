#ifndef CUDP_H
#define CUDP_H

#include <QObject>
#include <QHostAddress>
#include <QUdpSocket>
class CUDP : public QObject
{
    Q_OBJECT
public:
    explicit CUDP(QObject *parent = nullptr);
public:
    bool open(QHostAddress ip, quint16 port);
    bool close();
    bool state();
    void sendMessage(QByteArray message);
signals:

private:
    QUdpSocket *udpSocket;
};

#endif // CUDP_H
