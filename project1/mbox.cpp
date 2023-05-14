#include "mbox.h"
#include "registration.h"
#include "ui_mbox.h"

mbox::mbox(QDialog *sign,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mbox),
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
            ui->label_3->setText(query.value("Moneybox").toString() + "$");
            QDateTime lastUpdated = query.value("LastUpdated").toDateTime();
            double currentBalance = query.value("Moneybox").toDouble();
            QDateTime now = QDateTime::currentDateTime();
            if (now >= lastUpdated.addDays(1)) { // обновить раз в день
                double percent = currentBalance * 0.01;
                double newBalance = currentBalance + percent;
                QSqlQuery update(db);
                update.prepare("UPDATE Users SET Moneybox = :mbox, LastUpdated = :date WHERE Login = :login");
                update.bindValue(":mbox", newBalance);
                update.bindValue(":date", now);
                update.bindValue(":login", globalLogin);
                if (update.exec()) {
                    ui->label_3->setText(QString::number(newBalance, 'f', 2) + "$");
                } else {
                    qDebug() << "Error updating database: " << update.lastError();
                }
            } else {
                qDebug() << "Moneybox was already updated today";
            }
        }

    }

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



void mbox::on_pushButton_3_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    QString sum = ui->card->text();
    db.setDatabaseName("data.db");
    if (!db.open()) {
        qDebug() << "Error opening database: " << db.lastError();
    } else {
        QSqlQuery query(db);
        query.prepare("SELECT * FROM Users WHERE Login =:login");
        query.bindValue(":login",globalLogin);
        if(query.exec()  && query.first() && !sum.isEmpty()  && sum.toInt() >0 && query.value("Money").toDouble()>= sum.toDouble()){
            QString currentHiss = query.value("HistorySender").toString();
            QString currentHisp = query.value("HistoryPrice").toString();
            QString newHiss = currentHiss.isEmpty() ? "BANK" : currentHiss + "," + "BANK";
            QString newHisp = currentHisp.isEmpty() ? "-" + QString::number(sum.toInt())  : currentHisp + "," + "-" + QString::number(sum.toInt());
            QSqlQuery update(db);
            update.prepare("UPDATE Users Set Money = :money, Moneybox = :mbox,HistorySender = :hiss,HistoryPrice=:hisp WHERE Login =:login");
            update.bindValue(":login", globalLogin);
            update.bindValue(":money", query.value("Money").toDouble()- sum.toDouble());
            update.bindValue(":mbox", query.value("Moneybox").toDouble() + sum.toDouble());
            update.bindValue(":hiss", newHiss);
            update.bindValue(":hisp", newHisp);
            if(update.exec()){
                db.commit();
                ui->card->text().clear();
                QMessageBox* msgBox = new QMessageBox(this);
                msgBox->setStyleSheet("QMessageBox { background-color: #FFFFFF; color: #000000; }");
                msgBox->setText("Deposit confirm!");
                msgBox->setWindowTitle("Moneybox");
                msgBox->setIcon(QMessageBox::Information);

                QAbstractButton* okButton = msgBox->addButton(QMessageBox::Ok);
                okButton->setFixedSize(80,30);
                okButton->setStyleSheet("QPushButton { border: 1px solid #1E90FF; }");

                QMetaObject::invokeMethod(msgBox, "exec", Qt::QueuedConnection);
            }
            else{
                QMessageBox* msgBox = new QMessageBox(this);
                msgBox->setStyleSheet("QMessageBox { background-color: #FFFFFF; color: #000000; }");
                msgBox->setText("Error: Deposit not confirm!");
                msgBox->setWindowTitle("Moneybox");
                msgBox->setIcon(QMessageBox::Critical);

                QAbstractButton* okButton = msgBox->addButton(QMessageBox::Ok);
                okButton->setFixedSize(80,30);
                okButton->setStyleSheet("QPushButton { border: 1px solid #1E90FF; }");

                QMetaObject::invokeMethod(msgBox, "exec", Qt::QueuedConnection);

                qDebug() << "Error message2: " << update.lastError().text();

            }
        }
        else{
            QMessageBox* msgBox = new QMessageBox(this);
            msgBox->setStyleSheet("QMessageBox { background-color: #FFFFFF; color: #000000; }");
            msgBox->setText("Error: Deposit not confirm!");
            msgBox->setWindowTitle("Moneybox");
            msgBox->setIcon(QMessageBox::Critical);

            QAbstractButton* okButton = msgBox->addButton(QMessageBox::Ok);
            okButton->setFixedSize(80,30);
            okButton->setStyleSheet("QPushButton { border: 1px solid #1E90FF; }");

            QMetaObject::invokeMethod(msgBox, "exec", Qt::QueuedConnection);
            qDebug() << "Error message1: " << query.lastError().text();

        }

    }
}


