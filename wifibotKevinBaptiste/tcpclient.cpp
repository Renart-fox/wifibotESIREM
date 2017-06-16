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
    int readableData[168];
    for(int i = 0 ; i<data.count(); i++)
    {
        char b = data.at(i);

        for(int j=7; j>=0; j--)
        {
            readableData[7-j+i*8] = ((b >> j) & 1) ? 1 : 0;
            //std::cout << readableData[7-j+i*8];
        }
    }
    //std::cout << std::endl;

    int toDec = 0;
    int frame[20];
    for(int i=0; i<168; i+=8)
    {
        for(int j=0; j<8; j++)
        {
            toDec += readableData[i+j] * pow(2, 7-j);
        }
        frame[i/8] = toDec;
        //std::cout << frame[i/8] << " ";
        toDec = 0;
    }
    //std::cout << std::endl;
    emit signalBat(frame[2]);
    emit signalInfAG(frame[3]);
    emit signalInfAD(frame[11]);
    if(frame[3] >= 140 || frame[11] >= 140)
    {
        if(!bloque)
        {
            move('s',0);
            esquive();
            bloque = true;
            std::cout << "stop" << std::endl;
        }
    }
    else
    {
        if(bloque)
        {
            move('s',0);
            bloque = false;
            std::cout << "arret bloquage" << std::endl;
        }
    }
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
    timer->start(1000);
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
    QByteArray data;
    data.append(255);

    this->socket->write(data);
}

void TCPClient::move(char dir, int vitesse)
{
    if(this->isConnected)
    {
        if((dir != lastDirection && !bloque ) || (dir=='s'))
        {
            lastDirection = dir;

            QByteArray data;
            data.append(255);
            data.append(0x07);
            switch(dir)
            {
                case 'u': data.append((char)((int)(240*vitesse)/100));
                        data.append((char)0x00);
                        data.append((char)((int)(240*vitesse)/100));
                        data.append((char)0x00);
                        data.append((char)0x50);
                    break;
                case 'd': data.append((char)((int)(240*vitesse)/100));
                        data.append((char)0x00);
                        data.append((char)((int)(240*vitesse)/100));
                        data.append((char)0x00);
                        data.append((char)0x10);
                    break;
                case 'l': data.append((char)((int)(96*vitesse)/100));
                        data.append((char)0x00);
                        data.append((char)((int)(240*vitesse)/100));
                        data.append((char)0x00);
                        data.append((char)0x50);
                    break;
                case 'r': data.append((char)((int)(240*vitesse)/100));
                        data.append((char)0x00);
                        data.append((char)((int)(150*vitesse)/100));
                        data.append((char)0x00);
                        data.append((char)0x50);
                    break;
                case 'g': data.append((char)0x78);
                        data.append((char)0x00);
                        data.append((char)((int)(240*vitesse)/100));
                        data.append((char)0x00);
                        data.append((char)0x50);
                    break;
                case 'h': data.append((char)((int)(240*vitesse)/100));
                        data.append((char)0x00);
                        data.append(0x78);
                        data.append((char)0x00);
                        data.append((char)0x50);
                    break;
                case 'b': data.append(0x78);
                        data.append((char)0x00);
                        data.append((char)((int)(240*vitesse)/100));
                        data.append((char)0x00);
                        data.append((char)0x00);
                    break;
                case 'n': data.append((char)((int)(240*vitesse)/100));
                        data.append((char)0x00);
                        data.append(0x78);
                        data.append((char)0x00);
                        data.append((char)0x00);
                    break;
                case 's': data.append((char)0x00);
                data.append((char)0x00);
                data.append((char)0x00);
                data.append((char)0x00);
                data.append((char)0x50);
                    break;
            default:
                Error *e = new Error("Unrecognized direction ? Please contact the development team.");
                e->exec();
                e=NULL;
                free(e);
            }
            qint16 crc = NETWORKINGOPT::crc16(data);
            data.append((char)crc);
            data.append((char)(crc >> 8));

            this->socket->write(data);
        }
    }
    else
    {
        Error* e = new Error("Tried to move when robot is not connected.");
        e->exec();
        e=NULL;
        free(e);
    }

}

void TCPClient::setNewIP(QString ip)
{
    this->wifibotIP=ip;
}

void TCPClient::esquive()
{
        QByteArray data;
        data.append(255);
        data.append(0x07);
        data.append((char)0xf0);
        data.append((char)0x00);
        data.append((char)0xf0);
        data.append((char)0x00);
        data.append((char)0x10);
        qint16 crc = NETWORKINGOPT::crc16(data);
        data.append((char)crc);
        data.append((char)(crc >> 8));

        this->socket->write(data);
}
