#ifndef MBOX_H
#define MBOX_H

#include <QDialog>

namespace Ui {
class mbox;
}

class mbox : public QDialog
{
    Q_OBJECT

public:
    explicit mbox(QDialog *sign,QWidget *parent = nullptr);
    ~mbox();

private slots:

    void on_exi_clicked();

private:
    Ui::mbox *ui;
    QDialog *sign;
};

#endif // MBOX_H
