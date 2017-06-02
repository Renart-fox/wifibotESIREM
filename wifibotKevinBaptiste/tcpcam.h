#include <iostream>
#include "error.h"
#include <QNetworkAccessManager>
#include <QNetworkRequest>

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

    void moveCam(char dirCam);
private:
    void setupCam(QString IP, int port);
    QString wifibotIP;
    int wifibotPort;
};

#endif // TCPCAM_H
