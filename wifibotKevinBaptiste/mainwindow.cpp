#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QKeyEvent>

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

    this->installEventFilter(this);

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


    //changement de direction
        connect(ui->button_up, SIGNAL (pressed()), this, SLOT (move_Rup()));
        connect(ui->button_up, SIGNAL(released()), this, SLOT (stop()));

        connect(ui->button_back, SIGNAL (pressed()), this, SLOT (move_Rback()));
        connect(ui->button_back, SIGNAL(released()), this, SLOT (stop()));

        connect(ui->button_right, SIGNAL (pressed()), this, SLOT (move_Rright()));
        connect(ui->button_right, SIGNAL(released()), this, SLOT (stop()));

        connect(ui->button_left, SIGNAL (pressed()), this, SLOT (move_Rleft()));
        connect(ui->button_left, SIGNAL(released()), this, SLOT (stop()));

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
   this->tcpclient->move('u');
}

void MainWindow::move_Rback()
{
   this->tcpclient->move('d');
}

void MainWindow::move_Rright()
{
   this->tcpclient->move('r');
}

void MainWindow::move_Rleft()
{
   this->tcpclient->move('l');
}

void MainWindow::stop()
{
    this->tcpclient->move('s');
}

bool MainWindow::eventFilter(QObject *watched, QEvent *event)
{
    if(event->type()==QEvent::KeyPress)
    {
        pressedKey += ((QKeyEvent*)event)->key();
        if(pressedKey.contains(Qt::Key_Z) && pressedKey.contains(Qt::Key_Q))
        {
            this->tcpclient->move('g');
        }
        else if(pressedKey.contains(Qt::Key_Z) && pressedKey.contains(Qt::Key_D))
        {
            this->tcpclient->move('h');
        }
        else if(pressedKey.contains(Qt::Key_Z))
        {
            this->tcpclient->move('u');
        }
        else if(pressedKey.contains(Qt::Key_S) && pressedKey.contains(Qt::Key_Q))
        {
            this->tcpclient->move('b');
        }
        else if(pressedKey.contains(Qt::Key_S) && pressedKey.contains(Qt::Key_D))
        {
            this->tcpclient->move('n');
        }
        else if(pressedKey.contains(Qt::Key_S))
        {
            this->tcpclient->move('d');
        }
        else if(pressedKey.contains(Qt::Key_D))
        {
            this->tcpclient->move('r');
        }
        else if(pressedKey.contains(Qt::Key_Q))
        {
            this->tcpclient->move('l');
        }
    }

    if(event->type()==QEvent::KeyRelease)
    {
        pressedKey -= ((QKeyEvent*)event)->key();
        stop();
    }
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
