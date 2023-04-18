#ifndef SEC_H
#define SEC_H

#include <QDialog>

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

private:
    Ui::sec *ui;
    QDialog *sign;
};

#endif // SEC_H
