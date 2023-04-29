#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("DYAD Bank");
    //setStyleSheet("background-color: white;");


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
        qDebug() << "Failed to open database connection";
        return;
    }
    query = new QSqlQuery(db);
    QString createTable = "CREATE TABLE Users(Id INT, Login TEXT, Password TEXT, Money INT,/"
                          " CreditStatus BOOL, SumCredit INT, Moneybox INT)";
    if (query->exec(createTable)) {
        qDebug() << "Table created";
    } else {
        qDebug() << "Table NOT created";
    }
}

MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::on_pushButton_2_clicked()
{
    QString login = ui->login->text();
    QString pass = ui->pass->text();

    QSqlQuery query(db);
    query.prepare("SELECT * FROM Users WHERE Login = :login AND Password = :pass");
    query.bindValue(":login", login);
    query.bindValue(":pass", pass);

    if (query.exec() && query.next() && !login.isEmpty() && !pass.isEmpty()) {
        globalLogin = query.value(1).toString();
        globalPassword = query.value(2).toString();
        //secw = new sec(login,this);
        hide();
        window = new sign(this);
        window->setFixedSize(700, 800);
        window->show();
    } else{

        QMessageBox messageBox;

        messageBox.critical(this, "Error", "Not correct login or password!");

     }

}


void MainWindow::on_pushButton_clicked()
{
    hide();
    window2 = new registration(this);
    window2->setFixedSize(700, 800);
    window2->show();
}

