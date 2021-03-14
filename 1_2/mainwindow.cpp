#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pushButton->setProperty("pagematches",true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_tabWidget_currentChanged(int index)
{
    ui->pushButton->setProperty("pagematches", false);
    ui->pushButton_2->setProperty("pagematches", false);
    ui->pushButton_3->setProperty("pagematches", false);

    if (index == 0)
        ui->pushButton->setProperty("pagematches", true);
    else if (index == 1)
        ui->pushButton_2->setProperty("pagematches", true);
    else
        ui->pushButton_3->setProperty("pagematches", true);

    ui->pushButton->style()->polish(ui->pushButton);
    ui->pushButton_2->style()->polish(ui->pushButton_2);
    ui->pushButton_3->style()->polish(ui->pushButton_3);
}
