/********************************************************************************
** Form generated from reading UI file 'mbox.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MBOX_H
#define UI_MBOX_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_mbox
{
public:
    QLabel *label_6;
    QPushButton *pushButton_2;
    QPushButton *exi;
    QLabel *label_4;
    QLabel *label_2;
    QLabel *label_5;
    QLabel *label;
    QLabel *label_7;
    QPushButton *pushButton_3;
    QLineEdit *card;
    QLabel *label_3;

    void setupUi(QDialog *mbox)
    {
        if (mbox->objectName().isEmpty())
            mbox->setObjectName("mbox");
        mbox->resize(700, 800);
        label_6 = new QLabel(mbox);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(36, 486, 191, 91));
        label_6->setPixmap(QPixmap(QString::fromUtf8(":/resources/img/Group 33.png")));
        pushButton_2 = new QPushButton(mbox);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(363, 634, 281, 81));
        pushButton_2->setStyleSheet(QString::fromUtf8("border-image: url(:/resources/img/mb (3).png);"));
        exi = new QPushButton(mbox);
        exi->setObjectName("exi");
        exi->setGeometry(QRect(600, 10, 97, 89));
        exi->setStyleSheet(QString::fromUtf8("border-image: url(:/resources/img/Group 10.png);"));
        label_4 = new QLabel(mbox);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(228, 459, 417, 101));
        label_4->setPixmap(QPixmap(QString::fromUtf8(":/resources/img/mb.png")));
        label_2 = new QLabel(mbox);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(154, 12, 417, 281));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/resources/img/mb (1).png")));
        label_5 = new QLabel(mbox);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(36, 385, 176, 91));
        label_5->setPixmap(QPixmap(QString::fromUtf8(":/resources/img/Group 33 (1).png")));
        label = new QLabel(mbox);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 700, 800));
        label->setPixmap(QPixmap(QString::fromUtf8(":/resources/img/Rectangle 1.png")));
        label_7 = new QLabel(mbox);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(228, 561, 417, 94));
        label_7->setPixmap(QPixmap(QString::fromUtf8(":/resources/img/mb.png")));
        pushButton_3 = new QPushButton(mbox);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(62, 634, 281, 81));
        pushButton_3->setStyleSheet(QString::fromUtf8("border-image: url(:/resources/img/mb (4).png);"));
        card = new QLineEdit(mbox);
        card->setObjectName("card");
        card->setGeometry(QRect(240, 518, 391, 41));
        QFont font;
        font.setFamilies({QString::fromUtf8("Bahnschrift SemiLight Condensed")});
        font.setPointSize(28);
        card->setFont(font);
        card->setFrame(false);
        label_3 = new QLabel(mbox);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(240, 423, 391, 41));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Bahnschrift SemiLight Condensed")});
        font1.setPointSize(22);
        label_3->setFont(font1);
        label->raise();
        label_6->raise();
        pushButton_2->raise();
        exi->raise();
        label_4->raise();
        label_2->raise();
        label_5->raise();
        label_7->raise();
        pushButton_3->raise();
        card->raise();
        label_3->raise();

        retranslateUi(mbox);

        exi->setDefault(false);


        QMetaObject::connectSlotsByName(mbox);
    } // setupUi

    void retranslateUi(QDialog *mbox)
    {
        mbox->setWindowTitle(QCoreApplication::translate("mbox", "Dialog", nullptr));
        label_6->setText(QString());
        pushButton_2->setText(QString());
        exi->setText(QString());
        label_4->setText(QString());
        label_2->setText(QString());
        label_5->setText(QString());
        label->setText(QString());
        label_7->setText(QString());
        pushButton_3->setText(QString());
        card->setText(QString());
        label_3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class mbox: public Ui_mbox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MBOX_H
