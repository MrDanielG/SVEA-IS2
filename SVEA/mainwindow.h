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

    void on_actionRegistrar_candidatos_triggered();

    void on_actionCrear_propuesta_triggered();

    void on_actionCerrar_sesion_3_triggered();

    void on_pushButton_ingresar_clicked();

private:
    Ui::MainWindow *ui;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC", "ConexionPrincipal");
};

#endif // MAINWINDOW_H
