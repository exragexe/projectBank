#include "balance.h"
#include "registration.h"
#include "ui_balance.h"

class History
{
public:
    History(qint64 price, QString sender) : price(price), sender(sender) {}

    qint64 getPrice() const { return price; }
    QString getSender() const { return sender; }

private:
    qint64 price;
    QString sender;
};

balance::balance(QDialog *sign,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::balance),
    sign(sign)
{
    ui->setupUi(this);
    qint64 money;
    setWindowTitle("DYAD Bank");
    setStyleSheet("background-color: transparent;");
    QSqlQuery query(db);
    //balance
    query.prepare("SELECT Money FROM Users WHERE Login = :login");
    query.bindValue(":login", globalLogin);
    if (query.exec() && query.first()) {
        QString money = query.value(0).toString();
        ui->label_5->setText(money + " $");

    } else {

    }
    //history

    QList<History> historyList = {
        { 100, "Alice" },
        { 200, "Bob" },
        { 300, "Charlie" }
    };

    qint32 size = historyList.size();
    for(int i=0; i<size; i++){
        historyList.append(historyList[i]);
    }


    QStandardItemModel *model = new QStandardItemModel(parent);


    foreach (History history, historyList) {
        QStandardItem *item = new QStandardItem(QString("%1 %2").arg(history.getPrice()).arg(history.getSender()));
        model->appendRow(item);
    }


    QListView *listView = new QListView(parent);
    listView->setModel(model);




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

