#include "credit.h"
#include "registration.h"
#include "ui_credit.h"

credit::credit(QDialog *sign, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::credit),
    sign(sign)
{
    ui->setupUi(this);
    setWindowTitle("DYAD Bank");
    setStyleSheet("background-color: transparent;");
    ui->lineEdit->setStyleSheet("background-color: #2E2E2E;");

    connect(ui->listWidget, &QListWidget::currentItemChanged, this, &credit::updatePercent);
    connect(ui->lineEdit, &QLineEdit::textChanged, this, &credit::updatePercent);

}

credit::~credit()
{
    delete ui;
}

void credit::on_pushButton_clicked()
{
    this->hide();
    sign->show();
}


void credit::on_pushButton_2_clicked()
{
    QString sum = ui->lineEdit->text();
    ;
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("data.db");
    if (!db.open()) {
        qDebug() << "Error opening database: " << db.lastError();
    } else {
        QSqlQuery query(db);

        query.prepare("SELECT * FROM Users WHERE Login = :login");
        query.bindValue(":login", globalLogin);
        qDebug()<<query.value("CreditStatus").toBool();
        query.last();
        if(query.exec()  && query.first() &&!sum.isEmpty() && sum.toInt() > 0 && query.value("CreditStatus").toBool() && sum.toInt() <= 100000){
            QString currentHiss = query.value("HistorySender").toString();
            QString currentHisp = query.value("HistoryPrice").toString();
            QString newHiss = currentHiss.isEmpty() ? "BANK" : currentHiss + "," + "BANK";
            QString newHisp = currentHisp.isEmpty() ? "+" + QString::number(sum.toInt())  : currentHisp + "," + "+" + QString::number(sum.toInt());

            QString currentStat = query.value("CreditStatus").toString();
            QString currentSum = query.value("SumCredit").toString();
            QString currentTerm = query.value("Term").toString();
            QString currentType = query.value("TypeBills").toString();

            QString newStat = currentStat.isEmpty() ? "true" : currentStat + "," + "true" ;
            QString newSum = currentSum.isEmpty() ? QString::number(sum.toInt()*procentforsend+sum.toInt()) : currentSum + "," + QString::number(sum.toInt()*procentforsend+sum.toInt());
            QString newType = currentType.isEmpty() ? "Credit" : currentType + "," + "Credit";


            QSqlQuery updateQuery(db);
            updateQuery.prepare("UPDATE Users SET CreditStatus = :credstat, SumCredit = :credsum, Money = :money, TypeBills = :type, HistorySender = :hiss, HistoryPrice = :hisp, Term = :term WHERE Login = :login");

            updateQuery.bindValue(":login", globalLogin);

            if(ui->listWidget->currentItem()->text() == "1 month"){
                QDateTime currentDateTime = QDateTime::currentDateTime();
                QDateTime futureDateTime = currentDateTime.addMonths(1);
                QString dateString = futureDateTime.toString("yyyy.MM.dd");
                QString newTerm = currentTerm.isEmpty() ? dateString : currentTerm + "," + dateString;
                //====================
                procentforsend =(1.0/sum.toInt()) * 100.0;
                updateQuery.bindValue(":credstat", "");//newStat);
                updateQuery.bindValue(":credsum", "");//newSum);
                updateQuery.bindValue(":term", "");//newTerm);
                updateQuery.bindValue(":type", "");//newType);
                updateQuery.bindValue(":money", sum.toInt()+ query.value("Money").toInt());
                updateQuery.bindValue(":hiss", newHiss);
                updateQuery.bindValue(":hisp", newHisp);

            }
            else if(ui->listWidget->currentItem()->text() == "3 month"){
                QDateTime currentDateTime = QDateTime::currentDateTime();
                QDateTime futureDateTime = currentDateTime.addMonths(3);
                QString dateString = futureDateTime.toString("yyyy.MM.dd");
                QString newTerm = currentTerm.isEmpty() ? dateString : currentTerm + "," + dateString;
                //====================
                procentforsend =(3.0/sum.toInt()) * 100.0;
                ui->label_8->setText(QString::number(procentforsend));
                updateQuery.bindValue(":credstat", newStat);
                updateQuery.bindValue(":credsum", newSum);
                updateQuery.bindValue(":term", newTerm);
                updateQuery.bindValue(":type", newType);
                updateQuery.bindValue(":money", sum.toInt()+ query.value("Money").toInt());
                updateQuery.bindValue(":hiss", newHiss);
                updateQuery.bindValue(":hisp", newHisp);

            }

            else if(ui->listWidget->currentItem()->text() == "6 month"){

                QDateTime currentDateTime = QDateTime::currentDateTime();
                QDateTime futureDateTime = currentDateTime.addMonths(6);
                QString dateString = futureDateTime.toString("yyyy.MM.dd");
                QString newTerm = currentTerm.isEmpty() ? dateString : currentTerm + "," + dateString;
                //====================
                procentforsend =(6.0/sum.toInt()) * 100.0;
                ui->label_8->setText(QString::number(procentforsend));
                updateQuery.bindValue(":credstat", newStat);
                updateQuery.bindValue(":credsum", newSum);
                updateQuery.bindValue(":term", newTerm);
                updateQuery.bindValue(":type", newType);
                updateQuery.bindValue(":money", sum.toInt()+ query.value("Money").toInt());
                updateQuery.bindValue(":hiss", newHiss);
                updateQuery.bindValue(":hisp", newHisp);

            }

            else if(ui->listWidget->currentItem()->text() == "12 month"){

                QDateTime currentDateTime = QDateTime::currentDateTime();
                QDateTime futureDateTime = currentDateTime.addMonths(12);
                QString dateString = futureDateTime.toString("yyyy.MM.dd");
                QString newTerm = currentTerm.isEmpty() ? dateString : currentTerm + "," + dateString;
                //====================
                procentforsend =(12.0/sum.toInt()) * 100.0;
                ui->label_8->setText(QString::number(procentforsend));
                updateQuery.bindValue(":credstat", newStat);
                updateQuery.bindValue(":credsum", newSum);
                updateQuery.bindValue(":term", newTerm);
                updateQuery.bindValue(":type", newType);
                updateQuery.bindValue(":money", sum.toInt()+ query.value("Money").toInt());
                updateQuery.bindValue(":hiss", newHiss);
                updateQuery.bindValue(":hisp", newHisp);

            }

            else{
                QMessageBox* msgBox = new QMessageBox(this);
                msgBox->setStyleSheet("QMessageBox { background-color: #FFFFFF; color: #000000; }");
                msgBox->setText("Error: Credit failed!");
                msgBox->setWindowTitle("Credit");
                msgBox->setIcon(QMessageBox::Critical);

                QAbstractButton* okButton = msgBox->addButton(QMessageBox::Ok);
                okButton->setFixedSize(80,30);
                okButton->setStyleSheet("QPushButton { border: 1px solid #1E90FF; }");

                QMetaObject::invokeMethod(msgBox, "exec", Qt::QueuedConnection);

                qDebug() << "Error message: " << query.lastError().text();
            }
            if(updateQuery.exec()){
                db.commit();
                ui->lineEdit->text().clear();
                QMessageBox* msgBox = new QMessageBox(this);
                msgBox->setStyleSheet("QMessageBox { background-color: #FFFFFF; color: #000000; }");
                msgBox->setText("Credit confirm!");
                msgBox->setWindowTitle("Credit");
                msgBox->setIcon(QMessageBox::Information);

                QAbstractButton* okButton = msgBox->addButton(QMessageBox::Ok);
                okButton->setFixedSize(80,30);
                okButton->setStyleSheet("QPushButton { border: 1px solid #1E90FF; }");

                QMetaObject::invokeMethod(msgBox, "exec", Qt::QueuedConnection);
            }



        }
        else{
            QMessageBox* msgBox = new QMessageBox(this);
            msgBox->setStyleSheet("QMessageBox { background-color: #FFFFFF; color: #000000; }");
            msgBox->setText("Error: Credit failed!");
            msgBox->setWindowTitle("Credit");
            msgBox->setIcon(QMessageBox::Critical);

            QAbstractButton* okButton = msgBox->addButton(QMessageBox::Ok);
            okButton->setFixedSize(80,30);
            okButton->setStyleSheet("QPushButton { border: 1px solid #1E90FF; }");

            QMetaObject::invokeMethod(msgBox, "exec", Qt::QueuedConnection);

            qDebug() << "Error message: " << query.lastError().text();
            qDebug() << "Error message: " << query.value("CreditStatus").toBool();
        }
        db.commit();
    }
}
void credit::updatePercent()
{
    QString sum = ui->lineEdit->text();


    if(ui->listWidget->currentItem()){

        if(ui->listWidget->currentItem()->text() == "1 month"){
            procentforsend =(1.0/sum.toInt()) * 100.0;
        }

        else if(ui->listWidget->currentItem()->text() == "3 month"){
            procentforsend =(3.0/sum.toInt()) * 100.0;
            ui->label_8->setText(QString::number(procentforsend));

        }
        else if(ui->listWidget->currentItem()->text() == "6 month"){
            procentforsend =(6.0/sum.toInt()) * 100.0;
            ui->label_8->setText(QString::number(procentforsend));
        }
        else if(ui->listWidget->currentItem()->text() == "12 month"){
            procentforsend =(12.0/sum.toInt()) * 100.0;
            ui->label_8->setText(QString::number(procentforsend));
        }
        ui->label_8->setText(QString::number(procentforsend));
    }
    else{
         ui->label_8->setText("-");
    }
}
