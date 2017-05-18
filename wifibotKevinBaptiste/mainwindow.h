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



    void mouve_up();
    void mouve_down();
    void mouve_left();
    void mouve_right();



private:
    Ui::MainWindow *ui;
    TCPClient *tcpclient;
    UDPClient *udpclient;
};

#endif // MAINWINDOW_H
