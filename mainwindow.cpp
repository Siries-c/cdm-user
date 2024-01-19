#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDebug>
#include <QNetworkDatagram>
#include <QMessageBox>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent), ui(new Ui::MainWindow), udpSocket(new QUdpSocket(this))
{
    ui->setupUi(this);
    cudp = new CUDP();



    connect(ui->sendButton, &QPushButton::clicked, this, &MainWindow::sendMessage);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete udpSocket;
}


///*
//连接到服务端
//*/
//void MainWindow::connectToServer()
//{

//    if (!connectedState()) {
//        QString serverIp = ui->ipLineEdit->text();
//        quint16 serverPort = ui->portLineEdit->text().toUInt();
//        udpSocket->connectToHost(QHostAddress(serverIp), serverPort);
//    }

//}

///*
//断开连接
//*/
//void MainWindow::disconnectFromServer()
//{
//    if (connectedState()) {
//        //
//        udpSocket->disconnectFromHost();
//    }
//}


void MainWindow::sendMessage()
{

        QByteArray message = ui->sendEdit->toPlainText().toUtf8();
        cudp->sendMessage(message);

}


void MainWindow::on_connectButton_clicked()
{
    //单击后判断输入信息是否正确
    //
    //判断当前是否连接
    serverAddress = QHostAddress(ui->ipLineEdit->text());
    serverPort = ui->portLineEdit->text().toUShort();
    cudp->state();
    if(!cudp->state()){
        //如果是连接则断开
        //执行断开函数
        cudp->open(serverAddress,serverPort);

        //更新按钮显示的文本
        ui->connectButton->setText("断开");
    }else{
        //如果没有连接则连接
        //执行连接函数
    cudp->close();

        //更新按钮显示的文本
        ui->connectButton->setText("连接");
    }
}

//bool MainWindow::connectedState()
//{
//    qDebug() << "连接状态：" << udpSocket->state();
//    if(udpSocket->state() == QAbstractSocket::ConnectedState)
//    {
//        return true;
//    }else{
//        return false;
//    }
//}


void MainWindow::on_sendClearBtn_2_clicked()
{
    ui->sendEdit->clear();
}

