#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPropertyAnimation>
#include <QSequentialAnimationGroup>
#include <QParallelAnimationGroup>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPropertyAnimation *animation1 = new QPropertyAnimation(ui->pushButton, "geometry");
    animation1->setDuration(3000);
    animation1->setStartValue(ui->pushButton->geometry());
    animation1->setEndValue(QRect(50,200,100,50));

    QPropertyAnimation *animation2 = new QPropertyAnimation(ui->pushButton_2, "geometry");
    animation2->setDuration(3000);
    animation2->setStartValue(ui->pushButton_2->geometry());
    animation2->setEndValue(QRect(150,200,100,50));

    QPropertyAnimation *animation3 = new QPropertyAnimation(ui->pushButton_3,"geometry");
    animation3->setDuration(3000);
    animation3->setStartValue(ui->pushButton_3->geometry());
    animation3->setEndValue(QRect(250,200,100,50));

    QEasingCurve curve;
    curve.setType(QEasingCurve::OutBounce);
    curve.setAmplitude(1.00);
    curve.setOvershoot(1.70);
    curve.setPeriod(0.30);

    animation1->setEasingCurve(curve);
    animation2->setEasingCurve(curve);
    animation3->setEasingCurve(curve);

    QSequentialAnimationGroup *group = new QSequentialAnimationGroup;
    QParallelAnimationGroup *group2 = new QParallelAnimationGroup;
    QSequentialAnimationGroup *group_all = new QSequentialAnimationGroup;

    group->addAnimation(animation1);
    group->addAnimation(animation2);
    group2->addAnimation(animation3);

    group_all->addAnimation(group2);
    group_all->addAnimation(group);

    group_all->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

