#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QtSvg/QSvgGenerator>
#include <QFileDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    virtual void paintEvent(QPaintEvent *event);
    void paintAll(QSvgGenerator *generator = 0);

private slots:
    void on_action_Save_as_SVG_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
