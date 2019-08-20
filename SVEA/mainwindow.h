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

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
