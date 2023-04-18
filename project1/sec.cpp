#include "sec.h"
#include "ui_sec.h"

sec::sec(QDialog *sign,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sec),
    sign(sign)
{
    ui->setupUi(this);
    setWindowTitle("DYAD Bank");
    setStyleSheet("background-color: transparent;");
}

sec::~sec()
{
    delete ui;
}

void sec::on_pushButton_clicked()
{
    this->hide();
    sign->show();
}

