#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QProcess>
#include <QMessageBox>
#include <QScrollBar>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QProcess* process;
    QString outputText;
    QString fileName;
    QString outputFileName;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();
    void processStarted();
    void readyReadStandardOutput();
    void processFinished();

private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
