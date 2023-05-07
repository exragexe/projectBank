/********************************************************************************
** Form generated from reading UI file 'credit.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREDIT_H
#define UI_CREDIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_credit
{
public:
    QLabel *label_6;
    QLabel *label_3;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QLabel *label_8;
    QListWidget *listWidget;

    void setupUi(QDialog *credit)
    {
        if (credit->objectName().isEmpty())
            credit->setObjectName("credit");
        credit->resize(700, 800);
        label_6 = new QLabel(credit);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(26, 486, 191, 81));
        label_6->setPixmap(QPixmap(QString::fromUtf8(":/resources/img/credi (2).png")));
        label_3 = new QLabel(credit);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(228, 353, 417, 211));
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/resources/img/Group 15.png")));
        lineEdit = new QLineEdit(credit);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(240, 310, 391, 41));
        QFont font;
        font.setFamilies({QString::fromUtf8("Bahnschrift SemiLight Condensed")});
        font.setPointSize(28);
        lineEdit->setFont(font);
        lineEdit->setFrame(false);
        label_2 = new QLabel(credit);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(160, 23, 455, 251));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/resources/img/crediti.png")));
        label_4 = new QLabel(credit);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(26, 286, 191, 81));
        label_4->setPixmap(QPixmap(QString::fromUtf8(":/resources/img/Group 14.png")));
        label_5 = new QLabel(credit);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(26, 386, 191, 81));
        label_5->setPixmap(QPixmap(QString::fromUtf8(":/resources/img/credi (3).png")));
        label = new QLabel(credit);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 700, 800));
        label->setPixmap(QPixmap(QString::fromUtf8(":/resources/img/Rectangle 1.png")));
        pushButton_2 = new QPushButton(credit);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(107, 621, 486, 136));
        pushButton_2->setStyleSheet(QString::fromUtf8("border-image: url(:/resources/img/credi (1).png);"));
        pushButton = new QPushButton(credit);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(600, 10, 97, 89));
        pushButton->setStyleSheet(QString::fromUtf8("border-image: url(:/resources/img/Group 10.png);"));
        label_8 = new QLabel(credit);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(240, 520, 391, 41));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Bahnschrift SemiCondensed")});
        font1.setPointSize(22);
        label_8->setFont(font1);
        listWidget = new QListWidget(credit);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(240, 415, 411, 31));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Bahnschrift SemiLight Condensed")});
        font2.setPointSize(22);
        listWidget->setFont(font2);
        listWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(46, 46, 46);"));
        listWidget->setFrameShadow(QFrame::Raised);
        label->raise();
        pushButton_2->raise();
        pushButton->raise();
        label_2->raise();
        label_3->raise();
        lineEdit->raise();
        label_6->raise();
        label_5->raise();
        label_4->raise();
        label_8->raise();
        listWidget->raise();

        retranslateUi(credit);

        QMetaObject::connectSlotsByName(credit);
    } // setupUi

    void retranslateUi(QDialog *credit)
    {
        credit->setWindowTitle(QCoreApplication::translate("credit", "Dialog", nullptr));
        label_6->setText(QString());
        label_3->setText(QString());
        lineEdit->setText(QString());
        label_2->setText(QString());
        label_4->setText(QString());
        label_5->setText(QString());
        label->setText(QString());
        pushButton_2->setText(QString());
        pushButton->setText(QString());
        label_8->setText(QString());

        const bool __sortingEnabled = listWidget->isSortingEnabled();
        listWidget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidget->item(0);
        ___qlistwidgetitem->setText(QCoreApplication::translate("credit", "1 month", nullptr));
        QListWidgetItem *___qlistwidgetitem1 = listWidget->item(1);
        ___qlistwidgetitem1->setText(QCoreApplication::translate("credit", "3 month", nullptr));
        QListWidgetItem *___qlistwidgetitem2 = listWidget->item(2);
        ___qlistwidgetitem2->setText(QCoreApplication::translate("credit", "6 month", nullptr));
        QListWidgetItem *___qlistwidgetitem3 = listWidget->item(3);
        ___qlistwidgetitem3->setText(QCoreApplication::translate("credit", "12 month", nullptr));
        listWidget->setSortingEnabled(__sortingEnabled);

    } // retranslateUi

};

namespace Ui {
    class credit: public Ui_credit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREDIT_H
