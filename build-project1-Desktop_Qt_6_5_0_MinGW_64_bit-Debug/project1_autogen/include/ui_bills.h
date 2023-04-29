/********************************************************************************
** Form generated from reading UI file 'bills.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BILLS_H
#define UI_BILLS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_bills
{
public:
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton;
    QLabel *label_4;

    void setupUi(QDialog *bills)
    {
        if (bills->objectName().isEmpty())
            bills->setObjectName("bills");
        bills->resize(700, 800);
        label = new QLabel(bills);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 700, 800));
        label->setPixmap(QPixmap(QString::fromUtf8(":/resources/img/Rectangle 1.png")));
        label_2 = new QLabel(bills);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(135, 20, 457, 321));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/resources/img/Group 19.png")));
        pushButton = new QPushButton(bills);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(600, 10, 97, 89));
        pushButton->setStyleSheet(QString::fromUtf8("border-image: url(:/resources/img/Group 10.png);"));
        label_4 = new QLabel(bills);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(45, 374, 621, 401));
        label_4->setPixmap(QPixmap(QString::fromUtf8(":/resources/img/Group 20.png")));

        retranslateUi(bills);

        QMetaObject::connectSlotsByName(bills);
    } // setupUi

    void retranslateUi(QDialog *bills)
    {
        bills->setWindowTitle(QCoreApplication::translate("bills", "Dialog", nullptr));
        label->setText(QString());
        label_2->setText(QString());
        pushButton->setText(QString());
        label_4->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class bills: public Ui_bills {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BILLS_H
