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

           //ДОРОБИТИ //QStringList history;
           //ДОРОБИТИ //QString hisp = query.value("HistoryPrice").toString();
           //ДОРОБИТИ //QString hiss = query.value("HistorySender").toString();
           //ДОРОБИТИ //QStringList historyPrices = hisp.split(",");
           //ДОРОБИТИ //QStringList historySenders = hiss.split(",");
           //ДОРОБИТИ ////QStringListModel * modal = new QStringListModel();

           //ДОРОБИТИ //QStandardItemModel *model = new QStandardItemModel(this);
           //ДОРОБИТИ //QAbstractItemModel *currentModel = ui->listView->model();
           //ДОРОБИТИ //if (currentModel) {
           //ДОРОБИТИ //    for (int i = 0; i < currentModel->rowCount(); i++) {
           //ДОРОБИТИ //        QList<QStandardItem *> items;
           //ДОРОБИТИ //        items << new QStandardItem(currentModel->index(i, 0).data().toString());
           //ДОРОБИТИ //        items << new QStandardItem(currentModel->index(i, 1).data().toString());
           //ДОРОБИТИ //        model->appendRow(items);
           //ДОРОБИТИ //    }
           //ДОРОБИТИ //}
           //ДОРОБИТИ //QStandardItem *priceItem = new QStandardItem(query.value("HistoryPrice").toString());
           //ДОРОБИТИ //QStandardItem *senderItem = new QStandardItem(query.value("HistorySender").toString());
           //ДОРОБИТИ //model->appendRow({priceItem, senderItem});
           //ДОРОБИТИ //ui->listView->setModel(model);


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

