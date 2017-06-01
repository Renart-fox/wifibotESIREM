#include <QTcpSocket>
#include <iostream>
#include "error.h"
#include <QTimer>

#ifndef TCPCLIENT_H
#define TCPCLIENT_H


class TCPClient : public QObject
{
Q_OBJECT
public:
    TCPClient(QString IP="192.168.1.106", int port=8080);
    int getCamPort(){
        return this->wifibotPort;
    }
    QString getCamIP(){
        return this->wifibotIP;
    }
    bool getConnectionCamStatus(){
        return this->isConnected;
    }



    void connectToCam();
    void disconnectFromCam();
signals:
    void reportCamConnection(QString status);
private:
    void setupCam(QString IP, int port);
    QTimer* timer;
    QString wifibotIP;
    int wifibotPort;
    QTcpSocket *socket;
    bool isConnected = false;
private slots:
    void connectionCamEstablished();
    void getDataCam();
    void onDisconnectionCam();
    void onErrorCam();
};

#endif // TCPCLIENT_H
