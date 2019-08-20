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
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QStackedWidget *stackedWidget;
    QWidget *page;
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
    QWidget *page_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QToolBar *toolBar_Admin;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1900, 700);
        actionAdministrador = new QAction(MainWindow);
        actionAdministrador->setObjectName(QStringLiteral("actionAdministrador"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        horizontalLayout_3 = new QHBoxLayout(page);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_inicio = new QLabel(page);
        label_inicio->setObjectName(QStringLiteral("label_inicio"));
        label_inicio->setMinimumSize(QSize(900, 0));

        horizontalLayout_2->addWidget(label_inicio);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(-1, -1, 10, -1);
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        label_tituloInicio = new QLabel(page);
        label_tituloInicio->setObjectName(QStringLiteral("label_tituloInicio"));
        QFont font;
        font.setPointSize(20);
        label_tituloInicio->setFont(font);

        verticalLayout_2->addWidget(label_tituloInicio, 0, Qt::AlignHCenter);

        lineEdit_usuario = new QLineEdit(page);
        lineEdit_usuario->setObjectName(QStringLiteral("lineEdit_usuario"));
        lineEdit_usuario->setMaximumSize(QSize(200, 200));

        verticalLayout_2->addWidget(lineEdit_usuario, 0, Qt::AlignHCenter);

        label_usuario = new QLabel(page);
        label_usuario->setObjectName(QStringLiteral("label_usuario"));
        QFont font1;
        font1.setPointSize(10);
        label_usuario->setFont(font1);

        verticalLayout_2->addWidget(label_usuario, 0, Qt::AlignHCenter);

        lineEdit_contrasena = new QLineEdit(page);
        lineEdit_contrasena->setObjectName(QStringLiteral("lineEdit_contrasena"));
        lineEdit_contrasena->setMaximumSize(QSize(200, 16777215));

        verticalLayout_2->addWidget(lineEdit_contrasena, 0, Qt::AlignHCenter|Qt::AlignVCenter);

        label_contrasena = new QLabel(page);
        label_contrasena->setObjectName(QStringLiteral("label_contrasena"));
        label_contrasena->setFont(font1);

        verticalLayout_2->addWidget(label_contrasena, 0, Qt::AlignHCenter);

        verticalSpacer_4 = new QSpacerItem(5, 5, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_2->addItem(verticalSpacer_4);

        pushButton_ingresar = new QPushButton(page);
        pushButton_ingresar->setObjectName(QStringLiteral("pushButton_ingresar"));
        pushButton_ingresar->setMaximumSize(QSize(150, 16777215));
        pushButton_ingresar->setFont(font1);

        verticalLayout_2->addWidget(pushButton_ingresar, 0, Qt::AlignHCenter);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);


        horizontalLayout_2->addLayout(verticalLayout_2);


        horizontalLayout_3->addLayout(horizontalLayout_2);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        stackedWidget->addWidget(page_2);

        horizontalLayout->addWidget(stackedWidget);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1900, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        toolBar_Admin = new QToolBar(MainWindow);
        toolBar_Admin->setObjectName(QStringLiteral("toolBar_Admin"));
        toolBar_Admin->setEnabled(true);
        toolBar_Admin->setMinimumSize(QSize(0, 0));
        toolBar_Admin->setMovable(false);
        toolBar_Admin->setToolButtonStyle(Qt::ToolButtonIconOnly);
        toolBar_Admin->setFloatable(true);
        MainWindow->addToolBar(Qt::LeftToolBarArea, toolBar_Admin);

        toolBar_Admin->addAction(actionAdministrador);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionAdministrador->setText(QApplication::translate("MainWindow", "Administrador", nullptr));
        label_inicio->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        label_tituloInicio->setText(QApplication::translate("MainWindow", "Iniciar sesi\303\263n", nullptr));
        label_usuario->setText(QApplication::translate("MainWindow", "Usuario", nullptr));
        label_contrasena->setText(QApplication::translate("MainWindow", "Contrase\303\261a", nullptr));
        pushButton_ingresar->setText(QApplication::translate("MainWindow", "Ingresar", nullptr));
        toolBar_Admin->setWindowTitle(QApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
