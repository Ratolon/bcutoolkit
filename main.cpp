#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    // Pongo la ventana en pantalla completa
    w.setWindowState(Qt::WindowFullScreen);
    w.show();
    return a.exec();
}
