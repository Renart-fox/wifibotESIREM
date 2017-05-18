#include "tcpclient.h"

TCPClient::TCPClient(QString IP, int port)
{
    setup(IP, port);
    QObject::connect(this->socket, SIGNAL(connected()), this, SLOT(connectionEstablished()));
    QObject::connect(this->socket, SIGNAL(readyRead()), this, SLOT(getData()));
    QObject::connect(this->socket, SIGNAL(disconnected()), this, SLOT(onDisconnection()));
    QObject::connect(this->socket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(onError()));

}

void TCPClient::setup(QString IP, int port)
{
    this->wifibotIP = IP;
    this->wifibotPort = port;
    this->socket = new QTcpSocket();
}

void TCPClient::getData()
{
    //We the client receives data
    std::cout << "Ready to read !" << std::endl;
}

void TCPClient::connectToBot()
{
    if(!this->isConnected)
    {
        emit reportConnection("Status : Establishing connection");
        this->socket->connectToHost(this->wifibotIP, this->wifibotPort);
    }
}

void TCPClient::disconnectFromBot()
{
    if(this->isConnected)
    {
        emit reportConnection("Status : Disconnecting");
        this->socket->disconnectFromHost();
    }
}

void TCPClient::onDisconnection()
{
    std::cout << "Disconnected" << std::endl;
    this->isConnected = false;
    emit reportConnection("Status : disconnected");
}

void TCPClient::connectionEstablished()
{
    //After connection was established
    std::cout << "Connection successfully established" << std::endl;
    this->isConnected = true;
    emit reportConnection("Status : connected");
}

void TCPClient::onError()
{
    emit reportConnection("Status : Failed last action");
    Error *winError = new Error("Error. Either the IPv4 address is invalid or the device is unaivailable at the moment.");
    winError->exec();
    winError = NULL;
    free(winError);
}

void TCPClient::setNewIP(QString ip)
{
    this->wifibotIP=ip;
}
