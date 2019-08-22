#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProxyStyle>
#include <QTabBar>
#include <QStyleOptionTab>
#include <QtSql>
#include <QSqlDatabase>
#include <QModelIndex>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    void cambiarStacked(int indice);
    ~MainWindow();

private slots:
    void on_actionAdministrador_triggered();

    void on_actionCrear_eleccion_triggered();

    void on_actionGenerarUsuarios_triggered();

    void on_actionValidar_propuestas_triggered();

    void on_actionCerrar_sesion_triggered();

    void on_actionVotante_triggered();

    void on_actionPropuestas_triggered();

    void on_actionVotar_triggered();

    void on_actionCerrar_sesion_2_triggered();

    void on_actionPartido_triggered();

    void on_actionCrear_propuesta_triggered();

    void on_actionCerrar_sesion_3_triggered();

    void on_pushButton_ingresar_clicked();

    void on_pushButton_crearEleccion_clicked();

    void on_pushButton_generarUsuarios_clicked();

    void on_pushButton_crearPropuesta_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_radioButton_1_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_3_clicked();

    void on_pushButton_votar_clicked();

private:
    Ui::MainWindow *ui;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC", "ConexionPrincipal");
    QSqlRelationalTableModel * Modelo1;//clientes
    QSqlRelationalTableModel * Modelo2;//articulos
    QSqlRelationalTableModel * Modelo3;//vista
    QSqlRelationalTableModel * Modelo4;//pedidos
    QSqlRelationalTableModel * Modelo5;//articulos pedidos
    int votoCandidato;
    int pr1,pr2,pr3, INEVotante;
};

#endif // MAINWINDOW_H
