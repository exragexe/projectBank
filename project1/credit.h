#ifndef CREDIT_H
#define CREDIT_H


#include "library.h"

namespace Ui {
class credit;
}

class credit : public QDialog
{
    Q_OBJECT

public:
    explicit credit(QDialog *sign, QWidget *parent = nullptr);
    ~credit();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();
    void updatePercent();


private:
    Ui::credit *ui;
    QDialog *sign;
    double procentforsend ;
};

#endif // CREDIT_H
