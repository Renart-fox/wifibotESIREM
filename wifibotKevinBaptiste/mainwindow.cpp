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


    connect(ui->up, SIGNAL (pressed()), this, SLOT (mouve_up()));
    ui->up->setAutoRepeat(true);

    connect(ui->up, SIGNAL (pressed()), this, SLOT (mouve_down()));
    ui->up->setAutoRepeat(true);

    connect(ui->up, SIGNAL (pressed()), this, SLOT (mouve_up()));
    ui->up->setAutoRepeat(true);

    connect(ui->up, SIGNAL (pressed()), this, SLOT (mouve_up()));
    ui->up->setAutoRepeat(true);
    initSignals();
}

void MainWindow::initSignals()
{
    connect(ui->connectionButton, SIGNAL (released()), this, SLOT (pushAction()));
    connect(this->tcpclient, SIGNAL(reportConnection(QString)), this, SLOT(changeConnectionStatus(QString)));
    connect(this->ui->actionChange_IPv4, SIGNAL(triggered(bool)), this, SLOT(hello()));
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





void MainWindow::mouve_up()
{
   qDebug() << "up pressed";
}
