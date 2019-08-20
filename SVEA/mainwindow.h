#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
