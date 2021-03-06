#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QPainter>

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

void MainWindow::paintEvent(QPaintEvent* event){
    QImage image;
    image.load(":/images/checker.jpg");
    QImage image2;
    image2.load(":/images/tux.png");
    QImage image3;
    image3.load(":/images/butterfly.png");

    QPainter painter(this);

    painter.setCompositionMode(QPainter::CompositionMode_Difference);
    painter.drawImage(QPoint(10, 10), image);

    painter.setCompositionMode((QPainter::CompositionMode_Overlay));
    painter.drawImage(QPoint(10, 10), image2);

    painter.setCompositionMode(QPainter::CompositionMode_Xor);
    painter.drawImage(QPoint(300, 10), image);

    painter.setCompositionMode(QPainter::CompositionMode_SoftLight);
    painter.drawImage(QPoint(300, 40), image3);


}

