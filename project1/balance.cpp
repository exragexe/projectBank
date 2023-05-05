#include "balance.h"
#include "registration.h"
#include "ui_balance.h"



balance::balance(QDialog *sign,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::balance),
    sign(sign)
{
    ui->setupUi(this);
    qint64 money;
    setWindowTitle("DYAD Bank");
    setStyleSheet("background-color: transparent;");
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");

    db.setDatabaseName("data.db");
    if (!db.open()) {
        qDebug() << "Error opening database: " << db.lastError();
    } else {
        QSqlQuery query(db);

        //balance
        query.prepare("SELECT * FROM Users WHERE Login = :login");
        query.bindValue(":login", globalLogin);


        if (query.exec() && query.first()) {
            QString money = query.value("Money").toString();
            ui->label_5->setText(money + " $");
            //QString idcard = query.value("IDCARD").toString();

            //QSqlQuery updateQuery(db);
            //updateQuery.prepare("UPDATE Users SET Money = :money WHERE IDCARD = :idcard");
            //updateQuery.bindValue(":money",999);
            //updateQuery.bindValue(":idcard",idcard);
            //if(updateQuery.exec()){
            //
            //}
            //else{
            //    qDebug() << "Error updating database: " << updateQuery.lastError();
            //}


        } else {
               qDebug() << "Error executing query: " << query.lastError();
        }

        //history
        QSqlQueryModel * modal = new QSqlQueryModel();

        query.prepare("SELECT * FROM Users WHERE Login = :login");
        query.bindValue(":login", globalLogin);
        if (query.exec() && query.first()) {
            QString hisp = query.value("HistoryPrice").toString();
            QString hiss = query.value("HistorySender").toString();


            modal->setQuery(hisp + hiss);

            ui->listView->setModel(modal);

            ui->label_7->setText(query.value("IDCARD").toString());
        } else {

        }
    }



}

balance::~balance()
{
    delete ui;
}

void balance::on_pushButton_clicked()
{
    this->hide();
    sign->show();

}

