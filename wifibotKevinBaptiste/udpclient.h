#include <QUdpSocket>

#ifndef UDPCLIENT_H
#define UDPCLIENT_H


class UDPClient : public QObject
{
Q_OBJECT
public:
    UDPClient();
private:
    QUdpSocket *socket;
};

#endif // UDPCLIENT_H
