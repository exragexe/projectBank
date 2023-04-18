#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("DYAD Bank");
    setStyleSheet("background-color: white;");


    ui->label_3->setStyleSheet("background-color: transparent;");
    //.............
    QLabel labellg;
    QFont font("Microsoft Yi Baiti", 24);
    font.setPixelSize(2);
    labellg.setFont(font);
    labellg.setStyleSheet("QLabel { border: 3px dashed blue; }");
    ui->login->setStyleSheet("background-color: #D9D9D9;");
    ui->pass->setStyleSheet("background-color: #D9D9D9;");
    ui->pass->setEchoMode(QLineEdit::Password);
    //......
    setStyleSheet("background-color: transparent;");
    //DATABASE

}

MainWindow::~MainWindow()
{
    delete ui;

}




void MainWindow::on_pushButton_2_clicked()
{
   QString login = ui->login->text();
   QString pass = ui->pass->text();
   if(login =="1" && pass =="1"){
       hide();
       window = new sign(this);
       window->setFixedSize(700, 800);
       window->show();

    }
    else{

       QMessageBox messageBox;
               messageBox.setStyleSheet("color:red;background:blue");

               messageBox.critical(this, "Ошибка", "Неправильный логин или пароль!");

    }
}


void MainWindow::on_pushButton_clicked()
{
    hide();
    window2 = new registration(this);
    window2->setFixedSize(700, 800);
    window2->show();
}

