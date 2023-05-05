#ifndef SEC_H
#define SEC_H


#include "library.h"


namespace Ui {
class sec;
}

class sec : public QDialog
{
    Q_OBJECT

public:
    explicit sec(QDialog *sign, QWidget *parent = nullptr);
    ~sec();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::sec *ui;
    QDialog *sign;
    QMainWindow *mainw;
    QSqlDatabase db;
    QSqlQuery *query;


};

#endif // SEC_H
