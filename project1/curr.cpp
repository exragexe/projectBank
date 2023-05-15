#include "curr.h"
#include "registration.h"
#include "ui_curr.h"

curr::curr(QDialog *sign,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::curr),
    sign(sign)
{
    ui->setupUi(this);
    setWindowTitle("DYAD Bank");
    setStyleSheet("background-color: transparent;");
    ui->sel->hide();
    connect(ui->lineEdit, &QLineEdit::textChanged, this, &curr::updateValuts);
}

curr::~curr()
{
    delete ui;
}

void curr::on_exi_clicked()
{
    this->hide();
    sign->show();
}


void curr::on_pushButton_4_clicked()
{
    if(ui->sel->isVisible()){
        ui->sel->hide();
        ui->buy->show();
    } else {
    ui->buy->hide();
    ui->sel->show();
    }

}


void curr::on_sel_clicked()//SEL
{
    QString sumnum= ui->lineEdit->text();
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("data.db");
    if (!db.open()) {
        qDebug() << "Error opening database: " << db.lastError();
    } else {
        QSqlQuery query(db);

        query.prepare("SELECT * FROM Users WHERE Login = :login");
        query.bindValue(":login", globalLogin);
        if(query.exec()&&query.first() && ui->listWidget->currentItem() && ui->listWidget_2->currentItem() && !sumnum.isEmpty()&&sumnum.toDouble()>0){

            QSqlQuery update(db);
            update.prepare("UPDATE Users SET Money =:mon,EUR =:eur,UAH=:uah,PLN=:pln,HistorySender = :hiss, HistoryPrice = :hisp WHERE Login = :login");
            update.bindValue(":login", globalLogin);
            if(ui->listWidget->currentItem()->text()=="USD"&& ui->listWidget_2->currentItem()->text() == "PLN"&&query.value("Money").toDouble()>=sumnum.toDouble()){
                valut=dolarvzlot*sumnum.toDouble();
                update.bindValue(":mon",query.value("Money").toDouble()-valut);
                update.bindValue(":pln",query.value("PLN").toDouble()+valut);
            }
            else if(ui->listWidget->currentItem()->text()=="USD"&& ui->listWidget_2->currentItem()->text() == "UAH"&&query.value("Money").toDouble()>=sumnum.toDouble()){
                valut=dolarvgrn*sumnum.toDouble();
                update.bindValue(":mon",query.value("Money").toDouble()-valut);
                update.bindValue(":uah",query.value("UAH").toDouble()+valut);
            }
            else if(ui->listWidget->currentItem()->text()=="USD"&& ui->listWidget_2->currentItem()->text() == "EUR"&&query.value("Money").toDouble()>=sumnum.toDouble()){
                valut=dolarveuro*sumnum.toDouble();
                update.bindValue(":mon",query.value("Money").toDouble()-valut);
                update.bindValue(":eur",query.value("EUR").toDouble()+valut);
            }
            else if(ui->listWidget->currentItem()->text()=="PLN"&& ui->listWidget_2->currentItem()->text() == "USD"&&query.value("PLN").toDouble()>=sumnum.toDouble()){
                valut=zlotvdolar*sumnum.toDouble();
                update.bindValue(":pln",query.value("PLN").toDouble()-valut);
                update.bindValue(":mon",query.value("Money").toDouble()+valut);
            }
            else if(ui->listWidget->currentItem()->text()=="PLN"&& ui->listWidget_2->currentItem()->text() == "UAH"&&query.value("PLN").toDouble()>=sumnum.toDouble()){
                valut=zlotvgrn*sumnum.toDouble();
                update.bindValue(":pln",query.value("PLN").toDouble()-valut);
                update.bindValue(":uah",query.value("UAH").toDouble()+valut);
            }
            else if(ui->listWidget->currentItem()->text()=="PLN"&& ui->listWidget_2->currentItem()->text() == "EUR"&&query.value("PLN").toDouble()>=sumnum.toDouble()){
                valut=zlotveuro*sumnum.toDouble();
                update.bindValue(":pln",query.value("PLN").toDouble()-valut);
                update.bindValue(":eur",query.value("EUR").toDouble()+valut);
            }
            else if(ui->listWidget->currentItem()->text()=="UAH"&& ui->listWidget_2->currentItem()->text() == "PLN"&&query.value("UAH").toDouble()>=sumnum.toDouble()){
                valut=grnvzlot*sumnum.toDouble();
                update.bindValue(":uah",query.value("UAH").toDouble()-valut);
                update.bindValue(":pln",query.value("PLN").toDouble()+valut);
            }
            else if(ui->listWidget->currentItem()->text()=="UAH"&& ui->listWidget_2->currentItem()->text() == "USD"&&query.value("UAH").toDouble()>=sumnum.toDouble()){
                valut=grnvdolar*sumnum.toDouble();
                update.bindValue(":uah",query.value("UAH").toDouble()-valut);
                update.bindValue(":mon",query.value("Money").toDouble()+valut);
            }
            else if(ui->listWidget->currentItem()->text()=="UAH"&& ui->listWidget_2->currentItem()->text() == "EUR"&&query.value("UAH").toDouble()>=sumnum.toDouble()){
                valut=grnveuro*sumnum.toDouble();
                update.bindValue(":uah",query.value("UAH").toDouble()-valut);
                update.bindValue(":eur",query.value("EUR").toDouble()+valut);
            }
            else if(ui->listWidget->currentItem()->text()=="EUR"&& ui->listWidget_2->currentItem()->text() == "USD"&&query.value("EUR").toDouble()>=sumnum.toDouble()){
                valut=eurovdolar*sumnum.toDouble();
                update.bindValue(":eur",query.value("EUR").toDouble()-valut);
                update.bindValue(":mon",query.value("Money").toDouble()+valut);
            }
            else if(ui->listWidget->currentItem()->text()=="EUR"&& ui->listWidget_2->currentItem()->text() == "UAH"&&query.value("EUR").toDouble()>=sumnum.toDouble()){
                valut=eurovgrn*sumnum.toDouble();
                update.bindValue(":eur",query.value("EUR").toDouble()-valut);
                update.bindValue(":uah",query.value("UAH").toDouble()+valut);
            }
            else if(ui->listWidget->currentItem()->text()=="EUR"&& ui->listWidget_2->currentItem()->text() == "PLN"&&query.value("EUR").toDouble()>=sumnum.toDouble()){
                valut=eurovzlot*sumnum.toDouble();
                update.bindValue(":eur",query.value("EUR").toDouble()-valut);
                update.bindValue(":pln",query.value("PLN").toDouble()+valut);
            }

            if(update.exec()){
                db.commit();
                sumnum.clear();
                ui->label_4->clear();
                QMessageBox* msgBox = new QMessageBox(this);
                msgBox->setStyleSheet("QMessageBox { background-color: #FFFFFF; color: #000000; }");
                msgBox->setText("Currency exchange confirmed!");
                msgBox->setWindowTitle("Currency");
                msgBox->setIcon(QMessageBox::Information);

                QAbstractButton* okButton = msgBox->addButton(QMessageBox::Ok);
                okButton->setFixedSize(80,30);
                okButton->setStyleSheet("QPushButton { border: 1px solid #1E90FF; }");

                QMetaObject::invokeMethod(msgBox, "exec", Qt::QueuedConnection);
            }
            else{
                QMessageBox* msgBox = new QMessageBox(this);
                msgBox->setStyleSheet("QMessageBox { background-color: #FFFFFF; color: #000000; }");
                msgBox->setText("Error: Currency exchange failed!");
                msgBox->setWindowTitle("Currency");
                msgBox->setIcon(QMessageBox::Critical);

                QAbstractButton* okButton = msgBox->addButton(QMessageBox::Ok);
                okButton->setFixedSize(80,30);
                okButton->setStyleSheet("QPushButton { border: 1px solid #1E90FF; }");

                QMetaObject::invokeMethod(msgBox, "exec", Qt::QueuedConnection);

                qDebug() << "Error message: " << query.lastError().text();

            }
        }
        else{
            QMessageBox* msgBox = new QMessageBox(this);
            msgBox->setStyleSheet("QMessageBox { background-color: #FFFFFF; color: #000000; }");
            msgBox->setText("Error: Currency exchange failed!");
            msgBox->setWindowTitle("Currency");
            msgBox->setIcon(QMessageBox::Critical);

            QAbstractButton* okButton = msgBox->addButton(QMessageBox::Ok);
            okButton->setFixedSize(80,30);
            okButton->setStyleSheet("QPushButton { border: 1px solid #1E90FF; }");

            QMetaObject::invokeMethod(msgBox, "exec", Qt::QueuedConnection);

            qDebug() << "Error message: " << query.lastError().text();

        }
}
}
void curr::on_buy_clicked()//BUY
{
    QString sumnum= ui->lineEdit->text();
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("data.db");
    if (!db.open()) {
        qDebug() << "Error opening database: " << db.lastError();
    } else {
        QSqlQuery query(db);

        query.prepare("SELECT * FROM Users WHERE Login = :login");
        query.bindValue(":login", globalLogin);
        if(query.exec()&&query.first() && ui->listWidget->currentItem() && ui->listWidget_2->currentItem() && !sumnum.isEmpty()&&sumnum.toDouble()>0){

            QSqlQuery update(db);
            update.prepare("UPDATE Users SET Money =:mon,EUR =:eur,UAH=:uah,PLN=:pln,HistorySender = :hiss, HistoryPrice = :hisp WHERE Login = :login");
            update.bindValue(":login", globalLogin);
            if(ui->listWidget->currentItem()->text()=="USD"&& ui->listWidget_2->currentItem()->text() == "PLN"&&query.value("PLN").toDouble()>=sumnum.toDouble()){
                valut=dolarvzlot*sumnum.toDouble();
                update.bindValue(":mon",query.value("Money").toDouble()+valut);
                update.bindValue(":pln",query.value("PLN").toDouble()-valut);
            }
            else if(ui->listWidget->currentItem()->text()=="USD"&& ui->listWidget_2->currentItem()->text() == "UAH"&&query.value("UAH").toDouble()>=sumnum.toDouble()){
                valut=dolarvgrn*sumnum.toDouble();
                update.bindValue(":mon",query.value("Money").toDouble()+valut);
                update.bindValue(":uah",query.value("UAH").toDouble()-valut);
            }
            else if(ui->listWidget->currentItem()->text()=="USD"&& ui->listWidget_2->currentItem()->text() == "EUR"&&query.value("EUR").toDouble()>=sumnum.toDouble()){
                valut=dolarveuro*sumnum.toDouble();
                update.bindValue(":mon",query.value("Money").toDouble()+valut);
                update.bindValue(":eur",query.value("EUR").toDouble()-valut);
            }
            else if(ui->listWidget->currentItem()->text()=="PLN"&& ui->listWidget_2->currentItem()->text() == "USD"&&query.value("Money").toDouble()>=sumnum.toDouble()){
                valut=zlotvdolar*sumnum.toDouble();
                update.bindValue(":pln",query.value("PLN").toDouble()+valut);
                update.bindValue(":mon",query.value("Money").toDouble()-valut);
            }
            else if(ui->listWidget->currentItem()->text()=="PLN"&& ui->listWidget_2->currentItem()->text() == "UAH"&&query.value("UAH").toDouble()>=sumnum.toDouble()){
                valut=zlotvgrn*sumnum.toDouble();
                update.bindValue(":pln",query.value("PLN").toDouble()+valut);
                update.bindValue(":uah",query.value("UAH").toDouble()-valut);
            }
            else if(ui->listWidget->currentItem()->text()=="PLN"&& ui->listWidget_2->currentItem()->text() == "EUR"&&query.value("EUR").toDouble()>=sumnum.toDouble()){
                valut=zlotveuro*sumnum.toDouble();
                update.bindValue(":pln",query.value("PLN").toDouble()+valut);
                update.bindValue(":eur",query.value("EUR").toDouble()-valut);
            }
            else if(ui->listWidget->currentItem()->text()=="UAH"&& ui->listWidget_2->currentItem()->text() == "PLN"&&query.value("PLN").toDouble()>=sumnum.toDouble()){
                valut=grnvzlot*sumnum.toDouble();
                update.bindValue(":uah",query.value("UAH").toDouble()+valut);
                update.bindValue(":pln",query.value("PLN").toDouble()-valut);
            }
            else if(ui->listWidget->currentItem()->text()=="UAH"&& ui->listWidget_2->currentItem()->text() == "USD"&&query.value("Money").toDouble()>=sumnum.toDouble()){
                valut=grnvdolar*sumnum.toDouble();
                update.bindValue(":uah",query.value("UAH").toDouble()+valut);
                update.bindValue(":mon",query.value("Money").toDouble()-valut);
            }
            else if(ui->listWidget->currentItem()->text()=="UAH"&& ui->listWidget_2->currentItem()->text() == "EUR"&&query.value("EUR").toDouble()>=sumnum.toDouble()){
                valut=grnveuro*sumnum.toDouble();
                update.bindValue(":uah",query.value("UAH").toDouble()+valut);
                update.bindValue(":eur",query.value("EUR").toDouble()-valut);
            }
            else if(ui->listWidget->currentItem()->text()=="EUR"&& ui->listWidget_2->currentItem()->text() == "USD"&&query.value("Money").toDouble()>=sumnum.toDouble()){
                valut=eurovdolar*sumnum.toDouble();
                update.bindValue(":eur",query.value("EUR").toDouble()+valut);
                update.bindValue(":mon",query.value("Money").toDouble()-valut);
            }
            else if(ui->listWidget->currentItem()->text()=="EUR"&& ui->listWidget_2->currentItem()->text() == "UAH"&&query.value("UAH").toDouble()>=sumnum.toDouble()){
                valut=eurovgrn*sumnum.toDouble();
                update.bindValue(":eur",query.value("EUR").toDouble()+valut);
                update.bindValue(":uah",query.value("UAH").toDouble()-valut);
            }
            else if(ui->listWidget->currentItem()->text()=="EUR"&& ui->listWidget_2->currentItem()->text() == "PLN"&&query.value("PLN").toDouble()>=sumnum.toDouble()){
                valut=eurovzlot*sumnum.toDouble();
                update.bindValue(":eur",query.value("EUR").toDouble()+valut);
                update.bindValue(":pln",query.value("PLN").toDouble()-valut);
            }

            if(update.exec()){
                db.commit();
                sumnum.clear();
                ui->label_4->clear();
                QMessageBox* msgBox = new QMessageBox(this);
                msgBox->setStyleSheet("QMessageBox { background-color: #FFFFFF; color: #000000; }");
                msgBox->setText("Currency exchange confirmed!");
                msgBox->setWindowTitle("Currency");
                msgBox->setIcon(QMessageBox::Information);

                QAbstractButton* okButton = msgBox->addButton(QMessageBox::Ok);
                okButton->setFixedSize(80,30);
                okButton->setStyleSheet("QPushButton { border: 1px solid #1E90FF; }");

                QMetaObject::invokeMethod(msgBox, "exec", Qt::QueuedConnection);
            }
            else{
                QMessageBox* msgBox = new QMessageBox(this);
                msgBox->setStyleSheet("QMessageBox { background-color: #FFFFFF; color: #000000; }");
                msgBox->setText("Error: Currency exchange failed!");
                msgBox->setWindowTitle("Currency");
                msgBox->setIcon(QMessageBox::Critical);

                QAbstractButton* okButton = msgBox->addButton(QMessageBox::Ok);
                okButton->setFixedSize(80,30);
                okButton->setStyleSheet("QPushButton { border: 1px solid #1E90FF; }");

                QMetaObject::invokeMethod(msgBox, "exec", Qt::QueuedConnection);

                qDebug() << "Error message: " << query.lastError().text();

            }
        }
        else{
            QMessageBox* msgBox = new QMessageBox(this);
            msgBox->setStyleSheet("QMessageBox { background-color: #FFFFFF; color: #000000; }");
            msgBox->setText("Error: Currency exchange failed!");
            msgBox->setWindowTitle("Currency");
            msgBox->setIcon(QMessageBox::Critical);

            QAbstractButton* okButton = msgBox->addButton(QMessageBox::Ok);
            okButton->setFixedSize(80,30);
            okButton->setStyleSheet("QPushButton { border: 1px solid #1E90FF; }");

            QMetaObject::invokeMethod(msgBox, "exec", Qt::QueuedConnection);

            qDebug() << "Error message: " << query.lastError().text();

        }
}
}
void curr::updateValuts(){
    double sum =ui->lineEdit->text().toDouble();
    if(ui->listWidget->currentItem() && ui->listWidget_2->currentItem()){
       if(ui->listWidget->currentItem()->text() == "USD" && ui->listWidget_2->currentItem()->text() == "PLN"){
            valut=dolarvzlot *sum;
            ui->label_4->setText(QString::number(valut, 'f', 2) + "zł");
       }
       else if(ui->listWidget->currentItem()->text() == "USD" && ui->listWidget_2->currentItem()->text() == "UAH"){
           valut=dolarvgrn *sum;
           ui->label_4->setText(QString::number(valut, 'f', 2) + "₴");
       }
       else if(ui->listWidget->currentItem()->text() == "USD" && ui->listWidget_2->currentItem()->text() == "EUR"){
           valut=dolarveuro *sum;
           ui->label_4->setText(QString::number(valut, 'f', 2) + "€");
       }
       else if(ui->listWidget->currentItem()->text() == "UAH" && ui->listWidget_2->currentItem()->text() == "PLN"){
           valut=grnvzlot *sum;
           ui->label_4->setText(QString::number(valut, 'f', 2) + "zł");
       }
       else if(ui->listWidget->currentItem()->text() == "UAH" && ui->listWidget_2->currentItem()->text() == "EUR"){
           valut=grnveuro *sum;
           ui->label_4->setText(QString::number(valut, 'f', 2) + "€");
       }
       else if(ui->listWidget->currentItem()->text() == "UAH" && ui->listWidget_2->currentItem()->text() == "USD"){
           valut=grnvdolar *sum;
           ui->label_4->setText(QString::number(valut, 'f', 2) + "$");
       }
       else if(ui->listWidget->currentItem()->text() == "PLN" && ui->listWidget_2->currentItem()->text() == "UAH"){
           valut=zlotvgrn *sum;
           ui->label_4->setText(QString::number(valut, 'f', 2) + "₴");
       }
       else if(ui->listWidget->currentItem()->text() == "PLN" && ui->listWidget_2->currentItem()->text() == "USD"){
           valut=zlotvdolar *sum;
           ui->label_4->setText(QString::number(valut, 'f', 2) + "$");
       }
       else if(ui->listWidget->currentItem()->text() == "PLN" && ui->listWidget_2->currentItem()->text() == "EUR"){
           valut=zlotveuro *sum;
           ui->label_4->setText(QString::number(valut, 'f', 2) + "€");
       }
       else if(ui->listWidget->currentItem()->text() == "EUR" && ui->listWidget_2->currentItem()->text() == "UAH"){
           valut=eurovgrn *sum;
           ui->label_4->setText(QString::number(valut, 'f', 2) + "₴");
       }
       else if(ui->listWidget->currentItem()->text() == "EUR" && ui->listWidget_2->currentItem()->text() == "USD"){
           valut=eurovdolar *sum;
           ui->label_4->setText(QString::number(valut, 'f', 2) + "$");
       }
       else if(ui->listWidget->currentItem()->text() == "EUR" && ui->listWidget_2->currentItem()->text() == "PLN"){
           valut=eurovzlot *sum;
           ui->label_4->setText(QString::number(valut, 'f', 2) + "zł");
       }
       else{
           ui->label_4->setText("-");
       }

    }
    else{
         ui->label_4->setText("-");
    }
}

