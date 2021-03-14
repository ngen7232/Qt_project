#include "myclass.h"

myClass::myClass(QWidget *parent) : QWidget(parent)
{

}

void myClass::doSomething(){
    QMessageBox::information(this,"Hello","Button has been added");
}
