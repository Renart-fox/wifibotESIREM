/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionChange_IPv4;
    QWidget *centralWidget;
    QLabel *robotIPPort;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *connectionButton;
    QLabel *connectionStatus;
    QPushButton *button_right;
    QPushButton *button_left;
    QPushButton *button_up;
    QPushButton *button_back;
    QLabel *label;
    QLabel *label_3;
    QPushButton *camera_up;
    QPushButton *camera_left;
    QPushButton *camera_right;
    QPushButton *camera_down;
    QPushButton *button_dr;
    QPushButton *button_ur;
    QPushButton *button_dl;
    QPushButton *button_ul;
    QFrame *gridFrame;
    QGridLayout *videoContainer;
    QPushButton *camera_resetH;
    QSlider *horizontalSlider;
    QLabel *label_2;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_3;
    QLabel *infG;
    QSpacerItem *horizontalSpacer;
    QLabel *infD;
    QSpacerItem *horizontalSpacer_2;
    QLabel *Bat;
    QProgressBar *progressBar;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_5;
    QCheckBox *blurBox;
    QCheckBox *negaBox;
    QHBoxLayout *horizontalLayout_6;
    QCheckBox *hueBox;
    QCheckBox *grayBox;
    QMenuBar *menuBar;
    QMenu *menuMenu;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(700, 405);
        MainWindow->setMinimumSize(QSize(700, 400));
        MainWindow->setMaximumSize(QSize(700, 500));
        MainWindow->setCursor(QCursor(Qt::UpArrowCursor));
        MainWindow->setContextMenuPolicy(Qt::NoContextMenu);
        actionChange_IPv4 = new QAction(MainWindow);
        actionChange_IPv4->setObjectName(QStringLiteral("actionChange_IPv4"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        robotIPPort = new QLabel(centralWidget);
        robotIPPort->setObjectName(QStringLiteral("robotIPPort"));
        robotIPPort->setGeometry(QRect(550, 20, 131, 20));
        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 10, 361, 41));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        connectionButton = new QPushButton(horizontalLayoutWidget);
        connectionButton->setObjectName(QStringLiteral("connectionButton"));

        horizontalLayout->addWidget(connectionButton);

        connectionStatus = new QLabel(horizontalLayoutWidget);
        connectionStatus->setObjectName(QStringLiteral("connectionStatus"));

        horizontalLayout->addWidget(connectionStatus);

        button_right = new QPushButton(centralWidget);
        button_right->setObjectName(QStringLiteral("button_right"));
        button_right->setGeometry(QRect(110, 120, 41, 32));
        button_left = new QPushButton(centralWidget);
        button_left->setObjectName(QStringLiteral("button_left"));
        button_left->setGeometry(QRect(30, 120, 41, 32));
        button_up = new QPushButton(centralWidget);
        button_up->setObjectName(QStringLiteral("button_up"));
        button_up->setGeometry(QRect(70, 90, 41, 32));
        button_back = new QPushButton(centralWidget);
        button_back->setObjectName(QStringLiteral("button_back"));
        button_back->setGeometry(QRect(70, 150, 41, 32));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 70, 91, 16));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(560, 60, 101, 20));
        camera_up = new QPushButton(centralWidget);
        camera_up->setObjectName(QStringLiteral("camera_up"));
        camera_up->setGeometry(QRect(580, 90, 41, 32));
        camera_left = new QPushButton(centralWidget);
        camera_left->setObjectName(QStringLiteral("camera_left"));
        camera_left->setGeometry(QRect(540, 120, 41, 32));
        camera_right = new QPushButton(centralWidget);
        camera_right->setObjectName(QStringLiteral("camera_right"));
        camera_right->setGeometry(QRect(620, 120, 41, 32));
        camera_down = new QPushButton(centralWidget);
        camera_down->setObjectName(QStringLiteral("camera_down"));
        camera_down->setGeometry(QRect(580, 150, 41, 32));
        button_dr = new QPushButton(centralWidget);
        button_dr->setObjectName(QStringLiteral("button_dr"));
        button_dr->setGeometry(QRect(110, 150, 41, 32));
        button_ur = new QPushButton(centralWidget);
        button_ur->setObjectName(QStringLiteral("button_ur"));
        button_ur->setGeometry(QRect(110, 90, 41, 32));
        button_dl = new QPushButton(centralWidget);
        button_dl->setObjectName(QStringLiteral("button_dl"));
        button_dl->setGeometry(QRect(30, 150, 41, 32));
        button_ul = new QPushButton(centralWidget);
        button_ul->setObjectName(QStringLiteral("button_ul"));
        button_ul->setGeometry(QRect(30, 90, 41, 32));
        gridFrame = new QFrame(centralWidget);
        gridFrame->setObjectName(QStringLiteral("gridFrame"));
        gridFrame->setGeometry(QRect(180, 60, 310, 240));
        gridFrame->setMinimumSize(QSize(310, 240));
        gridFrame->setMaximumSize(QSize(310, 240));
        videoContainer = new QGridLayout(gridFrame);
        videoContainer->setSpacing(6);
        videoContainer->setContentsMargins(11, 11, 11, 11);
        videoContainer->setObjectName(QStringLiteral("videoContainer"));
        camera_resetH = new QPushButton(centralWidget);
        camera_resetH->setObjectName(QStringLiteral("camera_resetH"));
        camera_resetH->setGeometry(QRect(550, 200, 101, 32));
        horizontalSlider = new QSlider(centralWidget);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(10, 220, 160, 22));
        horizontalSlider->setMinimum(70);
        horizontalSlider->setMaximum(100);
        horizontalSlider->setOrientation(Qt::Horizontal);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 200, 91, 20));
        horizontalLayoutWidget_2 = new QWidget(centralWidget);
        horizontalLayoutWidget_2->setObjectName(QStringLiteral("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(0, 340, 691, 24));
        horizontalLayout_4 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_3 = new QSpacerItem(10, 10, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        infG = new QLabel(horizontalLayoutWidget_2);
        infG->setObjectName(QStringLiteral("infG"));

        horizontalLayout_4->addWidget(infG);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        infD = new QLabel(horizontalLayoutWidget_2);
        infD->setObjectName(QStringLiteral("infD"));

        horizontalLayout_4->addWidget(infD);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        Bat = new QLabel(horizontalLayoutWidget_2);
        Bat->setObjectName(QStringLiteral("Bat"));

        horizontalLayout_4->addWidget(Bat);

        progressBar = new QProgressBar(horizontalLayoutWidget_2);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(24);

        horizontalLayout_4->addWidget(progressBar);

        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(510, 240, 199, 80));
        verticalLayout_4 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        blurBox = new QCheckBox(verticalLayoutWidget);
        blurBox->setObjectName(QStringLiteral("blurBox"));

        horizontalLayout_5->addWidget(blurBox);

        negaBox = new QCheckBox(verticalLayoutWidget);
        negaBox->setObjectName(QStringLiteral("negaBox"));

        horizontalLayout_5->addWidget(negaBox);


        verticalLayout_4->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        hueBox = new QCheckBox(verticalLayoutWidget);
        hueBox->setObjectName(QStringLiteral("hueBox"));

        horizontalLayout_6->addWidget(hueBox);

        grayBox = new QCheckBox(verticalLayoutWidget);
        grayBox->setObjectName(QStringLiteral("grayBox"));

        horizontalLayout_6->addWidget(grayBox);


        verticalLayout_4->addLayout(horizontalLayout_6);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 700, 22));
        menuMenu = new QMenu(menuBar);
        menuMenu->setObjectName(QStringLiteral("menuMenu"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);

        menuBar->addAction(menuMenu->menuAction());
        menuMenu->addAction(actionChange_IPv4);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "WiFi Bot", Q_NULLPTR));
        actionChange_IPv4->setText(QApplication::translate("MainWindow", "Change IPv4...", Q_NULLPTR));
        robotIPPort->setText(QApplication::translate("MainWindow", "robotIPPort", Q_NULLPTR));
        connectionButton->setText(QApplication::translate("MainWindow", "Connect to bot", Q_NULLPTR));
        connectionStatus->setText(QApplication::translate("MainWindow", "Status : disconnected", Q_NULLPTR));
        button_right->setText(QApplication::translate("MainWindow", "\342\206\222", Q_NULLPTR));
        button_left->setText(QApplication::translate("MainWindow", "\342\206\220", Q_NULLPTR));
        button_up->setText(QApplication::translate("MainWindow", "\342\206\221", Q_NULLPTR));
        button_back->setText(QApplication::translate("MainWindow", "\342\206\223", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Piloter robot", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Piloter camera", Q_NULLPTR));
        camera_up->setText(QApplication::translate("MainWindow", "up", Q_NULLPTR));
        camera_left->setText(QApplication::translate("MainWindow", "left", Q_NULLPTR));
        camera_right->setText(QApplication::translate("MainWindow", "right", Q_NULLPTR));
        camera_down->setText(QApplication::translate("MainWindow", "down", Q_NULLPTR));
        button_dr->setText(QApplication::translate("MainWindow", "\342\206\230", Q_NULLPTR));
        button_ur->setText(QApplication::translate("MainWindow", "\342\206\227", Q_NULLPTR));
        button_dl->setText(QApplication::translate("MainWindow", "\342\206\231", Q_NULLPTR));
        button_ul->setText(QApplication::translate("MainWindow", "\342\206\226", Q_NULLPTR));
        camera_resetH->setText(QApplication::translate("MainWindow", "Reset cam", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "SPEED (1-100)", Q_NULLPTR));
        infG->setText(QApplication::translate("MainWindow", "Infra G", Q_NULLPTR));
        infD->setText(QApplication::translate("MainWindow", "Infra D", Q_NULLPTR));
        Bat->setText(QApplication::translate("MainWindow", "Battery", Q_NULLPTR));
        blurBox->setText(QApplication::translate("MainWindow", "Blur", Q_NULLPTR));
        negaBox->setText(QApplication::translate("MainWindow", "Nega", Q_NULLPTR));
        hueBox->setText(QApplication::translate("MainWindow", "Hue", Q_NULLPTR));
        grayBox->setText(QApplication::translate("MainWindow", "Gray", Q_NULLPTR));
        menuMenu->setTitle(QApplication::translate("MainWindow", "Menu", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
