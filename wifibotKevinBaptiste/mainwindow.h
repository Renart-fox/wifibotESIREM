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
    void setInfAD(int infAD);
    void setInfAG(int infAG);

    void loadCam();
    void setBat(int bat);

    void on_horizontalSlider_sliderReleased();

    void on_blurBox_stateChanged(int arg1);

    void on_negaBox_stateChanged(int arg1);

    void on_hueBox_stateChanged(int arg1);

    void on_grayBox_stateChanged(int arg1);

private:
    Ui::MainWindow *ui;
    TCPClient *tcpclient;
    TCPCam *camera;
    QSet<int> pressedKey;
    bool eventFilter(QObject *watched, QEvent *event);
    int speed = 70;
    QWebEngineView* videoStream;
    bool isBlurred = false;
    bool isNega = false;
    bool isInverted = false;
    bool isGray = false;

    QString getCurrentFilters();
};

#endif // MAINWINDOW_H
