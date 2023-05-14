#include "registration.h"
#include "ui_registration.h"
#include "mainwindow.h"

registration::registration(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::registration)
{

    ui->setupUi(this);
    setWindowTitle("DYAD Bank");

    ui->login->setStyleSheet("background-color: #D9D9D9;");
    ui->pass->setStyleSheet("background-color: #D9D9D9;");
    setStyleSheet("background-color: transparent;");
    //DATA BASE
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("data.db");
    if (db.open()) {
        qDebug() << "Database connected!";
    } else {
        qDebug() << "Failed to connect to database!";
    }
    QSqlQuery query("SELECT * FROM users");
    query.exec("INSERT INTO Users(IDCARD, Login, Password, Money, CreditStatus, SumCredit, Moneybox, HistorySender, HistoryPrice,TypeBills , Term)");
    if (query.exec()) {
        qDebug() << "Table created";
    } else {
        qDebug() << "Table NOT created";
    }


}

registration::~registration()
{
    delete ui;
}

void registration::on_pushButton_clicked()
{
    QString login = ui->login->text();
    QString pass = ui->pass->text();

    QSqlQuery checkQuery(db);
    checkQuery.prepare("SELECT COUNT(*) FROM Users WHERE Login = :login");
    checkQuery.bindValue(":login", login);
    if (checkQuery.exec() && checkQuery.first() && checkQuery.value(0).toInt() > 0) {
        QMessageBox* msgBox = new QMessageBox(this);
        msgBox->setStyleSheet("QMessageBox { background-color: #FFFFFF; color: #000000; }");
        msgBox->setText("Error: Login already exists!");
        msgBox->setWindowTitle("Registration");
        msgBox->setIcon(QMessageBox::Critical);
        QAbstractButton* okButton = msgBox->addButton(QMessageBox::Ok);
        okButton->setFixedSize(80,30);
        okButton->setStyleSheet("QPushButton { border: 1px solid #1E90FF; }");
        QMetaObject::invokeMethod(msgBox, "exec", Qt::QueuedConnection);

    }
    else{

        QSqlQuery query(db);
        QString id="";
        QString iddb;

        query.exec("SELECT IDCARD FROM Users");
        while (query.next()) {
            iddb = query.value(0).toString();

        }



        while(true){
            if (id.isEmpty() || id==iddb || id.size()<16) {
                const int idLength = 16;
                const QString digits = "0123456789";
                for (int i = 0; i < idLength; i++) {
                    const int index = rand() % digits.length();
                    id += digits.at(index);
                }
            }
            else{
                break;
            }
        }


        query.prepare("INSERT INTO Users(IDCARD, Login, Password, Money, CreditStatus, SumCredit, Moneybox, HistorySender, HistoryPrice,TypeBills , Term,BlockCard, isAdmin) "
                          "VALUES (:id, :login, :pass, 0, 0, 0 , 0,  NULL,0,NULL,0,false,false)");
        query.bindValue(":id", id);
        query.bindValue(":login", login);
        query.bindValue(":pass", pass);
        if(query.exec()){
            ui->login->clear();
            ui->pass->clear();
            mainw= new MainWindow(this);
            mainw->show();
            this->hide();
            mainw->setFixedSize(700, 800);

        }
        else{
            QMessageBox* msgBox = new QMessageBox(this);
            msgBox->setStyleSheet("QMessageBox { background-color: #FFFFFF; color: #000000; }");
            msgBox->setText("Error: Registration failed!");
            msgBox->setWindowTitle("Registration");
            msgBox->setIcon(QMessageBox::Critical);

            QAbstractButton* okButton = msgBox->addButton(QMessageBox::Ok);
            okButton->setFixedSize(80,30);
            okButton->setStyleSheet("QPushButton { border: 1px solid #1E90FF; }");

            QMetaObject::invokeMethod(msgBox, "exec", Qt::QueuedConnection);

            qDebug() << "Error message: " << query.lastError().text();


        }
    }

}


void registration::on_pushButton_2_clicked()
{
    mainw= new MainWindow(this);
    mainw->show();
    this->hide();
    mainw->setFixedSize(700, 800);
}
