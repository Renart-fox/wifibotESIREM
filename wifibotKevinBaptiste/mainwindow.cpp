#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QKeyEvent>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    tcpclient = new TCPClient();
    camera = new TCPCam();

    QString robotConnectionData = tcpclient->getRobotIP() + ":" + QString::number(tcpclient->getRobotPort());
    ui->robotIPPort->setText(robotConnectionData);

    this->installEventFilter(this);

    initSignals();

    loadCam();
}

void MainWindow::initSignals()
{
    //connection robot
    connect(ui->connectionButton, SIGNAL (released()), this, SLOT (pushAction()));

    connect(this->tcpclient, SIGNAL(reportConnection(QString)), this, SLOT(changeConnectionStatus(QString)));

    connect(this->ui->actionChange_IPv4, SIGNAL(triggered(bool)), this, SLOT(showIPWindow()));


    //Direction robot
        connect(ui->button_up, SIGNAL (pressed()), this, SLOT (move_Rup()));
        connect(ui->button_up, SIGNAL(released()), this, SLOT (stop()));

        connect(ui->button_back, SIGNAL (pressed()), this, SLOT (move_Rback()));
        connect(ui->button_back, SIGNAL(released()), this, SLOT (stop()));

        connect(ui->button_right, SIGNAL (pressed()), this, SLOT (move_Rright()));
        connect(ui->button_right, SIGNAL(released()), this, SLOT (stop()));

        connect(ui->button_left, SIGNAL (pressed()), this, SLOT (move_Rleft()));
        connect(ui->button_left, SIGNAL(released()), this, SLOT (stop()));

        connect(ui->button_ul, SIGNAL (pressed()), this, SLOT (move_Rul()));
        connect(ui->button_ul, SIGNAL(released()), this, SLOT (stop()));

        connect(ui->button_ur, SIGNAL (pressed()), this, SLOT (move_Rur()));
        connect(ui->button_ur, SIGNAL(released()), this, SLOT (stop()));

        connect(ui->button_dl, SIGNAL (pressed()), this, SLOT (move_Rdl()));
        connect(ui->button_dl, SIGNAL(released()), this, SLOT (stop()));

        connect(ui->button_dr, SIGNAL (pressed()), this, SLOT (move_Rdr()));
        connect(ui->button_dr, SIGNAL(released()), this, SLOT (stop()));

     //Direction camera
        connect(ui->camera_up, SIGNAL (pressed()), this, SLOT (move_Cup()));
        ui->camera_up->setAutoRepeat(true);

        connect(ui->camera_down, SIGNAL (pressed()), this, SLOT (move_Cdown()));
        ui->camera_down->setAutoRepeat(true);

        connect(ui->camera_right, SIGNAL (pressed()), this, SLOT (move_Cright()));
        ui->camera_right->setAutoRepeat(true);

        connect(ui->camera_left, SIGNAL (pressed()), this, SLOT (move_Cleft()));
        ui->camera_left->setAutoRepeat(true);

        connect(ui->camera_resetH, SIGNAL (pressed()), this, SLOT (resetHor()));
        connect(ui->camera_resetV, SIGNAL (pressed()), this, SLOT (resetVer()));

        connect(this->tcpclient, SIGNAL (signalBat(int)), this, SLOT (setBat(int)));
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

void MainWindow::showIPWindow()
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

//action robot
void MainWindow::move_Rup()
{
   this->tcpclient->move('u', speed);
}

void MainWindow::move_Rback()
{
   this->tcpclient->move('d', speed);
}

void MainWindow::move_Rright()
{
   this->tcpclient->move('r', speed);
}

void MainWindow::move_Rleft()
{
   this->tcpclient->move('l', speed);
}

void MainWindow::move_Rul()
{
   this->tcpclient->move('g', speed);
}

void MainWindow::move_Rur()
{
   this->tcpclient->move('h', speed);
}

void MainWindow::move_Rdl()
{
   this->tcpclient->move('b', speed);
}

void MainWindow::move_Rdr()
{
   this->tcpclient->move('n', speed);
}
void MainWindow::stop()
{
    this->tcpclient->move('s', speed);
}

bool MainWindow::eventFilter(QObject *watched, QEvent *event)
{
    if(event->type()==QEvent::KeyPress)
    {
        pressedKey += ((QKeyEvent*)event)->key();
        if(pressedKey.contains(Qt::Key_Z) && pressedKey.contains(Qt::Key_Q))
        {
            move_Rul();
        }
        else if(pressedKey.contains(Qt::Key_Z) && pressedKey.contains(Qt::Key_D))
        {
            move_Rur();
        }
        else if(pressedKey.contains(Qt::Key_Z))
        {
            move_Rup();
        }
        else if(pressedKey.contains(Qt::Key_S) && pressedKey.contains(Qt::Key_Q))
        {
            move_Rdl();
        }
        else if(pressedKey.contains(Qt::Key_S) && pressedKey.contains(Qt::Key_D))
        {
            move_Rdr();
        }
        else if(pressedKey.contains(Qt::Key_S))
        {
            move_Rback();
        }
        else if(pressedKey.contains(Qt::Key_D))
        {
            move_Rright();
        }
        else if(pressedKey.contains(Qt::Key_Q))
        {
            move_Rleft();
        }
    }

    if(event->type()==QEvent::KeyRelease)
    {
        int releasedKey = ((QKeyEvent*)event)->key();
        if(releasedKey==Qt::Key_Z || releasedKey==Qt::Key_Q || releasedKey==Qt::Key_S || releasedKey==Qt::Key_D) stop();
        pressedKey -= ((QKeyEvent*)event)->key();
    }
}
//action camera

void MainWindow::move_Cup()
{
   camera->moveCam('u');
}

void MainWindow::move_Cdown()
{
   camera->moveCam('d');
}

void MainWindow::move_Cright()
{
   camera->moveCam('r');
}

void MainWindow::move_Cleft()
{
   camera->moveCam('l');
}

void MainWindow::resetHor()
{
    camera->moveCam('h');
}

void MainWindow::resetVer()
{
    camera->moveCam('v');
}

void MainWindow::loadCam()
{
    QWebEngineView* videoStream = new QWebEngineView();
    this->ui->videoContainer->addWidget(videoStream);

    videoStream->load(QUrl("http://"+this->tcpclient->getRobotIP()+":8080/?action=stream"));
    videoStream->show();
}

void MainWindow::setBat(int bat)
{
    /*QString str= QString::number(bat);
    ui->Bat->setText("Bat :" + str);*/
}

void MainWindow::on_horizontalSlider_sliderReleased()
{
    this->speed = this->ui->horizontalSlider->value();
    std::cout << speed << std::endl;
}
