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
        query.bindValue(":idcard", idcard);

        if (query.exec() && query.first() && (sum.toInt()> 0) && !payee.isEmpty() && !sum.isEmpty() && payee != idcard) {
            money = query.value("Money").toInt();
            QString idsender = query.value("IDCARD").toString();

            QSqlQuery updateQuery(db);
            updateQuery.prepare("UPDATE Users SET HistorySender = :hiss, HistoryPrice = :hisp, Money = :money WHERE IDCARD = :idcard");
            updateQuery.bindValue(":hiss", payee);
            updateQuery.bindValue(":hisp", sum);
            updateQuery.bindValue(":money", money - sum.toInt());
            QSqlQuery querysend(db);
            querysend.prepare("SELECT * FROM Users WHERE IDCARD = :idcardsend");
            querysend.bindValue(":idcardsend", payee);

            if (querysend.exec() && querysend.first()) {
                QSqlQuery updatesendQuery(db);
                updatesendQuery.prepare("UPDATE Users SET Money = :money WHERE IDCARD = :idcardsend");
                updatesendQuery.bindValue(":money", querysend.value("Money").toInt() + sum.toInt());

                if (updateQuery.exec() && updatesendQuery.exec()){
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

        }
    }
}


