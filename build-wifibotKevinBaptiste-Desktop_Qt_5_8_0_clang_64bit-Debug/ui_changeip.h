/********************************************************************************
** Form generated from reading UI file 'changeip.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGEIP_H
#define UI_CHANGEIP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_changeIP
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QPlainTextEdit *case1;
    QPlainTextEdit *case2;
    QPlainTextEdit *case3;
    QPlainTextEdit *case4;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *buttonOK;
    QPushButton *buttonCancel;

    void setupUi(QDialog *changeIP)
    {
        if (changeIP->objectName().isEmpty())
            changeIP->setObjectName(QStringLiteral("changeIP"));
        changeIP->resize(493, 185);
        verticalLayoutWidget = new QWidget(changeIP);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 471, 171));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        case1 = new QPlainTextEdit(verticalLayoutWidget);
        case1->setObjectName(QStringLiteral("case1"));
        case1->setMaximumSize(QSize(50, 50));
        case1->setTabChangesFocus(true);
        case1->setTabStopWidth(3);

        horizontalLayout->addWidget(case1);

        case2 = new QPlainTextEdit(verticalLayoutWidget);
        case2->setObjectName(QStringLiteral("case2"));
        case2->setMaximumSize(QSize(50, 50));
        case2->setTabChangesFocus(true);
        case2->setTabStopWidth(3);

        horizontalLayout->addWidget(case2);

        case3 = new QPlainTextEdit(verticalLayoutWidget);
        case3->setObjectName(QStringLiteral("case3"));
        case3->setMaximumSize(QSize(50, 50));
        case3->setTabChangesFocus(true);
        case3->setTabStopWidth(3);

        horizontalLayout->addWidget(case3);

        case4 = new QPlainTextEdit(verticalLayoutWidget);
        case4->setObjectName(QStringLiteral("case4"));
        case4->setMaximumSize(QSize(50, 50));
        case4->setTabChangesFocus(true);
        case4->setTabStopWidth(3);
        case4->setMaximumBlockCount(3);

        horizontalLayout->addWidget(case4);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, 0, -1, -1);
        buttonOK = new QPushButton(verticalLayoutWidget);
        buttonOK->setObjectName(QStringLiteral("buttonOK"));

        horizontalLayout_2->addWidget(buttonOK);

        buttonCancel = new QPushButton(verticalLayoutWidget);
        buttonCancel->setObjectName(QStringLiteral("buttonCancel"));
        buttonCancel->setFocusPolicy(Qt::NoFocus);

        horizontalLayout_2->addWidget(buttonCancel);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(changeIP);

        QMetaObject::connectSlotsByName(changeIP);
    } // setupUi

    void retranslateUi(QDialog *changeIP)
    {
        changeIP->setWindowTitle(QApplication::translate("changeIP", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("changeIP", "Please input the IPv4 address of your WiFi Bot", Q_NULLPTR));
        case1->setPlainText(QApplication::translate("changeIP", "192", Q_NULLPTR));
        case2->setPlainText(QApplication::translate("changeIP", "168", Q_NULLPTR));
        case3->setPlainText(QApplication::translate("changeIP", "1", Q_NULLPTR));
        case4->setPlainText(QApplication::translate("changeIP", "106", Q_NULLPTR));
        buttonOK->setText(QApplication::translate("changeIP", "OK", Q_NULLPTR));
        buttonCancel->setText(QApplication::translate("changeIP", "Cancel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class changeIP: public Ui_changeIP {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGEIP_H
