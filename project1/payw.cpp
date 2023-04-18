#include "payw.h"
#include "ui_payw.h"

payw::payw(QDialog *sign,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::payw),
    sign(sign)
{
    ui->setupUi(this);
    connect(ui->exi, &QPushButton::clicked, this, &payw::exi);
    setWindowTitle("DYAD Bank");
    setStyleSheet("background-color: transparent;");
    ui->sum->setStyleSheet("background-color: #2E2E2E;");
    ui->payee->setStyleSheet("background-color: #2E2E2E;");
    ui->card->setStyleSheet("background-color: #2E2E2E;");
}

payw::~payw()
{
    delete ui;
}


void payw::exi()
{
    this->hide();
    sign->show();
}



