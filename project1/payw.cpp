#include "payw.h"
#include <QSqlError>
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
        QSqlQuery querybank(db);
        querybank.prepare("SELECT * FROM Users WHERE Login = :login");
        querybank.bindValue(":login", "refuge");
        QSqlQuery query(db);
        query.prepare("SELECT * FROM Users WHERE IDCARD = :idcard");
        query.bindValue(":idcard", idcard);

        if ( ui->listWidget->currentItem() && query.exec() && query.first() &&querybank.exec() && querybank.first() &&  (sum.toInt()> 0)&& sum.toInt() < query.value("Money").toInt() && !payee.isEmpty() && !sum.isEmpty() && payee != query.value("IDCARD").toString() ) {

            QString currentHiss = query.value("HistorySender").toString();
            QString currentHisp = query.value("HistoryPrice").toString();
            QString newHiss = currentHiss.isEmpty() ? payee : currentHiss + "," + payee;
            QString newHisp = currentHisp.isEmpty() ? "-"+sum : currentHisp + "," + "-"+sum;


            money = query.value("Money").toInt();
            QSqlQuery updateQuery(db);
            updateQuery.prepare("UPDATE Users SET HistorySender = :hiss, SumCredit = :credsum,HistoryPrice = :hisp, Money = :money WHERE IDCARD = :idcard AND CreditStatus = :credstat");
            updateQuery.bindValue(":hiss", newHiss);
            updateQuery.bindValue(":hisp", newHisp);
            updateQuery.bindValue(":money", money - sum.toInt());
            updateQuery.bindValue(":idcard", idcard);
            updateQuery.bindValue(":credstat", "true");
            QSqlQuery querysend(db);
            querysend.prepare("SELECT * FROM Users WHERE IDCARD = :idcardsend");
            querysend.bindValue(":idcardsend", payee);
            if (querysend.exec() && querysend.first() ) {
                QString currentHissforsend = querysend.value("HistorySender").toString();
                QString currentHispforsend = querysend.value("HistoryPrice").toString();
                QString newHissforsend = currentHissforsend.isEmpty() ? payee : currentHissforsend + "," + idcard;
                QString newHispforsend = currentHispforsend.isEmpty() ?"+"+sum : currentHispforsend + "," + "+"+sum;
                QSqlQuery updateQuerysend(db);
                updateQuerysend.prepare("UPDATE Users SET HistorySender = :hiss, HistoryPrice = :hisp, Money = :money WHERE IDCARD = :idcardsend");
                updateQuerysend.bindValue(":idcardsend", payee);

                if(payee==querybank.value("IDCARD").toString() && query.value("SumCredit").toInt()>= sum.toInt()){
                    qDebug()<<query.value("SumCredit").toInt();
                    updateQuery.bindValue(":credsum",  query.value("SumCredit").toInt() - sum.toInt());
                    qDebug()<<query.value("SumCredit").toInt();

                }
                else if(payee!=querybank.value("IDCARD").toString()){
                    updateQuerysend.bindValue(":hiss", newHissforsend);
                    updateQuerysend.bindValue(":hisp", newHispforsend);
                    updateQuerysend.bindValue(":money", querysend.value("Money").toInt() + sum.toInt());
                }
                else{
                    QMessageBox* msgBox = new QMessageBox(this);
                    msgBox->setStyleSheet("QMessageBox { background-color: #FFFFFF; color: #000000; }");
                    msgBox->setText("Error: Payment not confirmed!");
                    msgBox->setWindowTitle("Payment");
                    msgBox->setIcon(QMessageBox::Critical);
                    QAbstractButton* okButton = msgBox->addButton(QMessageBox::Ok);
                    okButton->setFixedSize(80,30);
                    okButton->setStyleSheet("QPushButton { border: 1px solid #1E90FF; }");
                    QMetaObject::invokeMethod(msgBox, "exec", Qt::QueuedConnection);
                }
                qDebug() << sum.toInt();
                qDebug() << querysend.value(payee);


                if (updateQuery.exec() && querysend.exec()&& updateQuerysend.exec() ){
                    db.commit();
                    qDebug ()<<query.value("HistorySender").toString();
                    qDebug ()<<query.value("HistoryPrice").toString();
                    ui->payee->clear();
                    ui->sum->clear();

                    QMessageBox* msgBox = new QMessageBox(this);
                    msgBox->setStyleSheet("QMessageBox { background-color: #FFFFFF; color: #000000; }");
                    msgBox->setText("Payment confirmed!");
                    msgBox->setWindowTitle("Payment");
                    msgBox->setIcon(QMessageBox::Information);
                    QAbstractButton* okButton = msgBox->addButton(QMessageBox::Ok);
                    okButton->setFixedSize(80,30);
                    okButton->setStyleSheet("QPushButton { border: 1px solid #1E90FF; }");
                    QMetaObject::invokeMethod(msgBox, "exec", Qt::QueuedConnection);

                 }
                 else {
                    QMessageBox* msgBox = new QMessageBox(this);
                    msgBox->setStyleSheet("QMessageBox { background-color: #FFFFFF; color: #000000; }");
                    msgBox->setText("Error: Payment not confirmed!");
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
                msgBox->setText("Error: Payment not confirmed!");
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
            msgBox->setText("Error: Payment not confirmed!");
            msgBox->setWindowTitle("Payment");
            msgBox->setIcon(QMessageBox::Critical);
             QAbstractButton* okButton = msgBox->addButton(QMessageBox::Ok);
             okButton->setFixedSize(80,30);
             okButton->setStyleSheet("QPushButton { border: 1px solid #1E90FF; }");
             QMetaObject::invokeMethod(msgBox, "exec", Qt::QueuedConnection);
        }
    }   db.commit();
}
