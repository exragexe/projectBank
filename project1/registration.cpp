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
    //DATA BASE
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("data.db");
    if (db.open()) {
        qDebug() << "Database connected!";
    } else {
        qDebug() << "Failed to connect to database!";
    }
    QSqlQuery query("SELECT * FROM users");
    query.exec("INSERT INTO Users(Id, Login, Password, Money, CreditStatus, SumCredit, Moneybox)");
    if (query.exec()) {
        qDebug() << "Table created";
    } else {
        qDebug() << "Table NOT created";
    }


}

registration::~registration()
{
    delete ui;
}

void registration::on_pushButton_clicked()
{
    QString login = ui->login->text();
    QString pass = ui->pass->text();
    QSqlQuery checkQuery(db);
    checkQuery.prepare("SELECT COUNT(*) FROM Users WHERE Login = :login");
    checkQuery.bindValue(":login", login);
    if (checkQuery.exec() && checkQuery.first() && checkQuery.value(0).toInt() > 0) {
        qApp->setPalette(QApplication::style()->standardPalette());
        QMessageBox::critical(this, "Registration", "Error: Login already exists!");
    }
    else{
        checkQuery.prepare("SELECT MAX(Id) FROM Users");
        if (checkQuery.exec() && checkQuery.first()) {
            globalId = checkQuery.value(0).toInt() + 1;
        } else {

        }
        QSqlQuery query(db);
        query.prepare("INSERT INTO Users(Id, Login, Password, Money, CreditStatus, SumCredit, Moneybox) "
                          "VALUES (:id, :login, :pass, 0, 0, 0 , 0)");
        query.bindValue(":id", globalId);
        query.bindValue(":login", login);
        query.bindValue(":pass", pass);
        if(query.exec()){
            ui->login->clear();
            ui->pass->clear();
            mainw= new MainWindow(this);
            mainw->show();
            this->hide();
            mainw->setFixedSize(700, 800);
        }
        else{
            qApp->setPalette(QApplication::style()->standardPalette());
            QMessageBox::critical(this, "Registration", "Error: Registration failed!");
        }
    }

}


void registration::on_pushButton_2_clicked()
{
    mainw= new MainWindow(this);
    mainw->show();
    this->hide();
    mainw->setFixedSize(700, 800);
}

