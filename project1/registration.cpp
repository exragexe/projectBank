#include "registration.h"
#include "ui_registration.h"
#include "mainwindow.h"

registration::registration(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::registration)
{
    ui->setupUi(this);
    setWindowTitle("DYAD Bank");

    ui->login->setStyleSheet("background-color: #D9D9D9;");
    ui->pass->setStyleSheet("background-color: #D9D9D9;");
    setStyleSheet("background-color: transparent;");
}

registration::~registration()
{
    delete ui;
}

void registration::on_pushButton_clicked()
{
    mainw= new MainWindow(this);
    mainw->show();
    this->hide();
    mainw->setFixedSize(700, 800);


}

