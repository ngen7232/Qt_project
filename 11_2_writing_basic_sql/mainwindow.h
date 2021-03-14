#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
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

private slots:
    void on_push_update_clicked();

    void on_push_insert_clicked();

    void on_push_delete_clicked();

private:
    Ui::MainWindow *ui;
    QSqlDatabase db;
    bool connected;
    int currentID;

};
#endif // MAINWINDOW_H
