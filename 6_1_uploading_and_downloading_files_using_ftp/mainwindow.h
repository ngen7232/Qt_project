#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QFile>
#include <QFileInfo>
#include <QFileDialog>
#include <QListWidgetItem>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void getFileList();

private slots:
    void on_open_btn_clicked();

    void on_upload_btn_clicked();

    void on_set_btn_clicked();
    void downloadFileListFinished();
    void uploadFileListFinished();
    void uploadFileProgress(qint64 byteSent, qint64 bytesTotal);
    void uploadFileFinished();
    void downloadFileProgress(qint64 byteReceived, qint64 bytesTotal);
    void downloadFileFinished();

    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

private:
    Ui::MainWindow *ui;
    QNetworkAccessManager* manager;
    QString ftpAddress;
    int ftpPort;
    QString username;
    QString password;
    QNetworkReply* downloadFileListReply;
    QNetworkReply* uploadFileListReply;
    QNetworkReply* uploadFileReply;
    QNetworkReply* downloadFileReply;

    QStringList fileList;
    QString uploadFileName;
    QString downloadFileName;
};
#endif // MAINWINDOW_H
