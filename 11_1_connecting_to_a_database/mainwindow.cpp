#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setUserName("jjy");
    db.setPassword("passwd");
    db.setDatabaseName("employee");

    if (db.open()){
        QSqlQuery query;
        if (query.exec("SELECT name, age, gender, married FROM employee")){
            while( query.next()){
                qDebug() <<query.value(0) << query.value(1) <<query.value(2)<<query.value(3);
                ui->label_name->setText(query.value(0).toString());
                ui->label_age->setText(query.value(1).toString());
                ui->checkBox_married->setChecked(query.value(3).toBool());
            }
        }
        else{
            qDebug() <<query.lastError().text() <<"#$$$$$$$$$$$$$$$$$$$";

        }
    }
    else{
        qDebug() <<"Failed to connect to database.";
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

