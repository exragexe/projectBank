#ifndef PAYW_H
#define PAYW_H


#include "library.h"

namespace Ui {
class payw;
}

class payw : public QDialog
{
    Q_OBJECT

public:
    explicit payw(QDialog *sign,QWidget *parent = nullptr);
    ~payw();

private slots:

    void exi();

    void on_pushButton_2_clicked();

private:
    Ui::payw *ui;
    QDialog *sign;
    QString idcard;
    qint64 money;
    QString idsender;
};

#endif // PAYW_H
