#ifndef SEC_H
#define SEC_H

#include <QDialog>
#include <QtSql/QSqlDatabase>
#include <QSqlQuery>
#include <QMainWindow>
#include <QMessageBox>
#include <QString>
#include <QInputDialog>

extern QString globalLogin;
extern QString globalPassword;
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

private:
    Ui::sec *ui;
    QDialog *sign;
    QMainWindow *mainw;
    QSqlDatabase db;
    QSqlQuery *query;


};

#endif // SEC_H
