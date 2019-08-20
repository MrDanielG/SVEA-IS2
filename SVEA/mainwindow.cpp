#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
#include "QMessageBox"
#include "QString"
#include <QTranslator>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //db.setDatabaseName("DRIVER={MySQL ODBC 8.0 Unicode Driver};Server=localhost;uid=root;Database=db_svea;");

    db.setDatabaseName("qtSVEA");
    if(!db.open()){
        QMessageBox::critical(this,"Error",db.lastError().text());
        return;
    }
    else{

    }
    cambiarStacked(1);

}

void MainWindow::cambiarStacked(int indice)
{//Para utilizar en el login más fácilmente
    ui->stackedWidget->setCurrentIndex(indice);


    if(ui->stackedWidget->currentIndex()==0||ui->stackedWidget->currentIndex()>5){
       ui->toolBar_Admin->setVisible(false);
    }
    if(ui->stackedWidget->currentIndex()<9){
        ui->toolBar_Partido->setVisible(false);
    }
    if(ui->stackedWidget->currentIndex()<6||ui->stackedWidget->currentIndex()>8){
        ui->toolBar_Votante->setVisible(false);
    }
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
    ui->stackedWidget->setCurrentIndex(0);
    ui->toolBar_Admin->setVisible(false);
}

void MainWindow::on_actionVotante_triggered()
{
    ui->stackedWidget->setCurrentIndex(5);
    ui->actionAdministrador->setCheckable(true);
}

void MainWindow::on_actionPropuestas_triggered()
{
    ui->stackedWidget->setCurrentIndex(6);
    ui->actionAdministrador->setCheckable(true);
}

void MainWindow::on_actionVotar_triggered()
{
    ui->stackedWidget->setCurrentIndex(7);
    ui->actionAdministrador->setCheckable(true);
}

void MainWindow::on_actionCerrar_sesion_2_triggered()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->toolBar_Votante->setVisible(false);
}

void MainWindow::on_actionPartido_triggered()
{
    ui->stackedWidget->setCurrentIndex(8);
    ui->actionAdministrador->setCheckable(true);
}

void MainWindow::on_actionRegistrar_candidatos_triggered()
{
    ui->stackedWidget->setCurrentIndex(9);
    ui->actionAdministrador->setCheckable(true);
}

void MainWindow::on_actionCrear_propuesta_triggered()
{
    ui->stackedWidget->setCurrentIndex(10);
    ui->actionAdministrador->setCheckable(true);
}

void MainWindow::on_actionCerrar_sesion_3_triggered()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->toolBar_Votante->setVisible(false);
}

void MainWindow::on_pushButton_ingresar_clicked()
{
    qDebug()<<"asdf";

    //QSqlDatabase mDatabase = QSqlDatabase::database("ConexionPrincipal");

    if(!db.isOpen()){
        qDebug() <<"Error en la conexion";
        return;
    }
    else {
        //Aqui todo el pinshi codigo
        QString usuarioID = ui->lineEdit_usuario->text();
        QString usuarioContra = ui->lineEdit_contrasena->text();

        qDebug()<<usuarioID;
        qDebug()<<usuarioContra;

        QString dbUsuario;
        QString dbContra;

        QSqlQuery queryFile(db);
        queryFile.exec("SELECT contra_usuario FROM usuario WHERE id_usuario = 1");
        dbContra = queryFile.value(1).toString();
        qDebug()<<dbContra;

    }

}
