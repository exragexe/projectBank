/********************************************************************************
** Form generated from reading UI file 'sec.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEC_H
#define UI_SEC_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_sec
{
public:
    QLabel *label_3;
    QLineEdit *lineEdit_2;
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label_2;
    QLineEdit *lineEdit_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_7;
    QPushButton *pushButton_3;

    void setupUi(QDialog *sec)
    {
        if (sec->objectName().isEmpty())
            sec->setObjectName("sec");
        sec->resize(700, 800);
        label_3 = new QLabel(sec);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(284, 542, 378, 94));
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/resources/img/sec (6).png")));
        lineEdit_2 = new QLineEdit(sec);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(290, 395, 371, 41));
        QFont font;
        font.setFamilies({QString::fromUtf8("Corbel")});
        font.setPointSize(28);
        lineEdit_2->setFont(font);
        lineEdit_2->setFrame(false);
        label = new QLabel(sec);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 700, 800));
        label->setPixmap(QPixmap(QString::fromUtf8(":/resources/img/Rectangle 1.png")));
        pushButton = new QPushButton(sec);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(600, 10, 97, 89));
        pushButton->setStyleSheet(QString::fromUtf8("border-image: url(:/resources/img/Group 10.png);"));
        pushButton_2 = new QPushButton(sec);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(33, 622, 302, 81));
        pushButton_2->setStyleSheet(QString::fromUtf8("border-image: url(:/resources/img/sec (3).png);"));
        label_2 = new QLabel(sec);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(192, 31, 345, 281));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/resources/img/Group 36.png")));
        lineEdit_3 = new QLineEdit(sec);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(290, 497, 371, 41));
        lineEdit_3->setFont(font);
        lineEdit_3->setFrame(false);
        label_4 = new QLabel(sec);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(21, 364, 262, 91));
        label_4->setPixmap(QPixmap(QString::fromUtf8(":/resources/img/sec (5).png")));
        label_5 = new QLabel(sec);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(21, 468, 257, 91));
        label_5->setPixmap(QPixmap(QString::fromUtf8(":/resources/img/sec (4).png")));
        label_7 = new QLabel(sec);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(284, 440, 378, 94));
        label_7->setPixmap(QPixmap(QString::fromUtf8(":/resources/img/sec (6).png")));
        pushButton_3 = new QPushButton(sec);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(361, 622, 317, 81));
        pushButton_3->setStyleSheet(QString::fromUtf8("border-image: url(:/resources/img/sec (2).png);"));
        label->raise();
        label_3->raise();
        pushButton->raise();
        pushButton_2->raise();
        label_2->raise();
        label_4->raise();
        label_5->raise();
        lineEdit_2->raise();
        label_7->raise();
        pushButton_3->raise();
        lineEdit_3->raise();

        retranslateUi(sec);

        QMetaObject::connectSlotsByName(sec);
    } // setupUi

    void retranslateUi(QDialog *sec)
    {
        sec->setWindowTitle(QCoreApplication::translate("sec", "Dialog", nullptr));
        label_3->setText(QString());
        lineEdit_2->setText(QString());
        label->setText(QString());
        pushButton->setText(QString());
        pushButton_2->setText(QString());
        label_2->setText(QString());
        lineEdit_3->setText(QString());
        label_4->setText(QString());
        label_5->setText(QString());
        label_7->setText(QString());
        pushButton_3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class sec: public Ui_sec {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEC_H
