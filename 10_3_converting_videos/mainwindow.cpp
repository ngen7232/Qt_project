#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    process =new QProcess(this);
    connect(process, &QProcess::started, this, &MainWindow::processStarted);
    connect(process, &QProcess::readyReadStandardOutput, this, &MainWindow::readyReadStandardOutput);
    connect(process, &QProcess::finished, this, &MainWindow::processFinished);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open video", "", "Video files (*.avi *.mp4 *.mov)");
    ui->label->setText(fileName);
}

void MainWindow::on_pushButton_2_clicked()
{
    QString ffmpeg = "C://FFmpeg/bin/ffmpeg";
    QStringList arguments;
    fileName = ui->label->text();

    if(fileName !=""){
        QFileInfo fileInfo = QFile(fileName);
        outputFileName = fileInfo.path() + "/" + fileInfo.completeBaseName();

        if (QFile::exists(fileName)){
            int format = ui->comboBox->currentIndex();
            if (format == 0){
                outputFileName += ".avi";
            }
            else if (format == 1){
                outputFileName += ".mp4";
            }
            else if (format == 2)
                outputFileName += ".mov";

            qDebug() << outputFileName<<format;
            arguments <<"-i"<<fileName<<outputFileName;
            qDebug() <<arguments;
        }
        else
        {
            QMessageBox::warning(this, "Failed", "Failed to open video fiel.");

        }
    }
    else{
        QMessageBox::warning(this, "Failed", "No file is selevted.");
    }
}

void MainWindow::processStarted(){
    qDebug() <<"Process started.";
    ui->pushButton->setEnabled(false);
    ui->comboBox->setEditable(false);
    ui->pushButton_2->setEnabled(false);
}
void MainWindow::readyReadStandardOutput(){
    outputText += process->readAllStandardOutput();
    ui->textEdit->setText(outputText);
    ui->textEdit->verticalScrollBar()->setSliderPosition(ui->textEdit->verticalScrollBar()->maximum());
}

void MainWindow::processFinished(){
    qDebug() << "Process finished.";
    if(QFile::exists(outputFileName)){
        QMessageBox::information(this, "Success", "Video successfully converted.");
    }
    else{
        QMessageBox::information(this, "Failed", "Failed to convert video.");
    }
    ui->pushButton->setEnabled(true);
    ui->comboBox->setEditable(true);
    ui->pushButton_2->setEnabled(true);
}
