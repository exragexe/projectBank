/********************************************************************************
** Form generated from reading UI file 'registration.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTRATION_H
#define UI_REGISTRATION_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_registration
{
public:
    QLabel *label;
    QLineEdit *login;
    QLineEdit *pass;
    QPushButton *pushButton;
    QLabel *label_19;
    QLabel *label_20;
    QLabel *label_21;
    QLabel *label_22;
    QLabel *label_3;
    QPushButton *pushButton_2;

    void setupUi(QDialog *registration)
    {
        if (registration->objectName().isEmpty())
            registration->setObjectName("registration");
        registration->resize(700, 800);
        label = new QLabel(registration);
        label->setObjectName("label");
        label->setGeometry(QRect(-340, 10, 1291, 881));
        label->setPixmap(QPixmap(QString::fromUtf8(":/resources/img/map.png")));
        login = new QLineEdit(registration);
        login->setObjectName("login");
        login->setEnabled(true);
        login->setGeometry(QRect(225, 534, 351, 30));
        QFont font;
        font.setFamilies({QString::fromUtf8("Bahnschrift SemiLight Condensed")});
        font.setPointSize(18);
        login->setFont(font);
        login->setFrame(false);
        pass = new QLineEdit(registration);
        pass->setObjectName("pass");
        pass->setGeometry(QRect(225, 613, 351, 30));
        pass->setFont(font);
        pass->setFrame(false);
        pushButton = new QPushButton(registration);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(290, 680, 201, 71));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Lucida Console")});
        font1.setPointSize(20);
        pushButton->setFont(font1);
        pushButton->setStyleSheet(QString::fromUtf8("border-image: url(:/resources/img/Group 11 (2).png);"));
        QIcon icon;
        QString iconThemeName = QString::fromUtf8("accessories-text-editor");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon = QIcon::fromTheme(iconThemeName);
        } else {
            icon.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        pushButton->setIcon(icon);
        pushButton->setCheckable(false);
        pushButton->setAutoRepeat(false);
        pushButton->setAutoExclusive(false);
        pushButton->setAutoDefault(false);
        pushButton->setFlat(false);
        label_19 = new QLabel(registration);
        label_19->setObjectName("label_19");
        label_19->setGeometry(QRect(130, 510, 81, 81));
        label_19->setPixmap(QPixmap(QString::fromUtf8(":/resources/img/Group 43.png")));
        label_20 = new QLabel(registration);
        label_20->setObjectName("label_20");
        label_20->setGeometry(QRect(130, 590, 81, 81));
        label_20->setPixmap(QPixmap(QString::fromUtf8(":/resources/img/Group 39 (1).png")));
        label_21 = new QLabel(registration);
        label_21->setObjectName("label_21");
        label_21->setGeometry(QRect(211, 521, 508, 65));
        label_21->setPixmap(QPixmap(QString::fromUtf8(":/resources/img/5.png")));
        label_22 = new QLabel(registration);
        label_22->setObjectName("label_22");
        label_22->setGeometry(QRect(211, 563, 508, 136));
        label_22->setPixmap(QPixmap(QString::fromUtf8(":/resources/img/5.png")));
        label_3 = new QLabel(registration);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(180, 100, 351, 341));
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/resources/img/bank1.png")));
        pushButton_2 = new QPushButton(registration);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(210, 680, 71, 71));
        pushButton_2->setFont(font1);
        pushButton_2->setStyleSheet(QString::fromUtf8("border-image: url(:/resources/img/Group 45.png);"));
        pushButton_2->setIcon(icon);
        pushButton_2->setCheckable(false);
        pushButton_2->setAutoRepeat(false);
        pushButton_2->setAutoExclusive(false);
        pushButton_2->setAutoDefault(false);
        pushButton_2->setFlat(false);
        label->raise();
        pushButton->raise();
        label_19->raise();
        label_20->raise();
        label_22->raise();
        label_21->raise();
        login->raise();
        pass->raise();
        label_3->raise();
        pushButton_2->raise();

        retranslateUi(registration);

        pushButton->setDefault(false);
        pushButton_2->setDefault(false);


        QMetaObject::connectSlotsByName(registration);
    } // setupUi

    void retranslateUi(QDialog *registration)
    {
        registration->setWindowTitle(QCoreApplication::translate("registration", "Dialog", nullptr));
        label->setText(QString());
        pushButton->setText(QString());
        label_19->setText(QString());
        label_20->setText(QString());
        label_21->setText(QString());
        label_22->setText(QString());
        label_3->setText(QString());
        pushButton_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class registration: public Ui_registration {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTRATION_H
