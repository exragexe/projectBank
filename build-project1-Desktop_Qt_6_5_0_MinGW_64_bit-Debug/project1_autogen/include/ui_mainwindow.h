/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label_3;
    QLabel *label;
    QLineEdit *login;
    QLineEdit *pass;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_2;
    QLabel *label_6;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(700, 800);
        MainWindow->setToolButtonStyle(Qt::ToolButtonIconOnly);
        MainWindow->setAnimated(true);
        MainWindow->setDocumentMode(false);
        MainWindow->setDockNestingEnabled(false);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(360, 680, 201, 71));
        QFont font;
        font.setFamilies({QString::fromUtf8("Lucida Console")});
        font.setPointSize(20);
        pushButton->setFont(font);
        pushButton->setStyleSheet(QString::fromUtf8("border-image: url(:/resources/img/Group 11 (1).png);"));
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
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(140, 680, 181, 71));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Lucida Console")});
        font1.setPointSize(20);
        font1.setBold(false);
        pushButton_2->setFont(font1);
        pushButton_2->setStyleSheet(QString::fromUtf8("border-image: url(:/resources/img/Group 11.png);"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(180, 100, 351, 341));
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/resources/img/bank1.png")));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(-340, 10, 1291, 881));
        label->setPixmap(QPixmap(QString::fromUtf8(":/resources/img/map.png")));
        login = new QLineEdit(centralwidget);
        login->setObjectName("login");
        login->setEnabled(true);
        login->setGeometry(QRect(215, 525, 351, 41));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Corbel")});
        font2.setPointSize(22);
        login->setFont(font2);
        login->setFrame(false);
        pass = new QLineEdit(centralwidget);
        pass->setObjectName("pass");
        pass->setGeometry(QRect(215, 605, 351, 41));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Lucida Console")});
        font3.setPointSize(18);
        pass->setFont(font3);
        pass->setFrame(false);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(118, 510, 81, 81));
        label_4->setStyleSheet(QString::fromUtf8(""));
        label_4->setPixmap(QPixmap(QString::fromUtf8(":/resources/img/Group 43.png")));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(118, 590, 81, 81));
        label_5->setStyleSheet(QString::fromUtf8(""));
        label_5->setPixmap(QPixmap(QString::fromUtf8(":/resources/img/Group 39 (1).png")));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(200, 514, 573, 72));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/resources/img/5.png")));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(200, 555, 573, 150));
        label_6->setPixmap(QPixmap(QString::fromUtf8(":/resources/img/5.png")));
        MainWindow->setCentralWidget(centralwidget);
        label->raise();
        label_3->raise();
        pushButton->raise();
        pushButton_2->raise();
        label_4->raise();
        label_5->raise();
        label_2->raise();
        label_6->raise();
        login->raise();
        pass->raise();

        retranslateUi(MainWindow);

        pushButton->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton->setText(QString());
        pushButton_2->setText(QString());
        label_3->setText(QString());
        label->setText(QString());
        label_4->setText(QString());
        label_5->setText(QString());
        label_2->setText(QString());
        label_6->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
