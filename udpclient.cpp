#include "udpclient.h"
#include <QNetworkDatagram>

UDPClient::UDPClient(QString IP, int port)
{
    setup(IP, port);
    connect(udpsocket, SIGNAL(connected()), this, SLOT(connectionEstablished()));
    connect(udpsocket, SIGNAL(readyRead()), this, SLOT(readPendingDatagrams()) );
}

void UDPClient::setup(QString IP, int port)
{
    this->wifibotIP = IP;
    this->wifibotPort = port;

    udpsocket = new QUdpSocket();
    QHostAddress address = QHostAddress(this->wifibotIP);
    udpsocket->bind(address, this->wifibotPort);
}

void UDPClient::readPendingDatagrams(){
    while (udpsocket->hasPendingDatagrams()) {
        QNetworkDatagram datagram = udpsocket->receiveDatagram();
        processTheDatagram(datagram);
    }
}

void UDPClient::connectionEstablished(){
    qDebug()<<"connection udp sucessful";
}

void UDPClient::processTheDatagram(QNetworkDatagram datagram){
    //if (datagram){
        qDebug()<<"udp data";
    //}

}
