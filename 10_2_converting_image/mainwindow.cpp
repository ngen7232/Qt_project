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


void MainWindow::on_pushButton_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, "Open Image", "", "Image Files (*.png *.jpg *.bmp");
    ui->label->setText(filename);
}


void MainWindow::on_pushButton_2_clicked()
{
    QString fileName = ui->label->text();
    if (fileName != ""){
        QFileInfo fileInfo = QFile(fileName);
        QString newFileName = fileInfo.path() +"/"+fileInfo.completeBaseName();
        QImage image = QImage(ui->label->text());
        if(!image.isNull()){
            int format = ui->comboBox->currentIndex();
            if(format == 0)
            {
                newFileName += ".png";
            }
            else if (format == 1)
            {
                newFileName += ".jpg";
            }
            else{
                newFileName += ".bmp";
            }

            qDebug() << newFileName << format;
            if(image.save(newFileName,0,-1)){
                QMessageBox::information(this, "Success", "Image successfully converted.");

            }
            else{
                QMessageBox::warning(this, "Failed", "Failed to convert image.");
            }
        }
        else{
            QMessageBox::warning(this, "Failed", "Failed to open image file.");
        }
    }
    else{
        QMessageBox::warning(this, "Failed", "No file is selected.");
    }
}