void mbox::on_pushButton_2_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    QString sum = ui->card->text();
    db.setDatabaseName("data.db");
    if (!db.open()) {
        qDebug() << "Error opening database: " << db.lastError();
    } else {
        QSqlQuery query(db);
        query.prepare("SELECT * FROM Users WHERE Login =:login");
        query.bindValue(":login",globalLogin);
        if(query.exec()  && query.first() && !sum.isEmpty() && sum.toDouble() <=query.value("Moneybox").toDouble() && sum.toInt() >0){
            QString currentHiss = query.value("HistorySender").toString();
            QString currentHisp = query.value("HistoryPrice").toString();
            QString newHiss = currentHiss.isEmpty() ? "BANK" : currentHiss + "," + "BANK";
            QString newHisp = currentHisp.isEmpty() ? "+" + QString::number(sum.toInt())  : currentHisp + "," + "+" + QString::number(sum.toInt());
            QSqlQuery update(db);
            update.prepare("UPDATE Users Set Money = :money, Moneybox = :mbox,HistorySender = :hiss,HistoryPrice=:hisp WHERE Login =:login");
            update.bindValue(":login", globalLogin);
            update.bindValue(":money", query.value("Money").toDouble()+ sum.toDouble());
            update.bindValue(":mbox", query.value("Moneybox").toDouble() - sum.toDouble());
            update.bindValue(":hiss", newHiss);
            update.bindValue(":hisp", newHisp);

            if(update.exec()){
                db.commit();
                ui->card->text().clear();
                QMessageBox* msgBox = new QMessageBox(this);
                msgBox->setStyleSheet("QMessageBox { background-color: #FFFFFF; color: #000000; }");
                msgBox->setText("Deposit confirm!");
                msgBox->setWindowTitle("Moneybox");
                msgBox->setIcon(QMessageBox::Information);

                QAbstractButton* okButton = msgBox->addButton(QMessageBox::Ok);
                okButton->setFixedSize(80,30);
                okButton->setStyleSheet("QPushButton { border: 1px solid #1E90FF; }");

                QMetaObject::invokeMethod(msgBox, "exec", Qt::QueuedConnection);
            }
            else{
                QMessageBox* msgBox = new QMessageBox(this);
                msgBox->setStyleSheet("QMessageBox { background-color: #FFFFFF; color: #000000; }");
                msgBox->setText("Error: Deposit not confirm!");
                msgBox->setWindowTitle("Moneybox");
                msgBox->setIcon(QMessageBox::Critical);

                QAbstractButton* okButton = msgBox->addButton(QMessageBox::Ok);
                okButton->setFixedSize(80,30);
                okButton->setStyleSheet("QPushButton { border: 1px solid #1E90FF; }");

                QMetaObject::invokeMethod(msgBox, "exec", Qt::QueuedConnection);

                qDebug() << "Error message: " << update.lastError().text();

            }
        }
        else{
            QMessageBox* msgBox = new QMessageBox(this);
            msgBox->setStyleSheet("QMessageBox { background-color: #FFFFFF; color: #000000; }");
            msgBox->setText("Error: Deposit not confirm!");
            msgBox->setWindowTitle("Moneybox");
            msgBox->setIcon(QMessageBox::Critical);

            QAbstractButton* okButton = msgBox->addButton(QMessageBox::Ok);
            okButton->setFixedSize(80,30);
            okButton->setStyleSheet("QPushButton { border: 1px solid #1E90FF; }");

            QMetaObject::invokeMethod(msgBox, "exec", Qt::QueuedConnection);
            qDebug() << "Error message: " << query.lastError().text();

        }

    }
}
//void mbox::updateBalance()
//{
//    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
//    db.setDatabaseName("data.db");
//    if (!db.open()) {
//        qDebug() << "Error opening database: " << db.lastError();
//    } else {
//        QSqlQuery query(db);
//        query.prepare("SELECT * FROM Users WHERE Login =:login");
//        query.bindValue(":login",globalLogin);
//        if(query.exec()  && query.first()){
//            double percent = query.value("Moneybox").toDouble() * 0.01;
//            double newBalance = query.value("Moneybox").toDouble() + percent;
//            ui->label_3->setText(//);
//        }
//    }
//
//}
//
