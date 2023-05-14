#include "bills.h"
#include "registration.h"
#include "ui_bills.h"

bills::bills(QDialog *sign,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::bills),
    sign(sign)
{
    ui->setupUi(this);
    setWindowTitle("DYAD Bank");
    setStyleSheet("background-color: transparent;");
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");

    db.setDatabaseName("data.db");
    if (!db.open()) {
        qDebug() << "Error opening database: " << db.lastError();
    } else {
        QSqlQuery query(db);


        query.prepare("SELECT * FROM Users WHERE Login = :login");
        query.bindValue(":login", globalLogin);


        if (query.exec() && query.first()) {



            QString type = query.value("TypeBills").toString();
            QString term = query.value("Term").toString();
            QString sum = query.value("SumCredit").toString();
            QString status = query.value("CreditStatus").toString();

            QStringList typelist = type.split(",");
            QStringList termlist =term.split(",");
            QStringList sumlist =sum.split(",");
            QStringList statuslist =status.split(",");
            QStandardItemModel *modeltype = new QStandardItemModel(this);
            QStandardItemModel *modelterm = new QStandardItemModel(this);
            QStandardItemModel *modelsum = new QStandardItemModel(this);
            QStandardItemModel *modelstatus = new QStandardItemModel(this);

            for (int i = 0; i < typelist.size(); i++) {
                    QStandardItem *itemtype = new QStandardItem(typelist[i]);
                    QStandardItem *itemterm = new QStandardItem(termlist[i]);
                    QStandardItem *itemsum = new QStandardItem();
                    QStandardItem *itemstatus = new QStandardItem();

                    qDebug() << "itemsum text =" << itemsum->text();
                    if(!sumlist[i].isEmpty() &&sumlist[i].toInt() <0){
                        QSqlQuery update(db);
                        update.prepare("UPDATE Users SET SumCredit = :credsum, BlockCard =:block WHERE Login=:login");
                        update.bindValue(":credsum", 0);
                        update.bindValue(":login", globalLogin);
                        if(update.exec() && update.first()&& update.isValid()){
                            qDebug() << "UPDATE CORRECT";
                            itemsum->setText(sumlist[i]);
                            db.commit();
                        }
                        else{
                            qDebug() << "UPDATE ERROR";
                        }
                    }
                    else if(!sumlist[i].isEmpty() &&sumlist[i].toInt()==0){
                        QString queryStr = QString("UPDATE Users SET CreditStatus='false', BlockCard='false' WHERE Login='%1'")
                            .arg(globalLogin);

                        QSqlQuery updatesec(db);
                        if (updatesec.exec(queryStr)) {
                            qDebug() << "UPDATE CORRECT";
                            itemsum->setText(sumlist[i]);
                            db.commit();
                        }
                        else{


                            qDebug() << "UPDATE ERROR sec";

                        }
                    }
                    else{
                        itemsum->setText(sumlist[i]);
                    }
                    if(statuslist[i] == "true" ){//|| !sumlist[i].isEmpty()
                        itemstatus->setText("Active");
                        qDebug()<< statuslist[i];
                        qDebug()<< sumlist[i];
                    }
                    else {
                        itemstatus->setText("Inactive");
                    }

                    itemsum->setText(sumlist[i]);
                    qDebug() << "sumlist[" << i << "] =" << sumlist[i];
                    modeltype->appendRow(itemtype);
                    modelterm->appendRow(itemterm);
                    modelsum->appendRow(itemsum);
                    modelstatus->appendRow(itemstatus);
                }

            ui->listView->setModel(modeltype);
            ui->listView_2->setModel(modelterm);
            ui->listView_3->setModel(modelsum);
            ui->listView_4->setModel(modelstatus);
            ui->listView->setEditTriggers(QAbstractItemView::NoEditTriggers);
            ui->listView_2->setEditTriggers(QAbstractItemView::NoEditTriggers);
            ui->listView_3->setEditTriggers(QAbstractItemView::NoEditTriggers);
            ui->listView_4->setEditTriggers(QAbstractItemView::NoEditTriggers);


        }
        else {
            qDebug() << "Error executing query: " << query.lastError();
        }
    }
}
bills::~bills()
{
    delete ui;
}

void bills::on_pushButton_clicked()
{
    this->hide();
    sign->show();
}
