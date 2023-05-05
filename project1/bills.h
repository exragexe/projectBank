#ifndef BILLS_H
#define BILLS_H


#include "library.h"

namespace Ui {
class bills;
}

class bills : public QDialog
{
    Q_OBJECT

public:
    explicit bills(QDialog *sign,QWidget *parent = nullptr);
    ~bills();

private slots:
    void on_pushButton_clicked();

private:
    Ui::bills *ui;
    QDialog *sign;
};

#endif // BILLS_H
