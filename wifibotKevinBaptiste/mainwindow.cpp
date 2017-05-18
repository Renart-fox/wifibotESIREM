#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    tcpclient = new TCPClient();
    QString robotConnectionData = tcpclient->getRobotIP() + ":" + QString::number(tcpclient->getRobotPort());
    ui->robotIPPort->setText(robotConnectionData);

    initSignals();
}

void MainWindow::initSignals()
{
    connect(ui->connectionButton, SIGNAL (released()), this, SLOT (pushAction()));
    connect(ui->camera_button, SIGNAL (released()), this, SLOT (cameraAction()));

    connect(this->tcpclient, SIGNAL(reportConnection(QString)), this, SLOT(changeConnectionStatus(QString)));

    connect(this->ui->actionChange_IPv4, SIGNAL(triggered(bool)), this, SLOT(hello()));

    //changement de direction
        connect(ui->button_up, SIGNAL (pressed()), this, SLOT (mouve_up()));
        ui->button_up->setAutoRepeat(true);

        connect(ui->button_back, SIGNAL (pressed()), this, SLOT (mouve_back()));
        ui->button_back->setAutoRepeat(true);

        connect(ui->button_right, SIGNAL (pressed()), this, SLOT (mouve_right()));
        ui->button_right->setAutoRepeat(true);

        connect(ui->button_left, SIGNAL (pressed()), this, SLOT (mouve_left()));
        ui->button_left->setAutoRepeat(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::pushAction()
{
    if(this->tcpclient->getConnectionStatus())
    {
        tcpclient->disconnectFromBot();
    }
    else
    {
        tcpclient->connectToBot();
        ui->actionChange_IPv4->setEnabled(false);
    }
}

void MainWindow::changeConnectionStatus(QString status)
{
    this->ui->connectionStatus->setText(status);
    if(!this->tcpclient->getConnectionStatus())
    {
        ui->connectionButton->setText("Connect to bot");
        ui->actionChange_IPv4->setEnabled(true);
    }
    else
    {
        ui->connectionButton->setText("Disconnect from bot");
        ui->actionChange_IPv4->setEnabled(false);
    }
}

void MainWindow::hello()
{
    changeIP* ip = new changeIP(this);
    int accepted = ip->exec();
    if(accepted == QDialog::Accepted)
    {
        this->tcpclient->setNewIP(ip->getNewIP());
        QString robotConnectionData = tcpclient->getRobotIP() + ":" + QString::number(tcpclient->getRobotPort());
        ui->robotIPPort->setText(robotConnectionData);
    }
    ip = NULL;
    free(ip);
}


void MainWindow::cameraAction()
{
    qDebug()<<"start cam";
}


void MainWindow::mouve_up()
{
   qDebug() << "up pressed";
}

void MainWindow::mouve_back()
{
   qDebug() << "back pressed";
}

void MainWindow::mouve_right()
{
   qDebug() << "right pressed";
}

void MainWindow::mouve_left()
{
   qDebug() << "left pressed";
}
