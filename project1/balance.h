#ifndef BALANCE_H
#define BALANCE_H

#include "library.h"


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
    qint64 money;

};

#endif
