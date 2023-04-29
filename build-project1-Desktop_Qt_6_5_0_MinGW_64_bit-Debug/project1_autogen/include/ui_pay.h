/********************************************************************************
** Form generated from reading UI file 'pay.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAY_H
#define UI_PAY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName("Dialog");
        Dialog->resize(700, 800);
        label = new QLabel(Dialog);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 700, 800));
        label->setPixmap(QPixmap(QString::fromUtf8(":/resources/img/Rectangle 1.png")));
        label_2 = new QLabel(Dialog);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(115, 23, 455, 251));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/resources/img/pay12.png")));
        pushButton = new QPushButton(Dialog);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(600, 10, 97, 89));
        pushButton->setStyleSheet(QString::fromUtf8("border-image: url(:/resources/img/Group 10.png);"));
        pushButton_2 = new QPushButton(Dialog);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(107, 621, 486, 136));
        pushButton_2->setStyleSheet(QString::fromUtf8("border-image: url(:/resources/img/Group 16.png);"));
        label_3 = new QLabel(Dialog);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(228, 353, 417, 211));
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/resources/img/Group 15.png")));
        label_4 = new QLabel(Dialog);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(26, 286, 191, 81));
        label_4->setPixmap(QPixmap(QString::fromUtf8(":/resources/img/Group 12.png")));
        label_5 = new QLabel(Dialog);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(26, 386, 191, 81));
        label_5->setPixmap(QPixmap(QString::fromUtf8(":/resources/img/Group 13 (1).png")));
        label_6 = new QLabel(Dialog);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(26, 486, 191, 81));
        label_6->setPixmap(QPixmap(QString::fromUtf8(":/resources/img/Group 14.png")));
        lineEdit = new QLineEdit(Dialog);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(240, 310, 391, 41));
        QFont font;
        font.setFamilies({QString::fromUtf8("Corbel")});
        font.setPointSize(28);
        lineEdit->setFont(font);
        lineEdit_2 = new QLineEdit(Dialog);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(240, 410, 391, 41));
        lineEdit_2->setFont(font);
        lineEdit_3 = new QLineEdit(Dialog);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(240, 510, 391, 41));
        lineEdit_3->setFont(font);

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        label->setText(QString());
        label_2->setText(QString());
        pushButton->setText(QString());
        pushButton_2->setText(QString());
        label_3->setText(QString());
        label_4->setText(QString());
        label_5->setText(QString());
        label_6->setText(QString());
        lineEdit->setText(QString());
        lineEdit_2->setText(QString());
        lineEdit_3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAY_H
