/********************************************************************************
** Form generated from reading UI file 'error.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ERROR_H
#define UI_ERROR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Error
{
public:
    QPushButton *closeButton;
    QLabel *errorMessage;

    void setupUi(QDialog *Error)
    {
        if (Error->objectName().isEmpty())
            Error->setObjectName(QStringLiteral("Error"));
        Error->setWindowModality(Qt::WindowModal);
        Error->resize(240, 85);
        Error->setModal(true);
        closeButton = new QPushButton(Error);
        closeButton->setObjectName(QStringLiteral("closeButton"));
        closeButton->setGeometry(QRect(160, 60, 75, 23));
        errorMessage = new QLabel(Error);
        errorMessage->setObjectName(QStringLiteral("errorMessage"));
        errorMessage->setGeometry(QRect(10, 10, 221, 41));
        errorMessage->setLayoutDirection(Qt::LeftToRight);
        errorMessage->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        errorMessage->setWordWrap(true);

        retranslateUi(Error);

        QMetaObject::connectSlotsByName(Error);
    } // setupUi

    void retranslateUi(QDialog *Error)
    {
        Error->setWindowTitle(QApplication::translate("Error", "Error !", Q_NULLPTR));
        closeButton->setText(QApplication::translate("Error", "OK", Q_NULLPTR));
        errorMessage->setText(QApplication::translate("Error", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Error: public Ui_Error {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ERROR_H
