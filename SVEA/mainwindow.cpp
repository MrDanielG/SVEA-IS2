#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(5);
    //ui->label_contrasena->setText("aiuda");

    if(ui->stackedWidget->currentIndex()==0||ui->stackedWidget->currentIndex()>5){
       ui->toolBar_Admin->setVisible(false);
    }

    qDebug() << "Daniel";
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionAdministrador_triggered()
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->actionAdministrador->setCheckable(true);
}

void MainWindow::on_actionCrear_eleccion_triggered()
{
    ui->stackedWidget->setCurrentIndex(2);
    ui->actionAdministrador->setCheckable(true);
}

void MainWindow::on_actionGenerarUsuarios_triggered()
{
    ui->stackedWidget->setCurrentIndex(3);
    ui->actionAdministrador->setCheckable(true);
}

void MainWindow::on_actionValidar_propuestas_triggered()
{
    ui->stackedWidget->setCurrentIndex(4);
    ui->actionAdministrador->setCheckable(true);
}

void MainWindow::on_actionCerrar_sesion_triggered()
{
    ui->stackedWidget->setCurrentIndex(5);
    ui->actionAdministrador->setCheckable(true);
}
