#ifndef ADMINPANEL_H
#define ADMINPANEL_H

#include "library.h"

namespace Ui {
class adminpanel;
}

class adminpanel : public QDialog
{
    Q_OBJECT

public:
    explicit adminpanel(QWidget *parent = nullptr);
    ~adminpanel();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::adminpanel *ui;
    QMainWindow *mainw;
};

#endif // ADMINPANEL_H
