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
#include <QtWidgets/QListView>
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
    QLabel *label_5;
    QListView *listView;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;

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
        label_5 = new QLabel(balance);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(310, 520, 221, 61));
        QFont font;
        font.setFamilies({QString::fromUtf8("Bahnschrift SemiLight Condensed")});
        font.setPointSize(22);
        label_5->setFont(font);
        listView = new QListView(balance);
        listView->setObjectName("listView");
        listView->setGeometry(QRect(290, 630, 256, 221));
        listView->setFont(font);
        listView->setStyleSheet(QString::fromUtf8("background-color: rgb(166, 166, 166);"));
        listView->setFrameShadow(QFrame::Raised);
        listView->setLineWidth(1);
        listView->setAutoScroll(true);
        listView->setTabKeyNavigation(false);
        listView->setAlternatingRowColors(false);
        label_6 = new QLabel(balance);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(20, 330, 181, 81));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Bahnschrift Condensed")});
        font1.setPointSize(22);
        label_6->setFont(font1);
        label_6->setStyleSheet(QString::fromUtf8("background-image: url(:/resources/img/curr (1).png);\n"
""));
        label_7 = new QLabel(balance);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(34, 343, 151, 51));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Bahnschrift SemiLight Condensed")});
        font2.setPointSize(18);
        label_7->setFont(font2);
        label_7->setStyleSheet(QString::fromUtf8(""));
        label_8 = new QLabel(balance);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(300, 630, 231, 221));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Bahnschrift SemiLight Condensed")});
        font3.setPointSize(20);
        label_8->setFont(font3);
        label_8->raise();
        label->raise();
        label_2->raise();
        label_3->raise();
        label_4->raise();
        pushButton->raise();
        label_5->raise();
        label_6->raise();
        label_7->raise();
        listView->raise();

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
        label_5->setText(QString());
        label_6->setText(QString());
        label_7->setText(QString());
        label_8->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class balance: public Ui_balance {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BALANCE_H
