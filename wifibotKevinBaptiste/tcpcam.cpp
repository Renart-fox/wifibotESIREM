#include "tcpCam.h"
#include <unistd.h>
#include <math.h>
#include <QNetworkRequest>

TCPCam::TCPCam(QString IP, int port)
{
    setupCam(IP, port);
    QObject::connect(this->socket, SIGNAL(connected()), this, SLOT(connectionCamEstablished()));
    QObject::connect(this->socket, SIGNAL(readyRead()), this, SLOT(getDataCam()));
    QObject::connect(this->socket, SIGNAL(disconnected()), this, SLOT(onDisconnectionCam()));
    QObject::connect(this->socket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(onErrorCam()));

}

void TCPCam::setupCam(QString IP, int port)
{
    this->wifibotIP = IP;
    this->wifibotPort = port;

    this->socket = new QTcpSocket();


}

void TCPCam::getDataCam()
{
    //We the client receives data
    std::cout << "data incoming from cam" << std::endl;
    QByteArray data = this->socket->readAll();
    std::cout << data.size() << std::endl;


}

void TCPCam::connectToCam()
{
    if(!this->CamIsConnected)
    {
        emit reportCamConnection("Status : Establishing connection");
        this->socket->connectToHost(this->wifibotIP, this->wifibotPort);
    }
}

void TCPCam::disconnectFromCam()
{
    if(this->CamIsConnected)
    {
        emit reportCamConnection("Status : Disconnecting");
        this->socket->disconnectFromHost();
    }
}

void TCPCam::onDisconnectionCam()
{
    std::cout << "Disconnected" << std::endl;
    this->CamIsConnected = false;
    emit reportCamConnection("Status : disconnected");
}





void TCPCam::connectionCamEstablished()
{
    //After connection was established
    std::cout << "Connection Cam successfully established" << std::endl;
    this->CamIsConnected = true;
    emit reportCamConnection("Status : connected");

    this->timer = new QTimer(this);
    connect(this->timer, SIGNAL(timeout()), this, SLOT(synchroniseCam()));
    timer->setSingleShot(false);
    timer->start(500);
}

void TCPCam::synchroniseCam()
{
    // Refreshes the connection with an empty frame
    QByteArray data;
    data.append(255);

    this->socket->write(data);
}

void TCPCam::onErrorCam()
{
    emit reportCamConnection("Status : Error");
    Error *winError = new Error(this->socket->errorString());
    winError->exec();
    winError = NULL;
    free(winError);
}





void TCPCam::moveCam(char dirCam)
{
    //if(dirCam != lastDirection)
    //{
        //lastDirection = dirCam;


        switch(dirCam)
        {
            case 'u':
                std::cout << "send" << std::endl;
                const QUrl url = QUrl("192.168.1.106:8080?action=command&dest=0&plugin=0&id=10094853&value=-200"); //On récupère l'URL entrée par l'utilisateur.
                QNetworkRequest requete(url); //On crée notre requête


                break;

        //}

    }
}

