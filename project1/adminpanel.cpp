#include "adminpanel.h"
#include "ui_adminpanel.h"
#include "mainwindow.h"

adminpanel::adminpanel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adminpanel)
{
    ui->setupUi(this);
    setWindowTitle("DYAD Bank ADMIN PANEL");
    setStyleSheet("background-color: transparent;");
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");

    db.setDatabaseName("data.db");
    if (!db.open()) {
        qDebug() << "Error opening database: " << db.lastError();
    } else {
        QSqlTableModel *model = new QSqlTableModel(nullptr, db);
        model->setTable("Users");
        model->select();


        model->setHeaderData(0, Qt::Horizontal, "IDCARD");
        model->setHeaderData(1, Qt::Horizontal, "Login");
        model->setHeaderData(2, Qt::Horizontal, "Password");
        model->setHeaderData(3, Qt::Horizontal, "Money");
        model->setHeaderData(4, Qt::Horizontal, "CreditStatus");
        model->setHeaderData(5, Qt::Horizontal, "SumCredit");
        model->setHeaderData(6, Qt::Horizontal, "Moneybox");
        model->setHeaderData(7, Qt::Horizontal, "HistorySender");
        model->setHeaderData(8, Qt::Horizontal, "HistoryPrice");
        model->setHeaderData(9, Qt::Horizontal, "TypeBills");
        model->setHeaderData(10, Qt::Horizontal, "Term");
        model->setHeaderData(11, Qt::Horizontal, "BlockCard");

        ui->tableView->setModel(model);
        ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    }
}

adminpanel::~adminpanel()
{
    delete ui;
}

void adminpanel::on_pushButton_clicked()
{
    mainw = new MainWindow(this);
    mainw->show();
    this->hide();
    mainw->setFixedSize(700, 800);
}


void adminpanel::on_pushButton_2_clicked()//SAVE BUTTON
{
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    QSqlTableModel *model = qobject_cast<QSqlTableModel *>(ui->tableView->model());
    if (model) {
        model->submitAll();
    }
}


void adminpanel::on_pushButton_3_clicked()//EDIT BUTTON
{
    ui->tableView->setEditTriggers(QAbstractItemView::DoubleClicked);
}


void adminpanel::on_pushButton_4_clicked() //DELETE BUNNOT
{
    QModelIndexList selectedIndexes = ui->tableView->selectionModel()->selectedRows();
    if (selectedIndexes.count() == 1) {
        int row = selectedIndexes.at(0).row();
        QSqlTableModel *model = qobject_cast<QSqlTableModel *>(ui->tableView->model());
        if (model) {
            model->removeRow(row);
            ui->tableView->update();
        }
    }
}

