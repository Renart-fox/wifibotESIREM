#include "tcpCam.h"
#include <unistd.h>
#include <math.h>

TCPCam::TCPCam(QString IP, int port)
{
    setupCam(IP, port);
}

void TCPCam::setupCam(QString IP, int port)
{
    this->wifibotIP = IP;
    this->wifibotPort = port;

}

void TCPCam::moveCam(char dirCam)
{

    QNetworkRequest query;
    QUrl url;
    QNetworkAccessManager *manager = new QNetworkAccessManager();

        switch(dirCam)
        {
            case 'u':
                url = QUrl("http://192.168.1.106:8080/?action=command&dest=0&plugin=0&id=10094853&group=1&value=-200"); //On récupère l'URL entrée par l'utilisateur.
                query.setUrl(url);
                manager->get(query);
                break;
            case 'd':
                url = QUrl("http://192.168.1.106:8080/?action=command&dest=0&plugin=0&id=10094853&group=1&value=200"); //On récupère l'URL entrée par l'utilisateur.
                query.setUrl(url);
                manager->get(query);
                break;
            case 'r':
                url = QUrl("http://192.168.1.106:8080/?action=command&dest=0&plugin=0&id=10094852&group=1&value=-200"); //On récupère l'URL entrée par l'utilisateur.
                query.setUrl(url);
                manager->get(query);
                break;
            case 'l':
                url = QUrl("http://192.168.1.106:8080/?action=command&dest=0&plugin=0&id=10094852&group=1&value=200"); //On récupère l'URL entrée par l'utilisateur.
                query.setUrl(url);
                manager->get(query);
                break;
            case 'h':
                url = QUrl("http://192.168.1.106:8080/?action=command&dest=0&plugin=0&id=10094854&group=1&value=1"); //On récupère l'URL entrée par l'utilisateur.
                query.setUrl(url);
                manager->get(query);
                break;
            case 'v':
                url = QUrl("http://192.168.1.106:8080/?action=command&dest=0&plugin=0&id=10094855&group=1&value=1"); //On récupère l'URL entrée par l'utilisateur.
                query.setUrl(url);
                manager->get(query);
                break;
    }
}

