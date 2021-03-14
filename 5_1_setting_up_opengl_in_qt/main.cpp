
#include "renderwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    RenderWindow window;
    window.setTitle("Hello world!");
    window.resize(640, 800);
    window.show();

    return a.exec();
}
