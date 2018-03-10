#include "mainwindow.h"
#include <QApplication>

/*
 * Main encaragado de inciar la aplicación
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
