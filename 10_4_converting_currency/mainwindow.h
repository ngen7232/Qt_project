#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDoubleValidator>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QDebug>
#include <QMessageBox>
#include <QJsonObject>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QNetworkAccessManager* manager;
    QString targetCurrency;

private slots:
    void on_convert_btn_clicked();
    void finished(QNetworkReply * reply);
};
#endif // MAINWINDOW_H
