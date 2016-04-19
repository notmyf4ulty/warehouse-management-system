#include <QApplication>
#include "mainwindow.h"
#include <QDebug>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainWindow mainWindow(&app);
    mainWindow.show();
    return app.exec();
}
