#include <QUdpSocket>

#ifndef UDPCLIENT_H
#define UDPCLIENT_H


class UDPClient : public QObject
{
Q_OBJECT
public:
    UDPClient(QString IP="192.168.1.106", int port=8080);


    void processTheDatagram(QNetworkDatagram datagram);
    void connectToCam();
private:

    void setup(QString IP, int port);
    QString wifibotIP;
    int wifibotPort;
    QUdpSocket *udpsocket;

private slots:
    void connectionEstablished();
    void readPendingDatagrams();
};

#endif // UDPCLIENT_H
