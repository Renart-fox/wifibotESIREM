#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "tcpclient.h"

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
private:
    Ui::MainWindow *ui;
    TCPClient *client;
    bool isConnected = false;
};

#endif // MAINWINDOW_H
