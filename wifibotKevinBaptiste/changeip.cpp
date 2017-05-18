#include "changeip.h"
#include "ui_changeip.h"

changeIP::changeIP(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::changeIP)
{
    ui->setupUi(this);

    QObject::connect(ui->case4, SIGNAL(textChanged()), this, SLOT(checkText()));
    QObject::connect(ui->case2, SIGNAL(textChanged()), this, SLOT(checkText()));
    QObject::connect(ui->case1, SIGNAL(textChanged()), this, SLOT(checkText()));
    QObject::connect(ui->case3, SIGNAL(textChanged()), this, SLOT(checkText()));
    QObject::connect(ui->buttonCancel, SIGNAL(clicked(bool)), this, SLOT(buttonCancel_clicked()));
    QObject::connect(ui->buttonOK, SIGNAL(clicked(bool)), this, SLOT(buttonOK_clicked()));
}

changeIP::~changeIP()
{
    delete ui;
}

void changeIP::checkText()
{
    if(ui->case4->toPlainText().size()>3)
    {
        QString newText = ui->case4->toPlainText().at(0);
        newText += ui->case4->toPlainText().at(1);
        newText += ui->case4->toPlainText().at(2);
        ui->case4->document()->setPlainText(newText);
    }
    if(ui->case2->toPlainText().size()>3)
    {
        QString newText = ui->case2->toPlainText().at(0);
        newText += ui->case2->toPlainText().at(1);
        newText += ui->case2->toPlainText().at(2);
        ui->case2->document()->setPlainText(newText);
    }
    if(ui->case1->toPlainText().size()>3)
    {
        QString newText = ui->case1->toPlainText().at(0);
        newText += ui->case1->toPlainText().at(1);
        newText += ui->case1->toPlainText().at(2);
        ui->case1->document()->setPlainText(newText);
    }
    if(ui->case3->toPlainText().size()>3)
    {
        QString newText = ui->case3->toPlainText().at(0);
        newText += ui->case3->toPlainText().at(1);
        newText += ui->case3->toPlainText().at(2);
        ui->case3->document()->setPlainText(newText);
    }
    if(ui->case1->toPlainText().size()==0)
    {
        ui->case1->document()->setPlainText("0");
    }
    if(ui->case2->toPlainText().size()==0)
    {
        ui->case2->document()->setPlainText("0");
    }
    if(ui->case3->toPlainText().size()==0)
    {
        ui->case3->document()->setPlainText("0");
    }
    if(ui->case4->toPlainText().size()==0)
    {
        ui->case4->document()->setPlainText("0");
    }
}

void changeIP::buttonOK_clicked()
{
    this->newIP = ui->case1->toPlainText();
    this->newIP +=".";
    this->newIP += ui->case2->toPlainText();
    this->newIP +=".";
    this->newIP += ui->case3->toPlainText();
    this->newIP +=".";
    this->newIP += ui->case4->toPlainText();
    this->done(QDialog::Accepted);
}

void changeIP::buttonCancel_clicked()
{
    this->done(QDialog::Rejected);
}
