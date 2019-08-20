/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAdministrador;
    QAction *actionCrear_eleccion;
    QAction *actionGenerarUsuarios;
    QAction *actionValidar_propuestas;
    QAction *actionCerrar_sesion;
    QAction *actionVotante;
    QAction *actionPropuestas;
    QAction *actionVotar;
    QAction *actionCerrar_sesion_2;
    QAction *actionPartido;
    QAction *actionRegistrar_candidatos;
    QAction *actionCrear_propuesta;
    QAction *actionCerrar_sesion_3;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QStackedWidget *stackedWidget;
    QWidget *page_login;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_inicio;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer;
    QLabel *label_tituloInicio;
    QLineEdit *lineEdit_usuario;
    QLabel *label_usuario;
    QLineEdit *lineEdit_contrasena;
    QLabel *label_contrasena;
    QSpacerItem *verticalSpacer_4;
    QPushButton *pushButton_ingresar;
    QSpacerItem *verticalSpacer_3;
    QWidget *page_a1;
    QLabel *label;
    QWidget *page_a2;
    QLabel *label_2;
    QWidget *page_a3;
    QWidget *page_a4;
    QWidget *page_v1;
    QWidget *page_v2;
    QWidget *page_v3;
    QWidget *page_p1;
    QWidget *page_p2;
    QWidget *page_p3;
    QMenuBar *menuBar;
    QStatusBar *statusBar;
    QToolBar *toolBar_Admin;
    QToolBar *toolBar_Votante;
    QToolBar *toolBar_Partido;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1900, 700);
        MainWindow->setStyleSheet(QLatin1String("QToolBar {\n"
"    background: white;\n"
"    spacing: 3px; /* spacing between items in the tool bar */\n"
"}\n"
"\n"
"QToolBar::handle {\n"
"    image: url(handle.png);\n"
"}\n"
"\n"
"QAction{\n"
"	border-radius: 5px;\n"
"	height: 60px;\n"
"	border-color: 5px black solid;\n"
"}"));
        actionAdministrador = new QAction(MainWindow);
        actionAdministrador->setObjectName(QStringLiteral("actionAdministrador"));
        actionAdministrador->setChecked(false);
        actionAdministrador->setEnabled(true);
        actionCrear_eleccion = new QAction(MainWindow);
        actionCrear_eleccion->setObjectName(QStringLiteral("actionCrear_eleccion"));
        actionCrear_eleccion->setChecked(false);
        QFont font;
        font.setPointSize(8);
        actionCrear_eleccion->setFont(font);
        actionGenerarUsuarios = new QAction(MainWindow);
        actionGenerarUsuarios->setObjectName(QStringLiteral("actionGenerarUsuarios"));
        actionValidar_propuestas = new QAction(MainWindow);
        actionValidar_propuestas->setObjectName(QStringLiteral("actionValidar_propuestas"));
        actionCerrar_sesion = new QAction(MainWindow);
        actionCerrar_sesion->setObjectName(QStringLiteral("actionCerrar_sesion"));
        actionVotante = new QAction(MainWindow);
        actionVotante->setObjectName(QStringLiteral("actionVotante"));
        actionPropuestas = new QAction(MainWindow);
        actionPropuestas->setObjectName(QStringLiteral("actionPropuestas"));
        actionVotar = new QAction(MainWindow);
        actionVotar->setObjectName(QStringLiteral("actionVotar"));
        actionCerrar_sesion_2 = new QAction(MainWindow);
        actionCerrar_sesion_2->setObjectName(QStringLiteral("actionCerrar_sesion_2"));
        actionPartido = new QAction(MainWindow);
        actionPartido->setObjectName(QStringLiteral("actionPartido"));
        actionRegistrar_candidatos = new QAction(MainWindow);
        actionRegistrar_candidatos->setObjectName(QStringLiteral("actionRegistrar_candidatos"));
        actionCrear_propuesta = new QAction(MainWindow);
        actionCrear_propuesta->setObjectName(QStringLiteral("actionCrear_propuesta"));
        actionCerrar_sesion_3 = new QAction(MainWindow);
        actionCerrar_sesion_3->setObjectName(QStringLiteral("actionCerrar_sesion_3"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        page_login = new QWidget();
        page_login->setObjectName(QStringLiteral("page_login"));
        horizontalLayout_3 = new QHBoxLayout(page_login);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_inicio = new QLabel(page_login);
        label_inicio->setObjectName(QStringLiteral("label_inicio"));
        label_inicio->setMinimumSize(QSize(900, 0));

        horizontalLayout_2->addWidget(label_inicio);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(-1, -1, 10, -1);
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        label_tituloInicio = new QLabel(page_login);
        label_tituloInicio->setObjectName(QStringLiteral("label_tituloInicio"));
        QFont font1;
        font1.setPointSize(20);
        label_tituloInicio->setFont(font1);

        verticalLayout_2->addWidget(label_tituloInicio, 0, Qt::AlignHCenter);

        lineEdit_usuario = new QLineEdit(page_login);
        lineEdit_usuario->setObjectName(QStringLiteral("lineEdit_usuario"));
        lineEdit_usuario->setMaximumSize(QSize(200, 200));

        verticalLayout_2->addWidget(lineEdit_usuario, 0, Qt::AlignHCenter);

        label_usuario = new QLabel(page_login);
        label_usuario->setObjectName(QStringLiteral("label_usuario"));
        QFont font2;
        font2.setPointSize(10);
        label_usuario->setFont(font2);

        verticalLayout_2->addWidget(label_usuario, 0, Qt::AlignHCenter);

        lineEdit_contrasena = new QLineEdit(page_login);
        lineEdit_contrasena->setObjectName(QStringLiteral("lineEdit_contrasena"));
        lineEdit_contrasena->setMaximumSize(QSize(200, 16777215));

        verticalLayout_2->addWidget(lineEdit_contrasena, 0, Qt::AlignHCenter|Qt::AlignVCenter);

        label_contrasena = new QLabel(page_login);
        label_contrasena->setObjectName(QStringLiteral("label_contrasena"));
        label_contrasena->setFont(font2);

        verticalLayout_2->addWidget(label_contrasena, 0, Qt::AlignHCenter);

        verticalSpacer_4 = new QSpacerItem(5, 5, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_2->addItem(verticalSpacer_4);

        pushButton_ingresar = new QPushButton(page_login);
        pushButton_ingresar->setObjectName(QStringLiteral("pushButton_ingresar"));
        pushButton_ingresar->setMaximumSize(QSize(150, 16777215));
        pushButton_ingresar->setFont(font2);

        verticalLayout_2->addWidget(pushButton_ingresar, 0, Qt::AlignHCenter);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);


        horizontalLayout_2->addLayout(verticalLayout_2);


        horizontalLayout_3->addLayout(horizontalLayout_2);

        stackedWidget->addWidget(page_login);
        page_a1 = new QWidget();
        page_a1->setObjectName(QStringLiteral("page_a1"));
        label = new QLabel(page_a1);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(170, 20, 191, 16));
        stackedWidget->addWidget(page_a1);
        page_a2 = new QWidget();
        page_a2->setObjectName(QStringLiteral("page_a2"));
        label_2 = new QLabel(page_a2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(150, 20, 47, 13));
        stackedWidget->addWidget(page_a2);
        page_a3 = new QWidget();
        page_a3->setObjectName(QStringLiteral("page_a3"));
        stackedWidget->addWidget(page_a3);
        page_a4 = new QWidget();
        page_a4->setObjectName(QStringLiteral("page_a4"));
        stackedWidget->addWidget(page_a4);
        page_v1 = new QWidget();
        page_v1->setObjectName(QStringLiteral("page_v1"));
        stackedWidget->addWidget(page_v1);
        page_v2 = new QWidget();
        page_v2->setObjectName(QStringLiteral("page_v2"));
        stackedWidget->addWidget(page_v2);
        page_v3 = new QWidget();
        page_v3->setObjectName(QStringLiteral("page_v3"));
        stackedWidget->addWidget(page_v3);
        page_p1 = new QWidget();
        page_p1->setObjectName(QStringLiteral("page_p1"));
        stackedWidget->addWidget(page_p1);
        page_p2 = new QWidget();
        page_p2->setObjectName(QStringLiteral("page_p2"));
        stackedWidget->addWidget(page_p2);
        page_p3 = new QWidget();
        page_p3->setObjectName(QStringLiteral("page_p3"));
        stackedWidget->addWidget(page_p3);

        horizontalLayout->addWidget(stackedWidget);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1900, 21));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        toolBar_Admin = new QToolBar(MainWindow);
        toolBar_Admin->setObjectName(QStringLiteral("toolBar_Admin"));
        toolBar_Admin->setEnabled(true);
        toolBar_Admin->setMinimumSize(QSize(0, 0));
        QFont font3;
        font3.setFamily(QStringLiteral("Bahnschrift"));
        font3.setPointSize(14);
        toolBar_Admin->setFont(font3);
        toolBar_Admin->setMovable(false);
        toolBar_Admin->setToolButtonStyle(Qt::ToolButtonIconOnly);
        toolBar_Admin->setFloatable(true);
        MainWindow->addToolBar(Qt::LeftToolBarArea, toolBar_Admin);
        toolBar_Votante = new QToolBar(MainWindow);
        toolBar_Votante->setObjectName(QStringLiteral("toolBar_Votante"));
        toolBar_Votante->setMovable(false);
        MainWindow->addToolBar(Qt::LeftToolBarArea, toolBar_Votante);
        toolBar_Partido = new QToolBar(MainWindow);
        toolBar_Partido->setObjectName(QStringLiteral("toolBar_Partido"));
        toolBar_Partido->setMovable(false);
        MainWindow->addToolBar(Qt::LeftToolBarArea, toolBar_Partido);

        toolBar_Admin->addAction(actionAdministrador);
        toolBar_Admin->addAction(actionCrear_eleccion);
        toolBar_Admin->addAction(actionGenerarUsuarios);
        toolBar_Admin->addAction(actionValidar_propuestas);
        toolBar_Admin->addAction(actionCerrar_sesion);
        toolBar_Votante->addAction(actionVotante);
        toolBar_Votante->addAction(actionPropuestas);
        toolBar_Votante->addAction(actionVotar);
        toolBar_Votante->addAction(actionCerrar_sesion_2);
        toolBar_Partido->addAction(actionPartido);
        toolBar_Partido->addAction(actionRegistrar_candidatos);
        toolBar_Partido->addAction(actionCrear_propuesta);
        toolBar_Partido->addAction(actionCerrar_sesion_3);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionAdministrador->setText(QApplication::translate("MainWindow", "Administrador", nullptr));
        actionCrear_eleccion->setText(QApplication::translate("MainWindow", "Crear elecci\303\263n", nullptr));
        actionGenerarUsuarios->setText(QApplication::translate("MainWindow", "Generar usuarios", nullptr));
        actionValidar_propuestas->setText(QApplication::translate("MainWindow", "Validar propuestas", nullptr));
        actionCerrar_sesion->setText(QApplication::translate("MainWindow", "Cerrar sesi\303\263n", nullptr));
        actionVotante->setText(QApplication::translate("MainWindow", "Votante", nullptr));
        actionPropuestas->setText(QApplication::translate("MainWindow", "Propuestas", nullptr));
        actionVotar->setText(QApplication::translate("MainWindow", "Votar", nullptr));
        actionCerrar_sesion_2->setText(QApplication::translate("MainWindow", "Cerrar sesi\303\263n", nullptr));
        actionPartido->setText(QApplication::translate("MainWindow", "Partido", nullptr));
        actionRegistrar_candidatos->setText(QApplication::translate("MainWindow", "Registrar candidatos", nullptr));
        actionCrear_propuesta->setText(QApplication::translate("MainWindow", "Crear propuesta", nullptr));
        actionCerrar_sesion_3->setText(QApplication::translate("MainWindow", "Cerrar sesi\303\263n", nullptr));
        label_inicio->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        label_tituloInicio->setText(QApplication::translate("MainWindow", "Iniciar sesi\303\263n", nullptr));
        label_usuario->setText(QApplication::translate("MainWindow", "Usuario", nullptr));
        label_contrasena->setText(QApplication::translate("MainWindow", "Contrase\303\261a", nullptr));
        pushButton_ingresar->setText(QApplication::translate("MainWindow", "Ingresar", nullptr));
        label->setText(QApplication::translate("MainWindow", "Informaci\303\263n administrador", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Crear elecci\303\263n", nullptr));
        toolBar_Admin->setWindowTitle(QApplication::translate("MainWindow", "toolBar", nullptr));
        toolBar_Votante->setWindowTitle(QApplication::translate("MainWindow", "toolBar", nullptr));
        toolBar_Partido->setWindowTitle(QApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
