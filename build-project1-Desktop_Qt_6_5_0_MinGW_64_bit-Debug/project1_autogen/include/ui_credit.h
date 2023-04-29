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
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_credit
{
public:
    QLabel *label_6;
    QLabel *label_3;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label;
    QPushButton *pushButton_2;
    QPushButton *pushButton;

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
        lineEdit_2 = new QLineEdit(credit);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(240, 410, 391, 41));
        QFont font;
        font.setFamilies({QString::fromUtf8("Corbel")});
        font.setPointSize(28);
        lineEdit_2->setFont(font);
        lineEdit_2->setFrame(false);
        lineEdit_3 = new QLineEdit(credit);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(240, 510, 391, 41));
        lineEdit_3->setFont(font);
        lineEdit_3->setFrame(false);
        lineEdit = new QLineEdit(credit);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(240, 310, 391, 41));
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
        label->raise();
        pushButton_2->raise();
        pushButton->raise();
        label_2->raise();
        label_3->raise();
        lineEdit_3->raise();
        lineEdit->raise();
        lineEdit_2->raise();
        label_6->raise();
        label_5->raise();
        label_4->raise();

        retranslateUi(credit);

        QMetaObject::connectSlotsByName(credit);
    } // setupUi

    void retranslateUi(QDialog *credit)
    {
        credit->setWindowTitle(QCoreApplication::translate("credit", "Dialog", nullptr));
        label_6->setText(QString());
        label_3->setText(QString());
        lineEdit_2->setText(QString());
        lineEdit_3->setText(QString());
        lineEdit->setText(QString());
        label_2->setText(QString());
        label_4->setText(QString());
        label_5->setText(QString());
        label->setText(QString());
        pushButton_2->setText(QString());
        pushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class credit: public Ui_credit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREDIT_H
