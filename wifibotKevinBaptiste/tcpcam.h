#include <QTcpSocket>
#include <iostream>
#include "error.h"
#include <QTimer>
#include "networkingopt.h"

#ifndef TCPCAM_H
#define TCPCAM_H


class TCPCam : public QObject
{
Q_OBJECT
public:
    TCPCam(QString IP="192.168.1.106", int port=8080);
    int getCamPort(){
        return this->wifibotPort;
    }
    QString getCamIP(){
        return this->wifibotIP;
    }
    bool getConnectionCamStatus(){
        return this->CamIsConnected;
    }


    void moveCam(char dirCam);
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
    bool CamIsConnected = false;
private slots:
    void connectionCamEstablished();
    void getDataCam();
    void onDisconnectionCam();
    void onErrorCam();
    void synchroniseCam();
};

#endif // TCPCAM_H
