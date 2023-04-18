#ifndef CURR_H
#define CURR_H

#include <QDialog>

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

private:
    Ui::curr *ui;
    QDialog *sign;
};

#endif // CURR_H
