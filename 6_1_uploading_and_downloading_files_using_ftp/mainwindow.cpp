#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    manager = new QNetworkAccessManager(this);
    ftpAddress = "ftp://127.0.0.1/";
    ftpPort = 21;
    username = "jjy";
    password = "123";
    getFileList();

    ui->up_progress->setValue(0);
    ui->down_progress->setValue(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_open_btn_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Select File", qApp->applicationDirPath());
    ui->upload_edit->setText(fileName);
}

void MainWindow::on_upload_btn_clicked()
{
    QFile *file = new QFile(ui->upload_edit->text());
    QFileInfo fileInfo(*file);
    uploadFileName = fileInfo.fileName();

    QUrl ftpPath;
    ftpPath.setUrl(ftpAddress + uploadFileName);
    ftpPath.setUserName(username);
    ftpPath.setPassword(password);
    ftpPath.setPort(ftpPort);

    if(file->open(QIODevice::ReadOnly)){
        ui->up_progress->setEnabled(true);
        ui->up_progress->setValue(0);

        QNetworkRequest request;
        request.setUrl(ftpPath);

        uploadFileReply = manager->put(request, file);
        connect(uploadFileReply, &QNetworkReply::uploadProgress, this, &MainWindow::uploadFileProgress);
        connect(uploadFileReply, &QNetworkReply::finished, this, &MainWindow::uploadFileFinished);
    }
    else{
        QMessageBox::warning(this, "Invalid File", "Failed to open file for upload.");
    }
}

void MainWindow::on_set_btn_clicked()
{
    QString folder = QFileDialog::getExistingDirectory(this, tr("Open Directory"), qApp->applicationDirPath(), QFileDialog::ShowDirsOnly);
    ui->download_edit->setText(folder);
}

void MainWindow::getFileList(){
    QUrl ftpPath;
    ftpPath.setUrl(ftpAddress + "files.txt");
    ftpPath.setUserName(username);
    ftpPath.setPassword(password);
    ftpPath.setPort(ftpPort);

    QNetworkRequest request;
    request.setUrl(ftpPath);
    downloadFileListReply = manager->get(request);
    connect(downloadFileListReply, SIGNAL(finished()), this, SLOT(downloadFileListFinished()));
}

void MainWindow::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    downloadFileName = item->text();

    QString folder = ui->download_edit->text();
    if(folder != "" && QDir(folder).exists()){
        QUrl ftpPath;
        ftpPath.setUrl(ftpAddress + downloadFileName);
        ftpPath.setUserName(username);
        ftpPath.setPassword(password);
        ftpPath.setPort(ftpPort);

        QNetworkRequest request;
        request.setUrl(ftpPath);

        downloadFileReply = manager->get(request);
        connect(downloadFileReply, &QNetworkReply::downloadProgress, this, &MainWindow::downloadFileProgress);
        connect(downloadFileReply, &QNetworkReply::finished, this, &MainWindow::downloadFileFinished);
    }
    else{
        QMessageBox::warning(this, "Invalid Path", "Please set the download path before download.");
    }
}

void MainWindow::downloadFileListFinished(){
    if(downloadFileListReply->error() != QNetworkReply::NoError)
        QMessageBox::warning(this, "Failed", "Failed to load file list: " + downloadFileListReply->errorString());
    else{
        QByteArray responseData;
        if(downloadFileListReply->isReadable()){
            responseData = downloadFileListReply->readAll();
        }

        ui->listWidget->clear();
        fileList = QString(responseData).split(",");
        if(fileList.size()>0){
            for(int i = 0 ;  i<fileList.size(); i++){
                if(fileList.at(i) != ""){
                    ui->listWidget->addItem(fileList.at(i));
                }
            }
        }
    }
}

void MainWindow::uploadFileListFinished(){
    if(uploadFileListReply->error() != QNetworkReply::NoError)
        QMessageBox::warning(this, "Failed", "Failed to update file list: " + uploadFileListReply->errorString());
    else
        getFileList();
}

void MainWindow::uploadFileProgress(qint64 bytesSent, qint64 bytesTotal){
    qint64 percentage;
    if (bytesTotal == 0)
        percentage = 0;
    else
        percentage = 100*bytesSent/bytesTotal;
    ui->up_progress->setValue((int) percentage);
}

void MainWindow::uploadFileFinished(){
    if(uploadFileReply->error() != QNetworkReply::NoError)
        QMessageBox::warning(this, "Failed", "Failed to upload file: " + uploadFileReply->errorString());
    else{
        bool exists = false;
        if (fileList.size()>0){
            for(int i = 0; i < fileList.size(); i++){
                if (fileList.at(i) == uploadFileName)
                    exists = true;
            }
        }
        if (!exists)
            fileList.append(uploadFileName);

        QString fileName = "files.txt";
        QFile* file = new QFile(qApp->applicationDirPath() + "/" + fileName);
        file->open(QIODevice::ReadWrite);
        if (fileList.size() >0){
            for (int j = 0; j < fileList.size(); j++){
                if (fileList.at(j) != "")
                    file->write(QString(fileList.at(j) +",").toUtf8());
            }
        }
        file->close();

        QFile* newFile = new QFile(qApp->applicationDirPath() + "/" + fileName);
        if(newFile->open(QIODevice::ReadOnly)){
            QUrl ftpPath;
            ftpPath.setUrl(ftpAddress + fileName);
            ftpPath.setUserName(username);
            ftpPath.setPassword(password);
            ftpPath.setPort(ftpPort);

            QNetworkRequest request;
            request.setUrl(ftpPath);
            uploadFileListReply = manager->put(request, newFile);
            connect(uploadFileListReply, &QNetworkReply::finished, this, &MainWindow::uploadFileListFinished);
            file->close();
        }
        QMessageBox::information(this, "Success", "File successfully uploaded.");
    }
}

void MainWindow::downloadFileProgress(qint64 bytesReceived, qint64 bytesTotal){
    qint64 percentage = 100 * bytesReceived/bytesTotal;
    ui->down_progress->setValue((int) percentage);
}

void MainWindow::downloadFileFinished(){
    if(downloadFileReply->error() != QNetworkReply::NoError)
        QMessageBox::warning(this, "Failed", "Failed to download file: " + downloadFileReply->errorString());
    else
    {
        QByteArray responseData;
        if(downloadFileReply->isReadable())
            responseData = downloadFileReply->readAll();

        if(!responseData.isEmpty()){
            QString folder = ui->download_edit->text();
            QFile file(folder + "/" +downloadFileName);
            file.open(QIODevice::WriteOnly);
            file.write((responseData));
            file.close();
            QMessageBox::information(this, "Success", "File successfully downloaded.");
        }
    }
}
