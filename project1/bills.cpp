#include "bills.h"
#include "ui_bills.h"

bills::bills(QDialog *sign,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::bills),
    sign(sign)
{
    ui->setupUi(this);
    setWindowTitle("DYAD Bank");
    setStyleSheet("background-color: transparent;");
}

bills::~bills()
{
    delete ui;
}

void bills::on_pushButton_clicked()
{
    this->hide();
    sign->show();
}

