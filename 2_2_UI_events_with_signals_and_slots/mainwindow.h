#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
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
    void on_pushButton_clicked();

    void on_pushButton_clicked(bool checked);

    void on_pushButton_pressed();

    void on_pushButton_released();

    void on_pushButton_toggled(bool checked);

    void on_comboBox_activated(const QString &arg1);

    void on_comboBox_activated(int index);

    void on_comboBox_currentIndexChanged(const QString &arg1);

    void on_comboBox_currentIndexChanged(int index);

    void on_comboBox_currentTextChanged(const QString &arg1);

    void on_comboBox_editTextChanged(const QString &arg1);

    void on_comboBox_highlighted(const QString &arg1);

    void on_comboBox_highlighted(int index);

    void on_comboBox_textActivated(const QString &arg1);

    void on_comboBox_textHighlighted(const QString &arg1);

    void on_lineEdit_cursorPositionChanged(int arg1, int arg2);

    void on_lineEdit_editingFinished();

    void on_lineEdit_inputRejected();

    void on_lineEdit_returnPressed();

    void on_lineEdit_selectionChanged();

    void on_lineEdit_textChanged(const QString &arg1);

    void on_lineEdit_textEdited(const QString &arg1);

    void on_spinBox_textChanged(const QString &arg1);

    void on_spinBox_valueChanged(const QString &arg1);

    void on_spinBox_valueChanged(int arg1);

    void on_horizontalSlider_actionTriggered(int action);

    void on_horizontalSlider_rangeChanged(int min, int max);

    void on_horizontalSlider_sliderMoved(int position);

    void on_horizontalSlider_sliderPressed();

    void on_horizontalSlider_sliderReleased();

    void on_horizontalSlider_valueChanged(int value);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
