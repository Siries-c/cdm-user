#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QUdpSocket>
#include "cudp.h"
#include "ctcp.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:


private slots:
    void sendMessage();       //发送消息
    void on_connectButton_clicked();  //连接按钮槽函数
    void on_sendClearBtn_2_clicked();

private:
    Ui::MainWindow *ui;
    QUdpSocket *udpSocket;
    CUDP *cudp = nullptr;
    CTCP *ctcp = nullptr;
    QHostAddress serverAddress;
    quint16 serverPort;

    QHostAddress clientAddress;
    quint16 clientPort;
};

#endif // MAINWINDOW_H
