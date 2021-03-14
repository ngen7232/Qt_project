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

void MainWindow::paintEvent(QPaintEvent *event)
{
    QImage image;
    image.load(":/image/tux.png");

    QPainter imagePainter(this);
    imagePainter.begin(this);
    imagePainter.drawImage(QPoint(100,150), image);
    imagePainter.end();
}
