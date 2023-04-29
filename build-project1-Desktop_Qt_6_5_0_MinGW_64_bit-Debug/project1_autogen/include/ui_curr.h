/********************************************************************************
** Form generated from reading UI file 'curr.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CURR_H
#define UI_CURR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_curr
{
public:
    QLabel *label_2;
    QLabel *label_5;
    QLabel *label_3;
    QPushButton *exi;
    QPushButton *buy;
    QLabel *label;
    QPushButton *sel;
    QPushButton *pushButton_4;

    void setupUi(QDialog *curr)
    {
        if (curr->objectName().isEmpty())
            curr->setObjectName("curr");
        curr->resize(700, 800);
        label_2 = new QLabel(curr);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(172, 17, 384, 311));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/resources/img/curr (5).png")));
        label_5 = new QLabel(curr);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(36, 390, 181, 181));
        label_5->setPixmap(QPixmap(QString::fromUtf8(":/resources/img/curr (1).png")));
        label_3 = new QLabel(curr);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(228, 459, 417, 111));
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/resources/img/curr (6).png")));
        exi = new QPushButton(curr);
        exi->setObjectName("exi");
        exi->setGeometry(QRect(600, 10, 97, 89));
        exi->setStyleSheet(QString::fromUtf8("border-image: url(:/resources/img/Group 10.png);"));
        buy = new QPushButton(curr);
        buy->setObjectName("buy");
        buy->setGeometry(QRect(249, 635, 281, 81));
        buy->setStyleSheet(QString::fromUtf8("border-image: url(:/resources/img/curr (3).png);"));
        label = new QLabel(curr);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 700, 800));
        label->setPixmap(QPixmap(QString::fromUtf8(":/resources/img/Rectangle 1.png")));
        sel = new QPushButton(curr);
        sel->setObjectName("sel");
        sel->setEnabled(true);
        sel->setGeometry(QRect(249, 635, 281, 81));
        sel->setStyleSheet(QString::fromUtf8("border-image: url(:/resources/img/curr (4).png);"));
        sel->setAutoDefault(true);
        pushButton_4 = new QPushButton(curr);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(162, 637, 71, 71));
        pushButton_4->setStyleSheet(QString::fromUtf8("border-image: url(:/resources/img/curr (2).png);"));
        label->raise();
        label_3->raise();
        label_5->raise();
        exi->raise();
        label_2->raise();
        buy->raise();
        sel->raise();
        pushButton_4->raise();

        retranslateUi(curr);

        exi->setDefault(false);


        QMetaObject::connectSlotsByName(curr);
    } // setupUi

    void retranslateUi(QDialog *curr)
    {
        curr->setWindowTitle(QCoreApplication::translate("curr", "Dialog", nullptr));
        label_2->setText(QString());
        label_5->setText(QString());
        label_3->setText(QString());
        exi->setText(QString());
        buy->setText(QString());
        label->setText(QString());
        sel->setText(QString());
        pushButton_4->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class curr: public Ui_curr {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CURR_H
