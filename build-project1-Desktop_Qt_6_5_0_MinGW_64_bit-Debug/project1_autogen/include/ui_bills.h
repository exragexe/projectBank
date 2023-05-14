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
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_bills
{
public:
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton;
    QLabel *label_4;
    QListView *listView;
    QListView *listView_2;
    QListView *listView_3;
    QListView *listView_4;

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
        listView = new QListView(bills);
        listView->setObjectName("listView");
        listView->setGeometry(QRect(63, 470, 174, 281));
        QFont font;
        font.setFamilies({QString::fromUtf8("Bahnschrift SemiLight Condensed")});
        font.setPointSize(20);
        listView->setFont(font);
        listView->setStyleSheet(QString::fromUtf8("background-color: rgb(166, 166, 166);"));
        listView->setFrameShape(QFrame::StyledPanel);
        listView->setFrameShadow(QFrame::Sunken);
        listView->setLineWidth(1);
        listView->setMidLineWidth(0);
        listView_2 = new QListView(bills);
        listView_2->setObjectName("listView_2");
        listView_2->setGeometry(QRect(250, 470, 126, 281));
        listView_2->setFont(font);
        listView_2->setStyleSheet(QString::fromUtf8("background-color: rgb(166, 166, 166);"));
        listView_2->setFrameShape(QFrame::StyledPanel);
        listView_2->setFrameShadow(QFrame::Sunken);
        listView_2->setLineWidth(1);
        listView_2->setMidLineWidth(0);
        listView_3 = new QListView(bills);
        listView_3->setObjectName("listView_3");
        listView_3->setGeometry(QRect(388, 470, 124, 281));
        listView_3->setFont(font);
        listView_3->setStyleSheet(QString::fromUtf8("background-color: rgb(166, 166, 166);"));
        listView_3->setFrameShape(QFrame::StyledPanel);
        listView_3->setFrameShadow(QFrame::Sunken);
        listView_3->setLineWidth(1);
        listView_3->setMidLineWidth(0);
        listView_4 = new QListView(bills);
        listView_4->setObjectName("listView_4");
        listView_4->setGeometry(QRect(523, 470, 124, 281));
        listView_4->setFont(font);
        listView_4->setStyleSheet(QString::fromUtf8("background-color: rgb(166, 166, 166);"));
        listView_4->setFrameShape(QFrame::StyledPanel);
        listView_4->setFrameShadow(QFrame::Sunken);
        listView_4->setLineWidth(1);
        listView_4->setMidLineWidth(0);

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
