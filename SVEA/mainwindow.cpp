#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //ui->label_contrasena->setText("aiuda");
    int indice=ui->stackedWidget->currentIndex();

    if(indice==0){
       ui->toolBar_Admin->setVisible(false);
    }

    qDebug() << "Daniel";
}

MainWindow::~MainWindow()
{
    delete ui;
}
