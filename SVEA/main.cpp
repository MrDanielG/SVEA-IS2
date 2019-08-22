#include "mainwindow.h"
#include <QApplication>
#include <QStyleFactory>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    a.setStyle(QStyleFactory::create("Fusion"));
    QPalette p = a.palette();

            p.setColor(QPalette::Background, QColor(255,255,255));
    p.setColor(QPalette::Window, QColor(255,255,255));
//    p.setColor(QPalette::Button, QColor(53,53,53));
    p.setColor(QPalette::Highlight, QColor(135,190,171));
//    p.setColor(QPalette::ButtonText, QColor(255,255,255));
//    p.setColor(QPalette::WindowText, QColor(255,255,255));
    a.setPalette(p);

    return a.exec();
}
