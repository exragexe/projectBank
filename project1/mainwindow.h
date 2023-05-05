#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include "registration.h"
#include "sign.h"
#include "library.h"
#include "sec.h"



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    sign *window;
    registration *window2;
    QSqlDatabase db;
    QSqlQuery *query;
    sec *secw;

};
#endif // MAINWINDOW_H
