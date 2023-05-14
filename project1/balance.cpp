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
            ui->label_7->setText(query.value("IDCARD").toString());


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

