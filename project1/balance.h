#ifndef BALANCE_H
#define BALANCE_H

#include <QDialog>
#include <QtSql/QSqlDatabase>
#include <QSqlQuery>
#include <QString>
#include <QMessageBox>
#include <QListView>
#include <QStandardItemModel>
#include <QSqlQueryModel>




namespace Ui {
class balance;
}

class balance : public QDialog
{
    Q_OBJECT

public:
    explicit balance(QDialog *sign, QWidget *parent = nullptr);
    ~balance();

private slots:


    void on_pushButton_clicked();

private:
    Ui::balance *ui;
    QDialog *sign;
    QSqlDatabase db;
    QSqlQuery *query;

};

#endif
