/********************************************************************************
** Form generated from reading UI file 'adminpanel.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINPANEL_H
#define UI_ADMINPANEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_adminpanel
{
public:
    QPushButton *pushButton;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QTableView *tableView;

    void setupUi(QDialog *adminpanel)
    {
        if (adminpanel->objectName().isEmpty())
            adminpanel->setObjectName("adminpanel");
        adminpanel->resize(1100, 700);
        pushButton = new QPushButton(adminpanel);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(980, 10, 111, 99));
        pushButton->setStyleSheet(QString::fromUtf8("background-image: url(:/resources/img/Group 46.png);"));
        label = new QLabel(adminpanel);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 1100, 700));
        label->setPixmap(QPixmap(QString::fromUtf8(":/resources/img/image 3.png")));
        label_2 = new QLabel(adminpanel);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(322, -120, 461, 461));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/resources/img/Group 51.png")));
        label_3 = new QLabel(adminpanel);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(25, 126, 1061, 561));
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/resources/img/Rectangle 35.png")));
        label_4 = new QLabel(adminpanel);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(280, -120, 534, 461));
        label_4->setPixmap(QPixmap(QString::fromUtf8(":/resources/img/Group 54.png")));
        label_5 = new QLabel(adminpanel);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(43, 142, 1021, 441));
        label_5->setPixmap(QPixmap(QString::fromUtf8(":/resources/img/Group 47.png")));
        pushButton_2 = new QPushButton(adminpanel);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(54, 585, 211, 79));
        pushButton_2->setStyleSheet(QString::fromUtf8("background-image: url(:/resources/img/Group 50.png);"));
        pushButton_3 = new QPushButton(adminpanel);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(439, 585, 211, 79));
        pushButton_3->setStyleSheet(QString::fromUtf8("background-image: url(:/resources/img/Group 49.png);"));
        pushButton_4 = new QPushButton(adminpanel);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(845, 585, 211, 79));
        pushButton_4->setStyleSheet(QString::fromUtf8("background-image: url(:/resources/img/Group 48.png);"));
        tableView = new QTableView(adminpanel);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(60, 160, 991, 391));
        QFont font;
        font.setFamilies({QString::fromUtf8("Bahnschrift SemiLight Condensed")});
        font.setPointSize(22);
        tableView->setFont(font);
        label->raise();
        pushButton->raise();
        label_2->raise();
        label_4->raise();
        label_3->raise();
        label_5->raise();
        pushButton_2->raise();
        pushButton_3->raise();
        pushButton_4->raise();
        tableView->raise();

        retranslateUi(adminpanel);

        QMetaObject::connectSlotsByName(adminpanel);
    } // setupUi

    void retranslateUi(QDialog *adminpanel)
    {
        adminpanel->setWindowTitle(QCoreApplication::translate("adminpanel", "Dialog", nullptr));
        pushButton->setText(QString());
        label->setText(QString());
        label_2->setText(QString());
        label_3->setText(QString());
        label_4->setText(QString());
        label_5->setText(QString());
        pushButton_2->setText(QString());
        pushButton_3->setText(QString());
        pushButton_4->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class adminpanel: public Ui_adminpanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINPANEL_H
