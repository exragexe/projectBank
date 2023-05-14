#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("DYAD Bank");
    ui->label_3->setStyleSheet("background-color: transparent;");
    //.............
    QLabel labellg;
    QFont font("Microsoft Yi Baiti", 24);
    font.setPixelSize(2);
    labellg.setFont(font);
    labellg.setStyleSheet("QLabel { border: 3px dashed blue; }");
    ui->login->setStyleSheet("background-color: #D9D9D9;");
    ui->pass->setStyleSheet("background-color: #D9D9D9;");
    ui->pass->setEchoMode(QLineEdit::Password);
    //......
    setStyleSheet("background-color: transparent;");
    //DATABASE
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("data.db");

    if (!db.open()) {
        qDebug() << "Failed to open database connection: " << db.lastError().text();
        return;
    }

    query = new QSqlQuery(db);
    QString createTable = "CREATE TABLE IF NOT EXISTS Users(IDCARD TEXT, Login TEXT, Password TEXT, Money DOUBLE, CreditStatus BOOL, SumCredit DOUBLE, Moneybox DOUBLE, HistorySender TEXT, HistoryPrice DOUBLE,TypeBills TEXT, Term INT, BlockCard BOOL, isAdmin BOOL, LastUpdated TEXT);";

    if (query->exec(createTable)) {
        qDebug() << "Table created";
    } else {
        qDebug() << "Table NOT created: " << query->lastError().text();
    }
    //if (query->exec("ALTER TABLE Users ADD COLUMN LastUpdated TEXT")) {
    //    qDebug() << "Column TypeBills added";
    //} else {
    //    qDebug() << "Column TypeBills NOT added: " << query->lastError().text();
    //}



}

MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::on_pushButton_2_clicked()
{
    QString login = ui->login->text();
    QString pass = ui->pass->text();

    if (db.open()) {
        QSqlQuery query;
        query.prepare("SELECT * FROM Users WHERE Login = :login AND Password = :pass");
        query.bindValue(":login", login);
        query.bindValue(":pass", pass);
        //qDebug()<<query.value("CreditStatus").toBool();

        if (query.exec() && query.next() && !login.isEmpty() && !pass.isEmpty()) {
            if(query.value("isAdmin").toBool()){
                hide();
                admin = new adminpanel(this);
                admin->setFixedSize(1100, 700);
                admin->show();
                db.close();
            }
            else{
                globalLogin = query.value(1).toString();
                globalPassword = query.value(2).toString();
                hide();

                window = new sign(this);
                window->setFixedSize(700, 800);
                window->show();

                db.close();
            }
        } else{
            QMessageBox* msgBox = new QMessageBox(this);
            msgBox->setStyleSheet("QMessageBox { background-color: #FFFFFF; color: #000000; }");
            msgBox->setText("Error: Not correct login or password!");
            msgBox->setWindowTitle("Login failed");
            msgBox->setIcon(QMessageBox::Critical);
            QAbstractButton* okButton = msgBox->addButton(QMessageBox::Ok);
            okButton->setFixedSize(80,30);
            okButton->setStyleSheet("QPushButton { border: 1px solid #1E90FF; }");
            QMetaObject::invokeMethod(msgBox, "exec", Qt::QueuedConnection);

        }
    } else {
        qDebug() << "Failed to open database connection";
    }
}



void MainWindow::on_pushButton_clicked()
{
    hide();
    window2 = new registration(this);
    window2->setFixedSize(700, 800);
    window2->show();
}
