#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPen>
#include <QPainterPath>
#include <QPainter>

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


void MainWindow::on_action_Save_as_SVG_triggered()
{
    QString filePath = QFileDialog::getSaveFileName(this, "save SVG", "C:\\Users\\JJY\\Desktop", "SVG files (*.svg)");
    if (filePath == "")
        return;
    QSvgGenerator generator;
    generator.setFileName(filePath);
    generator.setSize(QSize(this->width(), this->height()));
    generator.setViewBox(QRect(0, 0, this->width(), this->height()));
    generator.setTitle("SVG Example");
    generator.setDescription("This SVG file is generated by Qt.");
    paintAll(&generator);
}

void MainWindow::paintAll(QSvgGenerator *generator){
    QPainter painter;

    if(generator)
        painter.begin(generator);
    else
        painter.begin(this);

    painter.setFont(QFont("Times", 14, QFont::Bold));
    painter.drawText(QPoint(20, 30), "Testing");
    painter.drawLine(QPoint(50, 60), QPoint(100, 100));
    painter.setBrush(Qt::BDiagPattern);
    painter.drawRect(QRect(40, 120, 80, 30));

    QPen ellipsePen;
    ellipsePen.setColor(Qt::red);
    ellipsePen.setStyle(Qt::DashDotLine);
    painter.setPen(ellipsePen);
    painter.drawEllipse(QPoint(80, 200), 50, 20);

    QPainterPath rectPath;
    rectPath.addRect(QRect(150, 20, 100, 50));
    painter.setPen(QPen(Qt::red, 1, Qt::DashDotLine, Qt::FlatCap, Qt::MiterJoin));
    painter.setBrush(Qt::yellow);
    painter.drawPath(rectPath);
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    paintAll();
}
