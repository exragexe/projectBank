#include "sign.h"
#include "ui_sign.h"


sign::sign(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sign)
{


    ui->setupUi(this);
    setWindowTitle("DYAD Bank");
    setStyleSheet("background-color: transparent;");

}

sign::~sign()
{
    delete ui;
}

void sign::on_pushButton_3_clicked()
{
    payWidget = new payw(this);
    payWidget->show();
    this->hide();
    payWidget->setFixedSize(700,800);
}

void sign::on_pushButton_2_clicked()
{
    balanceWidget= new balance(this);
    balanceWidget->show();
    this->hide();
    balanceWidget->setFixedSize(690, 934);

}


void sign::on_pushButton_5_clicked()
{
    creditw = new credit(this);
    creditw->show();
    this->hide();
    creditw->setFixedSize(700,800);
}


void sign::on_pushButton_7_clicked()
{
    billsw=new bills(this);
    billsw->show();
    this->hide();
    billsw->setFixedSize(700,800);
}


void sign::on_pushButton_9_clicked()
{
    currw = new curr(this);
    currw->show();
    this->hide();
    currw->setFixedSize(700,800);
}


void sign::on_pushButton_11_clicked()
{
    mboxw = new mbox(this);
    mboxw->show();
    this->hide();
    mboxw->setFixedSize(700,800);
}


void sign::on_pushButton_13_clicked()
{
    secw = new sec(this);
    secw->show();
    this->hide();
    secw->setFixedSize(700,800);
}

