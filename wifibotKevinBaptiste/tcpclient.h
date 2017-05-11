#include <QTcpSocket>
#include <iostream>

#ifndef TCPCLIENT_H
#define TCPCLIENT_H


class TCPClient : public QObject
{
Q_OBJECT
public:
    TCPClient(QString IP="192.168.1.106", int port=8080);
    int getRobotPort(){
        return this->wifibotPort;
    }
    QString getRobotIP(){
        return this->wifibotIP;
    }
    void connectToBot();
    void disconnectFromBot();
signals:
    void reportConnection(QString status);
private:
    void setup(QString IP, int port);

    QString wifibotIP;
    int wifibotPort;
    QTcpSocket *socket;
    bool isConnected = false;
private slots:
    void connectionEstablished();
    void getData();
    void onDisconnection();
};

#endif // TCPCLIENT_H
