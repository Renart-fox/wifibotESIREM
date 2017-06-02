#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QUrl>
#include <QWebEngineView>
#include "tcpcam.h"
#include "tcpclient.h"
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
    void showIPWindow();


    void move_Rup();
    void move_Rback();
    void move_Rleft();
    void move_Rright();
    void move_Rul();
    void move_Rur();
    void move_Rdl();
    void move_Rdr();
    void move_Cup();
    void move_Cdown();
    void move_Cleft();
    void move_Cright();
    void resetVer();
    void resetHor();
    void stop();



private:
    Ui::MainWindow *ui;
    TCPClient *tcpclient;
    TCPCam *camera;
    QSet<int> pressedKey;
    bool eventFilter(QObject *watched, QEvent *event);
};

#endif // MAINWINDOW_H
