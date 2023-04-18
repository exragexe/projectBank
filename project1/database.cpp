//#include "database.h"
//#include "ui_database.h"
//
//database::database(QWidget *parent) :
//    QDialog(parent),
//    ui(new Ui::database)
//{
//    ui->setupUi(this);
//    db = QSqlDatabase::addDatabase("QSQLITE");
//    db.setDatabaseName("./data.db");
//    if (db.open()){
//        qDebug("open");
//    }
//    else{
//        qDebug("not open");
//    }
//
//}
//
//database::~database()
//{
//    delete ui;
//}
//
