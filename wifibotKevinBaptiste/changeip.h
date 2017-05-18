#ifndef CHANGEIP_H
#define CHANGEIP_H

#include <QDialog>

namespace Ui {
class changeIP;
}

class changeIP : public QDialog
{
    Q_OBJECT

public:
    explicit changeIP(QWidget *parent = 0);
    ~changeIP();
    QString getNewIP(){
        return this->newIP;
    }

private:
    Ui::changeIP *ui;
    QString newIP;
private slots:
    void checkText();
    void buttonOK_clicked();
    void buttonCancel_clicked();
};

#endif // CHANGEIP_H
