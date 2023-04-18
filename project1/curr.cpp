#include "curr.h"
#include "ui_curr.h"

curr::curr(QDialog *sign,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::curr),
    sign(sign)
{
    ui->setupUi(this);
    setWindowTitle("DYAD Bank");
    setStyleSheet("background-color: transparent;");
    ui->sel->hide();
}

curr::~curr()
{
    delete ui;
}

void curr::on_exi_clicked()
{
    this->hide();
    sign->show();
}


void curr::on_pushButton_4_clicked()
{
    if(ui->sel->isVisible()){
        ui->sel->hide();
        ui->buy->show();
    } else {
    ui->buy->hide();
    ui->sel->show();
    }

}

