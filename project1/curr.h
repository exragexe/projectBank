#ifndef CURR_H
#define CURR_H


#include "library.h"

namespace Ui {
class curr;
}

class curr : public QDialog
{
    Q_OBJECT

public:
    explicit curr(QDialog *sign, QWidget *parent = nullptr);
    ~curr();

private slots:
    void on_exi_clicked();

    void on_pushButton_4_clicked();

    void on_sel_clicked();

    void on_buy_clicked();
    void updateValuts();

private:
    Ui::curr *ui;
    QDialog *sign;
    double valut;
    double dolarvgrn=37.11;
    double eurovgrn=40.31;
    double zlotvgrn = 8.94;
    double grnvdolar=0.027;
    double eurovdolar=1.09;
    double zlotvdolar = 0.24;
    double grnvzlot=0.11;
    double dolarvzlot =4.15;
    double eurovzlot= 4.51;
    double grnveuro=0.025;
    double dolarveuro=0.92;
    double zlotveuro= 0.22;
};

#endif // CURR_H
