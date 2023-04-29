/********************************************************************************
** Form generated from reading UI file 'balance.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BALANCE_H
#define UI_BALANCE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_balance
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *pushButton;

    void setupUi(QDialog *balance)
    {
        if (balance->objectName().isEmpty())
            balance->setObjectName("balance");
        balance->resize(690, 932);
        label = new QLabel(balance);
        label->setObjectName("label");
        label->setGeometry(QRect(-5, 0, 741, 166));
        label->setPixmap(QPixmap(QString::fromUtf8(":/resources/img/firbal (2).png")));
        label_2 = new QLabel(balance);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(-10, 330, 731, 622));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/resources/img/firbal (1).png")));
        label_3 = new QLabel(balance);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(-20, 30, 749, 411));
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/resources/img/cardupd 1 (1).png")));
        label_4 = new QLabel(balance);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(80, 470, 531, 451));
        label_4->setPixmap(QPixmap(QString::fromUtf8(":/resources/img/Group 13.png")));
        pushButton = new QPushButton(balance);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(580, 10, 101, 91));
        pushButton->setStyleSheet(QString::fromUtf8("border-image: url(:/resources/img/Group 10.png);"));

        retranslateUi(balance);

        QMetaObject::connectSlotsByName(balance);
    } // setupUi

    void retranslateUi(QDialog *balance)
    {
        balance->setWindowTitle(QCoreApplication::translate("balance", "Dialog", nullptr));
        label->setText(QString());
        label_2->setText(QString());
        label_3->setText(QString());
        label_4->setText(QString());
        pushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class balance: public Ui_balance {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BALANCE_H
