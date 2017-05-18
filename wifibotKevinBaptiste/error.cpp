#include "error.h"
#include "ui_error.h"

Error::Error(QString message, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Error)
{
    ui->setupUi(this);
    ui->errorMessage->setText(message);
}

Error::~Error()
{
    delete ui;
}

void Error::on_closeButton_clicked()
{
    this->close();
}
