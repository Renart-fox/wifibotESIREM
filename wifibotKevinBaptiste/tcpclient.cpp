#include "tcpclient.h"

TCPClient::TCPClient(QString IP, int port)
{
    setup(IP, port);
    QObject::connect(this->socket, SIGNAL(connected()), this, SLOT(connectionEstablished()));
    QObject::connect(this->socket, SIGNAL(readyRead()), this, SLOT(getData()));
    QObject::connect(this->socket, SIGNAL(disconnected()), this, SLOT(onDisconnection()));

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
        this->isConnected = true;
        this->socket->connectToHost(this->wifibotIP, this->wifibotPort);
    }
}

void TCPClient::disconnectFromBot()
{
    if(this->isConnected)
    {
        this->isConnected = false;
        this->socket->disconnectFromHost();
    }
}

void TCPClient::onDisconnection()
{
    std::cout << "Disconnected" << std::endl;
    emit reportConnection("Status : disconnected");
}

void TCPClient::connectionEstablished()
{
    //After connection was established
    std::cout << "Connection successfully established" << std::endl;
    emit reportConnection("Status : connected");
}
