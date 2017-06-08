#include <QTcpSocket>
#include <iostream>
#include "error.h"
#include <QTimer>
#include "networkingopt.h"

#ifndef TCPCLIENT_H
#define TCPCLIENT_H


class TCPClient : public QObject
{
Q_OBJECT
public:
    TCPClient(QString IP="192.168.1.106", int port=15020);
    int getRobotPort(){
        return this->wifibotPort;
    }
    QString getRobotIP(){
        return this->wifibotIP;
    }
    bool getConnectionStatus(){
        return this->isConnected;
    }

    void setNewIP(QString ip);

    void move(char dir, int speed);

    void connectToBot();
    void disconnectFromBot();
signals:
    void reportConnection(QString status);
    void signalBat(int valB);
    void signalInfAD(int iad);
    void signalInfAG(int iag);
private:
    void setup(QString IP, int port);
    QTimer* timer;
    QString wifibotIP;
    int wifibotPort;
    QTcpSocket *socket;
    bool isConnected = false;
    char lastDirection = 'n';
private slots:
    void connectionEstablished();
    void getData();
    void onDisconnection();
    void onError();
    void synchroniseBot();
};

#endif // TCPCLIENT_H
