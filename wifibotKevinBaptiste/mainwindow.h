#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "tcpclient.h"
#include "udpclient.h"
#include "error.h"
#include "changeip.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void initSignals();
private slots:
    void pushAction();
    void changeConnectionStatus(QString status);
    void hello();


    void cameraConnection();
    void move_Rup();
    void move_Rback();
    void move_Rleft();
    void move_Rright();
    void move_Cup();
    void move_Cdown();
    void move_Cleft();
    void move_Cright();




private:
    Ui::MainWindow *ui;
    TCPClient *tcpclient;
    UDPClient *udpclient;
};

#endif // MAINWINDOW_H
