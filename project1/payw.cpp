#include "payw.h"
#include "qsqlerror.h"
#include "registration.h"
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
    //ui->card->setStyleSheet("background-color: #2E2E2E;");

    //CARD

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");

    db.setDatabaseName("data.db");
    if (!db.open()) {
        qDebug() << "Error opening database: " << db.lastError();
    } else {
        QSqlQuery query(db);

        query.prepare("SELECT * FROM Users WHERE Login = :login");
        query.bindValue(":login", globalLogin);

        if (query.exec() && query.first()) {
            idcard =query.value("IDCARD").toString();
            ui->listWidget->addItem(idcard);


        } else {

        }

    }
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

void payw::on_pushButton_2_clicked()
{
    QString payee = ui->payee->text();
    QString sum = ui->sum->text();

    int money = 0;

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("data.db");
    if (!db.open()) {
        qDebug() << "Error opening database: " << db.lastError();
    } else {
        QSqlQuery query(db);
        query.prepare("SELECT * FROM Users WHERE IDCARD = :idcard");
        query.bindValue(":idcard", idcard);//ui->listWidget->currentItem()->text());

        //ui->listWidget->currentItem()->text()!=nullptr
        if (query.exec() && query.first() &&  (sum.toInt()> 0)&& sum.toInt() < query.value("Money").toInt() && !payee.isEmpty() && !sum.isEmpty() && payee != query.value("IDCARD").toString() ) {
            money = query.value("Money").toInt();


            QSqlQuery updateQuery(db);
            updateQuery.prepare("UPDATE Users SET HistorySender = :hiss, HistoryPrice = :hisp, Money = :money WHERE IDCARD = :idcard");
            updateQuery.bindValue(":hiss", payee);
            updateQuery.bindValue(":hisp", sum);
            updateQuery.bindValue(":money", money - sum.toInt());
            updateQuery.bindValue(":idcard", idcard);
            QSqlQuery querysend(db);
            querysend.prepare("SELECT * FROM Users WHERE IDCARD = :idcardsend");
            querysend.bindValue(":idcardsend", payee);


            if (querysend.exec() && querysend.first()) {

                querysend.prepare("UPDATE Users SET Money = :money WHERE IDCARD = :idcardsend");
                querysend.bindValue(":idcardsend", payee);
                querysend.bindValue(":money", querysend.value("Money").toInt() + sum.toInt());

                qDebug() << sum.toInt();
                qDebug() << updateQuery.value(payee);


                if (updateQuery.exec() && querysend.exec()){
                    ui->payee->clear();
                    ui->sum->clear();
                    QMessageBox* msgBox = new QMessageBox(this);
                    msgBox->setStyleSheet("QMessageBox { background-color: #FFFFFF; color: #000000; }");
                    msgBox->setText("Payment confirm!");
                    msgBox->setWindowTitle("Payment");
                    msgBox->setIcon(QMessageBox::Information);
                    QAbstractButton* okButton = msgBox->addButton(QMessageBox::Ok);
                    okButton->setFixedSize(80,30);
                    okButton->setStyleSheet("QPushButton { border: 1px solid #1E90FF; }");
                    QMetaObject::invokeMethod(msgBox, "exec", Qt::QueuedConnection);
                    db.commit();
                 }
                 else {
                    QMessageBox* msgBox = new QMessageBox(this);
                    msgBox->setStyleSheet("QMessageBox { background-color: #FFFFFF; color: #000000; }");
                    msgBox->setText("Error: Payment not confirm!");
                    msgBox->setWindowTitle("Payment");
                    msgBox->setIcon(QMessageBox::Critical);
                    QAbstractButton* okButton = msgBox->addButton(QMessageBox::Ok);
                    okButton->setFixedSize(80,30);
                    okButton->setStyleSheet("QPushButton { border: 1px solid #1E90FF; }");
                    QMetaObject::invokeMethod(msgBox, "exec", Qt::QueuedConnection);
                }
                db.commit();
            }
            else{
                QMessageBox* msgBox = new QMessageBox(this);
                msgBox->setStyleSheet("QMessageBox { background-color: #FFFFFF; color: #000000; }");
                msgBox->setText("Error: Payment not confirm!");
                msgBox->setWindowTitle("Payment");
                msgBox->setIcon(QMessageBox::Critical);
                QAbstractButton* okButton = msgBox->addButton(QMessageBox::Ok);
                okButton->setFixedSize(80,30);
                okButton->setStyleSheet("QPushButton { border: 1px solid #1E90FF; }");
                QMetaObject::invokeMethod(msgBox, "exec", Qt::QueuedConnection);
            }
            db.commit();
        }
        else{
            QMessageBox* msgBox = new QMessageBox(this);
            msgBox->setStyleSheet("QMessageBox { background-color: #FFFFFF; color: #000000; }");
            msgBox->setText("Error: Payment not confirm!");
            msgBox->setWindowTitle("Payment");
            msgBox->setIcon(QMessageBox::Critical);
             QAbstractButton* okButton = msgBox->addButton(QMessageBox::Ok);
             okButton->setFixedSize(80,30);
             okButton->setStyleSheet("QPushButton { border: 1px solid #1E90FF; }");
             QMetaObject::invokeMethod(msgBox, "exec", Qt::QueuedConnection);
        }
    }   db.commit();
}


