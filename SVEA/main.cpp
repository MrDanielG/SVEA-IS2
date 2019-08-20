#include "mainwindow.h"
#include <QApplication>
#include <QStyleFactory>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //Base De Datos

    //db.setDatabaseName("qtSVEA");

    w.show();
    a.setStyle(QStyleFactory::create("Fusion"));
    QPalette p = a.palette();
    p.setColor(QPalette::Window, QColor(53,53,53));
    p.setColor(QPalette::Button, QColor(53,53,53));
    p.setColor(QPalette::Highlight, QColor(142,45,197));
    p.setColor(QPalette::ButtonText, QColor(255,255,255));
    p.setColor(QPalette::WindowText, QColor(255,255,255));
    a.setPalette(p);
    return a.exec();
}
