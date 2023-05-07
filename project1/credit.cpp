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
        if(query.exec() && query.first() && !sum.isEmpty() && sum.toInt() > 0 && query.value("CreditStatus").toBool()==false){
            QSqlQuery updateQuery(db);
            updateQuery.prepare("UPDATE Users SET CreditStatus = :credstat, SumCredit = :credsum, Money = :money WHERE Login = :login");
            updateQuery.bindValue(":login", globalLogin);
            if(ui->listWidget->currentItem()->text() == "1 month"){
                procentforsend =(1.0/sum.toInt()) * 100.0;
                updateQuery.bindValue(":credstat", true);
                updateQuery.bindValue(":credsum", sum.toInt()*procentforsend);

                updateQuery.bindValue(":money", sum.toInt()+ updateQuery.value("Money").toInt());

            }

            else if(ui->listWidget->currentItem()->text() == "3 month"){
                procentforsend =(3.0/sum.toInt()) * 100.0;
                ui->label_8->setText(QString::number(procentforsend));
                updateQuery.bindValue(":credstat", true);
                updateQuery.bindValue(":credsum", sum.toInt()*procentforsend);
                updateQuery.bindValue(":money", sum.toInt()+ updateQuery.value("Money").toInt());
            }

            else if(ui->listWidget->currentItem()->text() == "6 month"){
                procentforsend =(6.0/sum.toInt()) * 100.0;
                ui->label_8->setText(QString::number(procentforsend));
                updateQuery.bindValue(":credstat", true);
                updateQuery.bindValue(":credsum", sum.toInt()*procentforsend);
                updateQuery.bindValue(":money", sum.toInt()+ updateQuery.value("Money").toInt());
            }

            else if(ui->listWidget->currentItem()->text() == "12 month"){
                procentforsend =(12.0/sum.toInt()) * 100.0;
                ui->label_8->setText(QString::number(procentforsend));
                updateQuery.bindValue(":credstat", true);
                updateQuery.bindValue(":credsum", sum.toInt()*procentforsend);
                updateQuery.bindValue(":money", sum.toInt()+ updateQuery.value("Money").toInt());
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

            QMessageBox* msgBox = new QMessageBox(this);
            msgBox->setStyleSheet("QMessageBox { background-color: #FFFFFF; color: #000000; }");
            msgBox->setText("Credit confirn!");
            msgBox->setWindowTitle("Credit");
            msgBox->setIcon(QMessageBox::Information);

            QAbstractButton* okButton = msgBox->addButton(QMessageBox::Ok);
            okButton->setFixedSize(80,30);
            okButton->setStyleSheet("QPushButton { border: 1px solid #1E90FF; }");

            QMetaObject::invokeMethod(msgBox, "exec", Qt::QueuedConnection);


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
    }
}
void credit::updatePercent()
{
    bool ok;
    //int procentforsend =(12.0/ui->lineEdit->text().toInt()) * 100.0;


    if (ok) {

        ui->label_8->setText(QString::number(procentforsend));
    }
}

