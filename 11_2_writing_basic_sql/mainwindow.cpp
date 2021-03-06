#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setUserName("jjy");
    db.setPassword("password");
    db.setDatabaseName("dbname");
    connected = db.open();

    if (connected){
        QSqlQuery query;
        if (query.exec("SELECT id, name, age, gender, married FROM employee")){
            while(query.next()){
                currentID = query.value(0).toInt();
                ui->line_name->setText(query.value(1).toString());
                ui->line_age->setText(query.value(2).toString());
                ui->comboBox->setCurrentIndex(query.value(3).toInt());
                ui->checkBox->setChecked(query.value(4).toBool());
            }
        }
        else{
            qDebug()<< query.lastError().text();
        }
    }
    else{
        qDebug() <<"Failed to connect to database";
    }
}

MainWindow::~MainWindow()
{
    db.close();
    delete ui;
}


void MainWindow::on_push_update_clicked()
{
    if (connected){
        if(currentID == 0){
            qDebug() <<"Nothing to update.";
        }
        else{
            QString id = QString::number(currentID);
            QString name = ui->line_name->text();
            QString age = ui->line_age->text();
            QString gender = QString::number(ui->comboBox->currentIndex());
            QString married = QString::number(ui->checkBox->isChecked());

            qDebug() <<"UPDATE employee SET name = '" +name+"', age = '"+ age+ "', gender = " + gender+", married= '"+married+" WHERE id = "+id;
            QSqlQuery query;
            if(query.exec("UPDATE employee SET name = '" + name + "', age = '" + age+ "', gender = " + gender + ", married = " + married + "WHERE id = "+ id)){
                qDebug() << "Update success";
            }
            else{
                qDebug() << query.lastError().text();
            }
        }
    }
    else{
        qDebug() <<"Failed to connect to database.";
    }
}

void MainWindow::on_push_insert_clicked()
{
    if (connected){
        QString name = ui->line_name->text();
        QString age = ui->line_age->text();
        QString gender = QString::number(ui->comboBox->currentIndex());
        QString married = QString::number(ui->checkBox->isChecked());
        qDebug() <<"INSERT INTO employee (name, age, gender, married) VALUES('" + name +"', '"+age+"', '"+gender+", "+ married+")";

        QSqlQuery query;
        if(query.exec("INSERT INTO employee (name, age, gender, married) VALUES ('" + name+"', "+age+"', '"+gender+"', '"+married+")")){
            currentID = query.lastInsertId().toInt();
            qDebug() <<"Insert success.";
        }
        else{
            qDebug() <<query.lastError().text();
        }
    }else{
        qDebug() <<"Failed to connect to database.";
    }
}

void MainWindow::on_push_delete_clicked()
{
    if (connected){
        if(currentID == 0){
            qDebug() <<"Nothing to delete.";
        }else{
            QString id = QString::number(currentID);
            qDebug()<<"DELETE FROM employee WHERE id = "+ id;

            QSqlQuery query;
            if(query.exec("DELETE FROM employee WHERE id = " + id)){
                currentID = 0;
                qDebug() <<"Delte success";
            }else{
                qDebug() <<query.lastError().text();
            }
        }
    }else{
        qDebug() <<"Failed to connect to database.";
    }
}
