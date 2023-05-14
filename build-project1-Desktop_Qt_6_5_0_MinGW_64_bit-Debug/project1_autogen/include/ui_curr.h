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
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
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
    QLineEdit *lineEdit;
    QLabel *label_4;
    QListWidget *listWidget;
    QListWidget *listWidget_2;

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
        lineEdit = new QLineEdit(curr);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(240, 420, 401, 41));
        QFont font;
        font.setFamilies({QString::fromUtf8("Bahnschrift SemiLight Condensed")});
        font.setPointSize(26);
        lineEdit->setFont(font);
        lineEdit->setFrame(false);
        label_4 = new QLabel(curr);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(240, 525, 401, 31));
        label_4->setFont(font);
        listWidget = new QListWidget(curr);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(70, 398, 111, 61));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Bahnschrift SemiLight Condensed")});
        font1.setPointSize(48);
        listWidget->setFont(font1);
        listWidget->setFrameShape(QFrame::NoFrame);
        listWidget_2 = new QListWidget(curr);
        new QListWidgetItem(listWidget_2);
        new QListWidgetItem(listWidget_2);
        new QListWidgetItem(listWidget_2);
        new QListWidgetItem(listWidget_2);
        listWidget_2->setObjectName("listWidget_2");
        listWidget_2->setGeometry(QRect(70, 492, 111, 61));
        listWidget_2->setFont(font1);
        listWidget_2->setFrameShape(QFrame::NoFrame);
        label->raise();
        label_3->raise();
        label_5->raise();
        exi->raise();
        label_2->raise();
        buy->raise();
        sel->raise();
        pushButton_4->raise();
        lineEdit->raise();
        label_4->raise();
        listWidget->raise();
        listWidget_2->raise();

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
        lineEdit->setText(QString());
        label_4->setText(QCoreApplication::translate("curr", "<html><head/><body><p align=\"center\"><br/></p></body></html>", nullptr));

        const bool __sortingEnabled = listWidget->isSortingEnabled();
        listWidget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidget->item(0);
        ___qlistwidgetitem->setText(QCoreApplication::translate("curr", "USD", nullptr));
        QListWidgetItem *___qlistwidgetitem1 = listWidget->item(1);
        ___qlistwidgetitem1->setText(QCoreApplication::translate("curr", "PLN", nullptr));
        QListWidgetItem *___qlistwidgetitem2 = listWidget->item(2);
        ___qlistwidgetitem2->setText(QCoreApplication::translate("curr", "UAH", nullptr));
        QListWidgetItem *___qlistwidgetitem3 = listWidget->item(3);
        ___qlistwidgetitem3->setText(QCoreApplication::translate("curr", "EUR", nullptr));
        listWidget->setSortingEnabled(__sortingEnabled);


        const bool __sortingEnabled1 = listWidget_2->isSortingEnabled();
        listWidget_2->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem4 = listWidget_2->item(0);
        ___qlistwidgetitem4->setText(QCoreApplication::translate("curr", "USD", nullptr));
        QListWidgetItem *___qlistwidgetitem5 = listWidget_2->item(1);
        ___qlistwidgetitem5->setText(QCoreApplication::translate("curr", "PLN", nullptr));
        QListWidgetItem *___qlistwidgetitem6 = listWidget_2->item(2);
        ___qlistwidgetitem6->setText(QCoreApplication::translate("curr", "UAH", nullptr));
        QListWidgetItem *___qlistwidgetitem7 = listWidget_2->item(3);
        ___qlistwidgetitem7->setText(QCoreApplication::translate("curr", "EUR", nullptr));
        listWidget_2->setSortingEnabled(__sortingEnabled1);

    } // retranslateUi

};

namespace Ui {
    class curr: public Ui_curr {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CURR_H
