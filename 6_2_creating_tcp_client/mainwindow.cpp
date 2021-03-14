#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_connect_btn_clicked()
{
    if(!connectedToHost){
        socket = new QTcpSocket();
        connect(socket, &QTcpSocket::connected, this, &MainWindow::socketConnected);
        connect(socket, &QTcpSocket::readyRead, this, &MainWindow::socketReadyRead);
        connect(socket, &QTcpSocket::disconnected, this, &MainWindow::socketDisconnected);

        socket->connectToHost("127.0.0.1", 8001);
    }
    else{
        QString name = ui->name_edit->text();
        socket->write("<font color=\"Orange\">" + name.toUtf8() + "has left the chat room. <\font>");
        socket->disconnectFromHost();
        qDebug()<<"222";
    }
}

void MainWindow::on_send_btn_clicked()
{
    QString name = ui->name_edit->text();
    QString message = ui->message_edit->text();
    socket->write("<font color=\"Blue\">" + name.toUtf8() + "<\font>: " + message.toUtf8());

    ui->message_edit->clear();
}

void MainWindow::printMessage(QString message){
    ui->textBrowser->append(message);
}

void MainWindow::socketConnected(){
    qDebug()<<"Connected to server.";
    printMessage("<font color=\"Green\">Connected to server <\font>");
    QString name = ui->name_edit->text();
    socket->write("<font color=\"Purple\">" + name.toUtf8() + "has joined the chatroom.<\font>");
    ui->connect_btn->setText("Disconnect");
    connectedToHost = true;
}

void MainWindow::socketDisconnected(){
    qDebug()<<"Disconnected from server.";
    printMessage("<font color=\"Red\">Disconnected from server.<\font>");
    ui->connect_btn->setText("Connect");
    connectedToHost = false;
}

void MainWindow::socketReadyRead(){
    printMessage(socket->readAll());
}
