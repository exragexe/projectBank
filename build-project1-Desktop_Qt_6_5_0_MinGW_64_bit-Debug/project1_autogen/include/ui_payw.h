/********************************************************************************
** Form generated from reading UI file 'payw.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAYW_H
#define UI_PAYW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_payw
{
public:
    QLabel *label_6;
    QLabel *label_3;
    QLineEdit *payee;
    QLineEdit *sum;
    QLabel *label_2;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label;
    QPushButton *pushButton_2;
    QPushButton *exi;
    QListWidget *listWidget;

    void setupUi(QDialog *payw)
    {
        if (payw->objectName().isEmpty())
            payw->setObjectName("payw");
        payw->resize(700, 800);
        label_6 = new QLabel(payw);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(26, 486, 191, 81));
        label_6->setPixmap(QPixmap(QString::fromUtf8(":/resources/img/Group 14.png")));
        label_3 = new QLabel(payw);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(228, 353, 417, 211));
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/resources/img/Group 15.png")));
        payee = new QLineEdit(payw);
        payee->setObjectName("payee");
        payee->setGeometry(QRect(240, 410, 391, 41));
        QFont font;
        font.setFamilies({QString::fromUtf8("Corbel")});
        font.setPointSize(28);
        payee->setFont(font);
        payee->setFrame(false);
        sum = new QLineEdit(payw);
        sum->setObjectName("sum");
        sum->setGeometry(QRect(240, 510, 391, 41));
        sum->setFont(font);
        sum->setFrame(false);
        label_2 = new QLabel(payw);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(115, 23, 455, 251));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/resources/img/pay12.png")));
        label_4 = new QLabel(payw);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(26, 286, 191, 81));
        label_4->setPixmap(QPixmap(QString::fromUtf8(":/resources/img/Group 12.png")));
        label_5 = new QLabel(payw);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(26, 386, 191, 81));
        label_5->setPixmap(QPixmap(QString::fromUtf8(":/resources/img/Group 13 (1).png")));
        label = new QLabel(payw);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 700, 800));
        label->setPixmap(QPixmap(QString::fromUtf8(":/resources/img/Rectangle 1.png")));
        pushButton_2 = new QPushButton(payw);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(107, 621, 486, 136));
        pushButton_2->setStyleSheet(QString::fromUtf8("border-image: url(:/resources/img/Group 16.png);"));
        exi = new QPushButton(payw);
        exi->setObjectName("exi");
        exi->setGeometry(QRect(600, 10, 97, 89));
        exi->setStyleSheet(QString::fromUtf8("border-image: url(:/resources/img/Group 10.png);"));
        listWidget = new QListWidget(payw);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(240, 310, 401, 41));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Corbel")});
        font1.setPointSize(24);
        listWidget->setFont(font1);
        listWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(46, 46, 46);"));
        listWidget->setFrameShadow(QFrame::Raised);
        label->raise();
        pushButton_2->raise();
        label_3->raise();
        label_2->raise();
        label_4->raise();
        label_6->raise();
        label_5->raise();
        payee->raise();
        sum->raise();
        exi->raise();
        listWidget->raise();

        retranslateUi(payw);

        exi->setDefault(false);


        QMetaObject::connectSlotsByName(payw);
    } // setupUi

    void retranslateUi(QDialog *payw)
    {
        payw->setWindowTitle(QCoreApplication::translate("payw", "Dialog", nullptr));
        label_6->setText(QString());
        label_3->setText(QString());
        payee->setText(QString());
        sum->setText(QString());
        label_2->setText(QString());
        label_4->setText(QString());
        label_5->setText(QString());
        label->setText(QString());
        pushButton_2->setText(QString());
        exi->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class payw: public Ui_payw {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAYW_H
