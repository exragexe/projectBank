#ifndef REGISTRATION_H
#define REGISTRATION_H

#include <QDialog>
#include <QMainWindow>
#include <QtSql/QSqlDatabase>
#include <QSqlQuery>

namespace Ui {
class registration;
}

class registration : public QDialog
{
    Q_OBJECT

public:
    explicit registration(QWidget *parent = nullptr);
    ~registration();

private slots:
    void on_pushButton_clicked();

private:
    Ui::registration *ui;
    QMainWindow *mainw;
    QSqlDatabase db;
    QSqlQuery *query;


};

#endif // REGISTRATION_H
