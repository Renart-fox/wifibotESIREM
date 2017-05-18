#include "tcpclient.h"
#include <unistd.h>

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
    QByteArray data = this->socket->readAll();
    std::cout << "data found" << std::endl;
    for(int i = 0 ; i<=data.size()-1; i++)
    {
        char b = data.at(i);
        for(int j=7; j>=0; --j)
        {
            std::cout << ((b >> j) & 1);
        }
    }
    std::cout << std::endl;
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
    timer->stop();
}

void TCPClient::connectionEstablished()
{
    //After connection was established
    std::cout << "Connection successfully established" << std::endl;
    this->isConnected = true;
    emit reportConnection("Status : connected");
    this->timer = new QTimer(this);
    connect(this->timer, SIGNAL(timeout()), this, SLOT(synchroniseBot()));
    timer->setSingleShot(false);
    timer->start(500);
}

void TCPClient::onError()
{
    emit reportConnection("Status : Error");
    Error *winError = new Error(this->socket->errorString());
    winError->exec();
    winError = NULL;
    free(winError);
}

void TCPClient::synchroniseBot()
{
    // Refreshes the connection with an empty frame
    int i = 255;
    this->socket->write((const char*) &i, sizeof(i));
}

void TCPClient::setNewIP(QString ip)
{
    this->wifibotIP=ip;
}
