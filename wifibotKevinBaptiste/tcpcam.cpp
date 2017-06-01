#include "tcpclient.h"
#include <unistd.h>
#include <math.h>

TCPClient::TCPCam(QString IP, int port)
{
    setupCam(IP, port);
    QObject::connect(this->socket, SIGNAL(connected()), this, SLOT(connectionCamEstablished()));
    QObject::connect(this->socket, SIGNAL(readyRead()), this, SLOT(getDataCam()));
    QObject::connect(this->socket, SIGNAL(disconnected()), this, SLOT(onDisconnectionCam()));
    QObject::connect(this->socket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(onErrorCam()));

}

void TCPClient::setupCam(QString IP, int port)
{
    this->wifibotIP = IP;
    this->wifibotPort = port;
    this->socket = new QTcpSocket();
}

void TCPClient::getDataCam()
{
    //We the client receives data
    QByteArray data = this->socket->readAll();

}

void TCPClient::connectToCam()
{
    if(!this->isConnected)
    {
        emit reportConnectionCam("Status : Establishing connection");
        this->socket->connectToHost(this->wifibotIP, this->wifibotPort);
    }
}

void TCPClient::disconnectFromCam()
{
    if(this->isConnected)
    {
        emit reportConnectionCam("Status : Disconnecting");
        this->socket->disconnectFromHost();
    }
}

void TCPClient::onDisconnectionCam()
{
    std::cout << "Disconnected" << std::endl;
    this->isConnected = false;
    emit reportConnectionCam("Status : disconnected");
}

void TCPClient::connectionCamEstablished()
{
    //After connection was established
    std::cout << "Connection successfully established" << std::endl;
    this->isConnected = true;
    emit reportConnectionCam("Status : connected");


}

void TCPClient::onErrorCam()
{
    emit reportConnectionCam("Status : Error");
    Error *winError = new Error(this->socket->errorString());
    winError->exec();
    winError = NULL;
    free(winError);
}



