#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    tcpclient = new TCPClient();
    //initialisation udp
    udpclient = new UDPClient();
    QString robotConnectionData = tcpclient->getRobotIP() + ":" + QString::number(tcpclient->getRobotPort());
    ui->robotIPPort->setText(robotConnectionData);

    initSignals();
}

void MainWindow::initSignals()
{
    //connection robot
    connect(ui->connectionButton, SIGNAL (released()), this, SLOT (pushAction()));
    //connection cam
    connect(ui->camera_button, SIGNAL (released()), this, SLOT (cameraConnection()));

    connect(this->tcpclient, SIGNAL(reportConnection(QString)), this, SLOT(changeConnectionStatus(QString)));

    connect(this->ui->actionChange_IPv4, SIGNAL(triggered(bool)), this, SLOT(hello()));

    //changement de direction du robot
        connect(ui->button_up, SIGNAL (pressed()), this, SLOT (move_Rup()));
        ui->button_up->setAutoRepeat(true);

        connect(ui->button_back, SIGNAL (pressed()), this, SLOT (move_Rback()));
        ui->button_back->setAutoRepeat(true);

        connect(ui->button_right, SIGNAL (pressed()), this, SLOT (move_Rright()));
        ui->button_right->setAutoRepeat(true);

        connect(ui->button_left, SIGNAL (pressed()), this, SLOT (move_Rleft()));
        ui->button_left->setAutoRepeat(true);
    //changement de direction de la camera
        connect(ui->camera_up, SIGNAL (pressed()), this, SLOT (move_Cup()));
        ui->camera_up->setAutoRepeat(true);

        connect(ui->camera_down, SIGNAL (pressed()), this, SLOT (move_Cdown()));
        ui->camera_down->setAutoRepeat(true);

        connect(ui->camera_right, SIGNAL (pressed()), this, SLOT (move_Cright()));
        ui->camera_right->setAutoRepeat(true);

        connect(ui->camera_left, SIGNAL (pressed()), this, SLOT (move_Cleft()));
        ui->camera_left->setAutoRepeat(true);

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


void MainWindow::cameraConnection()
{
    qDebug()<<"start cam";

    udpclient->connectToCam();

}

//action robot
void MainWindow::move_Rup()
{
   qDebug() << "up pressed";
}

void MainWindow::move_Rback()
{
   qDebug() << "back pressed";
}

void MainWindow::move_Rright()
{
   qDebug() << "right pressed";
}

void MainWindow::move_Rleft()
{
   qDebug() << "left pressed";
}
//action camera

void MainWindow::move_Cup()
{
   qDebug() << "Camera up";
}

void MainWindow::move_Cdown()
{
   qDebug() << "Camera down";
}

void MainWindow::move_Cright()
{
   qDebug() << "Camera right";
}

void MainWindow::move_Cleft()
{
   qDebug() << "Camera left";
}
