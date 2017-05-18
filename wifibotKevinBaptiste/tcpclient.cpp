#include "tcpclient.h"
#include <unistd.h>
#include <math.h>

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
    char readableData[168];
    for(int i = 0 ; i<data.count(); i++)
    {
        char b = data.at(i);

        for(int j=7; j>=0; j--)
        {
            readableData[7-j+i*8] = ((b >> j) & 1) ? '1' : '0';
            std::cout << readableData[7-j+i*8];
        }
    }
    std::cout << std::endl;
    for(int i=0; i<168; i+=8)
    {
        // We assume that the maximum battery the bot can have is set to 183
        int toDecimal = 0;
        for(int k=7; k>=0; k--)
        {
            toDecimal += (readableData[i+k]-'0')*pow(2,k);
        }
        std::cout << toDecimal << " ";
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

    char init[4] = {'i','n','i','t'};
    this->socket->write(init, 4*sizeof(char));

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
    char refresh[4] = {'d','a','t','a'};
    this->socket->write(refresh, 4*sizeof(char));
}

void TCPClient::setNewIP(QString ip)
{
    this->wifibotIP=ip;
}
