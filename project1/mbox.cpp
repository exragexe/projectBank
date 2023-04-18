#include "mbox.h"
#include "ui_mbox.h"

mbox::mbox(QDialog *sign,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mbox),
    sign(sign)
{
    ui->setupUi(this);
    //connect(ui->exi, &QPushButton::clicked, this, &mbox::exi);
    setWindowTitle("DYAD Bank");
    setStyleSheet("background-color: transparent;");
}

mbox::~mbox()
{
    delete ui;
}

void mbox::on_exi_clicked()
{
    this->hide();
    sign->show();
}

