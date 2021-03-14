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
    qDebug() << "Push button clicked\n";
}

void MainWindow::on_pushButton_clicked(bool checked)
{
    qDebug() << "Push button clicked" << checked <<"\n";
}

void MainWindow::on_pushButton_pressed()
{
    qDebug() << "Push button pressed\n";

}

void MainWindow::on_pushButton_released()
{
    qDebug() << "Push button released\n";
}

void MainWindow::on_pushButton_toggled(bool checked)
{
    qDebug() << "Push button toggled"<< checked <<"\n";
}

void MainWindow::on_comboBox_activated(const QString &arg1)
{
    qDebug() << "Combo box activated" << arg1 <<"\n";
}

void MainWindow::on_comboBox_activated(int index)
{
    qDebug() << "Combo box activated" << index<<"\n";
}

void MainWindow::on_comboBox_currentIndexChanged(const QString &arg1)
{
    qDebug() << "Combo box index changed" << arg1 <<"\n";
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    qDebug() << "Combo box index changed" << index <<"\n";
}

void MainWindow::on_comboBox_currentTextChanged(const QString &arg1)
{
    qDebug() << "Combo box current text changed" << arg1 <<"\n";
}

void MainWindow::on_comboBox_editTextChanged(const QString &arg1)
{
    qDebug() << "Combo box edit text changed" << arg1 <<"\n";
}

void MainWindow::on_comboBox_highlighted(const QString &arg1)
{
    qDebug() << "Combo box hilihted" << arg1 << "\n";
}

void MainWindow::on_comboBox_highlighted(int index)
{
    qDebug() << "Combo box hilihted" << index << "\n";
}

void MainWindow::on_comboBox_textActivated(const QString &arg1)
{
    qDebug() << "Combo box text activated" << arg1 <<"\n";
}

void MainWindow::on_comboBox_textHighlighted(const QString &arg1)
{
    qDebug() << "Combo box edit text highlighted" << arg1 <<"\n";
}

void MainWindow::on_lineEdit_cursorPositionChanged(int arg1, int arg2)
{
    qDebug() << "Line edit cursor position changed" << arg1 <<" "<< arg2 << "\n";
}

void MainWindow::on_lineEdit_editingFinished()
{
    qDebug() << "Line edit edit finished" << "\n";
}

void MainWindow::on_lineEdit_inputRejected()
{
    qDebug() << "Line edit input rejected \n";
}

void MainWindow::on_lineEdit_returnPressed()
{
    qDebug() << "Line edit return pressed\n";
}

void MainWindow::on_lineEdit_selectionChanged()
{
    qDebug() << "Line edit slection changed\n";
}

void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    qDebug() << "Line edit text changed"<<arg1<<"\n";

}

void MainWindow::on_lineEdit_textEdited(const QString &arg1)
{
    qDebug() << "Line edit text edited"<<arg1<<"\n";

}

void MainWindow::on_spinBox_textChanged(const QString &arg1)
{
    qDebug() << "Spin box text changed"<<arg1<<"\n";

}

void MainWindow::on_spinBox_valueChanged(const QString &arg1)
{
    qDebug() << "Spin box value changed"<<arg1<<"\n";

}

void MainWindow::on_spinBox_valueChanged(int arg1)
{
    qDebug() << "Spin box value changed"<<arg1<<"\n";

}

void MainWindow::on_horizontalSlider_actionTriggered(int action)
{

    qDebug() << "horizontal slider action triggered"<<action<<"\n";
}

void MainWindow::on_horizontalSlider_rangeChanged(int min, int max)
{

    qDebug() << "horizontal slider range changed min: "<<min << ", max: "<<max<<"\n";
}

void MainWindow::on_horizontalSlider_sliderMoved(int position)
{
    qDebug() << "horizontal slider moved: "<<position<<"\n";
}

void MainWindow::on_horizontalSlider_sliderPressed()
{
    qDebug() << "horizontal slider pressed\n";
}

void MainWindow::on_horizontalSlider_sliderReleased()
{
    qDebug() << "horizontal slider released\n";
}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    qDebug() << "horizontal slider value changed" << value <<"\n";
}
