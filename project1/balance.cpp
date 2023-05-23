#include "balance.h"
#include "registration.h"
#include "ui_balance.h"



balance::balance(QDialog *sign,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::balance),
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

        //balance
        query.prepare("SELECT * FROM Users WHERE Login = :login");
        query.bindValue(":login", globalLogin);

        if (query.exec() && query.first()) {
            qDebug ()<< query.value("HistoryPrice").toString();

             qDebug ()<<query.value("HistorySender").toString();
            ui->label_7->setText(query.value("IDCARD").toString());
            //========BALANCE
            QString moneyUSD = query.value("Money").toString();
            QString moneyEUR = query.value("EUR").toString();
            QString moneyUAH = query.value("UAH").toString();
            QString moneyPLN = query.value("PLN").toString();
            QStandardItemModel *model1 = new QStandardItemModel(this);
            double usdValue = moneyUSD.toDouble();
            double eurValue = moneyEUR.toDouble();
            double uahValue = moneyUAH.toDouble();
            double plnValue = moneyPLN.toDouble();
            moneyUSD = QString::number(usdValue, 'f', 2);
            moneyEUR = QString::number(eurValue, 'f', 2);
            moneyUAH = QString::number(uahValue, 'f', 2);
            moneyPLN = QString::number(plnValue, 'f', 2);
            QStandardItem *item1 = new QStandardItem(moneyUSD + "$");
            QStandardItem *item2 = new QStandardItem(moneyEUR + "€");
            QStandardItem *item3 = new QStandardItem(moneyUAH + "₴");
            QStandardItem *item4 = new QStandardItem(moneyPLN + "zł");
            model1->appendColumn(QList<QStandardItem*>() << item1 << item2 << item3 << item4);
            ui->listView_2->setModel(model1);
            ui->listView_2->setEditTriggers(QAbstractItemView::NoEditTriggers);
            //=========HISTORY
            QString hisp = query.value("HistoryPrice").toString();
            QString hiss = query.value("HistorySender").toString();
            QStringList historyPrices = hisp.split(",");
            QStringList historySenders = hiss.split(",");
            QStandardItemModel *model = new QStandardItemModel(this);

            for (int i = 0; i < historyPrices.size(); i++) {
                QStandardItem *item = new QStandardItem(historyPrices[i] +"$ " + historySenders[i]);
                model->appendRow(item);
            }

            ui->listView->setModel(model);
            ui->listView->setEditTriggers(QAbstractItemView::NoEditTriggers);
            //=========BLOCKCARD
            QDateTime currentDateTime = QDateTime::currentDateTime();
            QString dateString = currentDateTime.toString("yyyy.MM.dd");
            QSqlQuery querycredit(db);

            if(query.value("CreditStatus").toString()=="true" && dateString == query.value("Term").toString() ){
                QSqlQuery updatequery(db);
                updatequery.prepare("UPDATE Users SET BlockCard = :block WHERE Login =:login" );
                updatequery.bindValue(":login", globalLogin);
                updatequery.bindValue(":block", true);
                if(updatequery.exec() && updatequery.first()){
                    qDebug()<<"card block";
                }
                else{
                    qDebug()<<"card not block. ERORE";
                }
            }
        } else {
            qDebug() << "Error executing query: " << query.lastError();
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


