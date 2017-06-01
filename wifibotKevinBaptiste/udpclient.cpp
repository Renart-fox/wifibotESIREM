#include "udpclient.h"
#include <QNetworkDatagram>

UDPClient::UDPClient(QString IP, int port)
{
    setup(IP, port);
    connect(udpsocket, SIGNAL(hostFound()), this, SLOT(connectionEstablished()));
    connect(udpsocket, SIGNAL(wconnected()), this, SLOT(connectionEstablished()));
    connect(udpsocket, SIGNAL(readyRead()), this, SLOT(readPendingDatagrams()));
}

void UDPClient::setup(QString IP, int port)
{
    this->wifibotIP = IP;
    this->wifibotPort = port;
    udpsocket = new QUdpSocket();

}

void UDPClient::connectToCam()
{
    QHostAddress address = QHostAddress(this->wifibotIP);
    udpsocket->connectToHost(this->wifibotIP, this->wifibotPort);
    if (udpsocket->waitForConnected(1000))
        qDebug("Connected!");
}

void UDPClient::readPendingDatagrams(){
    qDebug()<<"lecture";
    QByteArray Buffer;
    Buffer.resize(udpsocket->pendingDatagramSize());

}

void UDPClient::connectionEstablished(){
    qDebug()<<"connection udp sucessful";
}

void UDPClient::processTheDatagram(QNetworkDatagram datagram){
    //if (datagram){
        qDebug()<<"udp data";
    //}

}
