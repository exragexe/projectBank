#ifndef CREDIT_H
#define CREDIT_H

#include <QDialog>

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

private:
    Ui::credit *ui;
    QDialog *sign;
};

#endif // CREDIT_H
