#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPropertyAnimation>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPropertyAnimation *animation = new QPropertyAnimation(ui->pushButton, "geometry");
    animation->setDuration(3000);
    animation->setStartValue(ui->pushButton->geometry());
    animation->setEndValue(QRect(200,200,100, 50));

    QEasingCurve curve;
    curve.setType((QEasingCurve::OutBounce));
    animation->setEasingCurve(curve);
    animation->setLoopCount(3);
    animation->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

