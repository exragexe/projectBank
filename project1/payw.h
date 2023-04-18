#ifndef PAYW_H
#define PAYW_H

#include <QDialog>

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

private:
    Ui::payw *ui;
    QDialog *sign;
};

#endif // PAYW_H
