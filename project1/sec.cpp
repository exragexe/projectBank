#include "sec.h"
#include "mainwindow.h"
#include "ui_sec.h"
QString globalLogin;
QString globalPassword;
sec::sec(QDialog *sign,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sec),
    sign(sign)


{
    ui->setupUi(this);
    //globalLogin = login;
    setWindowTitle("DYAD Bank");
    setStyleSheet("background-color: transparent;");
    //DATABASE

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("data.db");
    if (db.open()) {
        qDebug() << "Database connected!";
    } else {
        qDebug() << "Failed to connect to database!";
    }
    QSqlQuery query("SELECT * FROM users");
    query.exec("INSERT INTO Users(Id, Login, Password, Money, CreditStatus, SumCredit, Moneybox)");
    if (query.exec()) {
        qDebug() << "Table created";
    } else {
        qDebug() << "Table NOT created";
    }

}

sec::~sec()
{
    delete ui;
}

void sec::on_pushButton_clicked()
{
    this->hide();
    sign->show();
}


void sec::on_pushButton_3_clicked()
{
    QSqlQuery query;

    query.prepare("SELECT Password FROM Users WHERE Login = :login");
    query.bindValue(":login", globalLogin);
    if (query.exec() && query.first()) {
        QString password = query.value(0).toString();
        QInputDialog passwordDialog;
        passwordDialog.setWindowTitle("Enter Password");
        passwordDialog.setLabelText("Password:");
        passwordDialog.setTextEchoMode(QLineEdit::Password);

    if (passwordDialog.exec() == QDialog::Accepted) {
        QString enteredPassword = passwordDialog.textValue();
    if (enteredPassword == password) {
        QString currentUserLogin = globalLogin;
        QSqlQuery deleteQuery;
        deleteQuery.prepare("DELETE FROM Users WHERE Login = :login");
        deleteQuery.bindValue(":login", currentUserLogin);
    if (deleteQuery.exec()) {
        qDebug() << "User " << currentUserLogin << " deleted";
        mainw = new MainWindow(this);
        mainw->show();
        this->hide();
        mainw->setFixedSize(700, 800);
}
    else {
        qDebug() << "Failed to delete user " << currentUserLogin;
        QMessageBox* msgBox = new QMessageBox(this);
        msgBox->setStyleSheet("QMessageBox { background-color: #FFFFFF; color: #000000; }");
        msgBox->setText("Error: Delete account failed!");
        msgBox->setWindowTitle("Security");
        msgBox->setIcon(QMessageBox::Critical);
        QAbstractButton* okButton = msgBox->addButton(QMessageBox::Ok);
        okButton->setFixedSize(80,30);
        okButton->setStyleSheet("QPushButton { border: 1px solid #1E90FF; }");
        QMetaObject::invokeMethod(msgBox, "exec", Qt::QueuedConnection);

}
}   else {
        QMessageBox* msgBox = new QMessageBox(this);
        msgBox->setStyleSheet("QMessageBox { background-color: #FFFFFF; color: #000000; }");
        msgBox->setText("Error: Incorrect password!");
        msgBox->setWindowTitle("Security");
        msgBox->setIcon(QMessageBox::Critical);
        QAbstractButton* okButton = msgBox->addButton(QMessageBox::Ok);
        okButton->setFixedSize(80,30);
        okButton->setStyleSheet("QPushButton { border: 1px solid #1E90FF; }");
        QMetaObject::invokeMethod(msgBox, "exec", Qt::QueuedConnection);

    }
}
}   else {
        QMessageBox* msgBox = new QMessageBox(this);
        msgBox->setStyleSheet("QMessageBox { background-color: #FFFFFF; color: #000000; }");
        msgBox->setText("Error: Failed to retrieve password from database!");
        msgBox->setWindowTitle("Security");
        msgBox->setIcon(QMessageBox::Critical);
        QAbstractButton* okButton = msgBox->addButton(QMessageBox::Ok);
        okButton->setFixedSize(80,30);
        okButton->setStyleSheet("QPushButton { border: 1px solid #1E90FF; }");
        QMetaObject::invokeMethod(msgBox, "exec", Qt::QueuedConnection);

}
}

void sec::on_pushButton_2_clicked()
{

    QString oldpas = ui->lineEdit_2->text();
    QString newpas = ui->lineEdit_3->text();

    QSqlQuery checkQuery(db);
    checkQuery.prepare("SELECT Password FROM Users WHERE Login = :login");

    checkQuery.bindValue(":login", globalLogin);
    if (checkQuery.exec() && checkQuery.first()) {
        QString passwordFromDb = checkQuery.value(0).toString();
        if (passwordFromDb == oldpas) {
            QSqlQuery updateQuery(db);
            updateQuery.prepare("UPDATE Users SET Password = :pass WHERE Login = :login");
            updateQuery.bindValue(":pass", newpas);
            updateQuery.bindValue(":login", globalLogin);
            if (updateQuery.exec()) {
                ui->lineEdit_2->clear();
                 ui->lineEdit_3->clear();
                 QMessageBox* msgBox = new QMessageBox(this);
                 msgBox->setStyleSheet("QMessageBox { background-color: #FFFFFF; color: #000000; }");
                 msgBox->setText("Password updated successfully!");
                 msgBox->setWindowTitle("Security");
                 msgBox->setIcon(QMessageBox::Information);
                 QAbstractButton* okButton = msgBox->addButton(QMessageBox::Ok);
                 okButton->setFixedSize(80,30);
                 okButton->setStyleSheet("QPushButton { border: 1px solid #1E90FF; }");
                 QMetaObject::invokeMethod(msgBox, "exec", Qt::QueuedConnection);

            } else {
                QMessageBox* msgBox = new QMessageBox(this);
                msgBox->setStyleSheet("QMessageBox { background-color: #FFFFFF; color: #000000; }");
                msgBox->setText("Error: Password update failed!");
                msgBox->setWindowTitle("Security");
                msgBox->setIcon(QMessageBox::Critical);
                QAbstractButton* okButton = msgBox->addButton(QMessageBox::Ok);
                okButton->setFixedSize(80,30);
                okButton->setStyleSheet("QPushButton { border: 1px solid #1E90FF; }");
                QMetaObject::invokeMethod(msgBox, "exec", Qt::QueuedConnection);

            }
        } else {
            QMessageBox* msgBox = new QMessageBox(this);
            msgBox->setStyleSheet("QMessageBox { background-color: #FFFFFF; color: #000000; }");
            msgBox->setText("Error: Incorrect old password!");
            msgBox->setWindowTitle("Security");
            msgBox->setIcon(QMessageBox::Critical);
            QAbstractButton* okButton = msgBox->addButton(QMessageBox::Ok);
            okButton->setFixedSize(80,30);
            okButton->setStyleSheet("QPushButton { border: 1px solid #1E90FF; }");
            QMetaObject::invokeMethod(msgBox, "exec", Qt::QueuedConnection);

        }
    } else {
        QMessageBox* msgBox = new QMessageBox(this);
        msgBox->setStyleSheet("QMessageBox { background-color: #FFFFFF; color: #000000; }");
        msgBox->setText("Error: Failed to get password from database!");
        msgBox->setWindowTitle("Security");
        msgBox->setIcon(QMessageBox::Critical);
        QAbstractButton* okButton = msgBox->addButton(QMessageBox::Ok);
        okButton->setFixedSize(80,30);
        okButton->setStyleSheet("QPushButton { border: 1px solid #1E90FF; }");
        QMetaObject::invokeMethod(msgBox, "exec", Qt::QueuedConnection);

    }


}
