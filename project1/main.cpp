#include "mainwindow.h"
#include <QApplication>
#include <QPixmap>
#include <QLabel>
#include <QFont>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;


    //sizewind
    w.setFixedSize(700, 800);
    w.setStyleSheet("QFormLayout { background-color: transparent;");

    //icon
    QIcon icon(":/resources/img/2.png");
    QApplication::setWindowIcon(icon);

    w.show();
    return a.exec();
}
