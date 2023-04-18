#include "credit.h"
#include "ui_credit.h"

credit::credit(QDialog *sign,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::credit),
    sign(sign)
{
    ui->setupUi(this);
    setWindowTitle("DYAD Bank");
    setStyleSheet("background-color: transparent;");
    ui->lineEdit->setStyleSheet("background-color: #2E2E2E;");
    ui->lineEdit_2->setStyleSheet("background-color: #2E2E2E;");
    ui->lineEdit_3->setStyleSheet("background-color: #2E2E2E;");
}

credit::~credit()
{
    delete ui;
}

void credit::on_pushButton_clicked()
{
    this->hide();
    sign->show();
}

