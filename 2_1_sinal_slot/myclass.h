#ifndef MYCLASS_H
#define MYCLASS_H

#include <QWidget>
#include <QMainWindow>
#include <QMessageBox>

class myClass : public QWidget
{
    Q_OBJECT
public:
    explicit myClass(QWidget *parent = nullptr);

signals:
public slots:
    void doSomething();
};

#endif // MYCLASS_H
