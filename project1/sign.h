#ifndef SIGN_H
#define SIGN_H

#include <QDialog>
#include "balance.h"
#include "payw.h"
#include "credit.h"
#include "bills.h"
#include "curr.h"
#include "mbox.h"
#include "sec.h"


namespace Ui {
class sign;
}

class sign : public QDialog
{
    Q_OBJECT

public:
    explicit sign(QWidget *parent = nullptr);
    ~sign();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_13_clicked();

private:
    Ui::sign *ui;
    balance *balanceWidget;
    payw *payWidget;
    credit *creditw;
    bills *billsw;
    curr *currw;
    mbox *mboxw;
    sec *secw;

};

#endif // SIGN_H
