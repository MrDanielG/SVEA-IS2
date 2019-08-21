#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
#include "QMessageBox"
#include "QString"
#include "QImage"
#include <QTranslator>
#include <QStandardItemModel>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    showMaximized();

    //db.setDatabaseName("DRIVER={MySQL ODBC 8.0 Unicode Driver};Server=localhost;uid=root;Database=db_svea;");
    cambiarStacked(0);
    db.setDatabaseName("qtSVEA");


    if(!db.open()){
        QMessageBox::critical(this,"Error",db.lastError().text());
        return;
    }
    else{
        Modelo1=new QSqlRelationalTableModel(this,db);
        Modelo1->setTable("vista_partidos");
        Modelo1->setEditStrategy(QSqlRelationalTableModel::OnManualSubmit);
        Modelo1->select();
        ui->tableView_partidos->setModel(Modelo1);

        Modelo1->setHeaderData(Modelo1->fieldIndex("id_partido"),Qt::Horizontal,tr("ID Partido"));
        Modelo1->setHeaderData(Modelo1->fieldIndex("nombre_partido"),Qt::Horizontal,tr("Nombre del partido"));

        Modelo2=new QSqlRelationalTableModel(this,db);
        Modelo2->setTable("vista_votantes");
        Modelo2->setEditStrategy(QSqlRelationalTableModel::OnManualSubmit);
        Modelo2->select();
        ui->tableView_votantes->setModel(Modelo2);

        Modelo2->setHeaderData(Modelo2->fieldIndex("ine"),Qt::Horizontal,tr("INE"));
        Modelo2->setHeaderData(Modelo2->fieldIndex("nombre_votante"),Qt::Horizontal,tr("Nombre del votante"));

        Modelo3=new QSqlRelationalTableModel(this,db);
        Modelo3->setTable("vista_propuesta");
        Modelo3->setEditStrategy(QSqlRelationalTableModel::OnManualSubmit);
        Modelo3->select();
        ui->tableView_validarPropuesta->setModel(Modelo3);


        Modelo3->setHeaderData(Modelo3->fieldIndex("p.id_propuesta"),Qt::Horizontal,tr("ID propuesta"));
        Modelo3->setHeaderData(Modelo3->fieldIndex("c.nombre_candidato"),Qt::Horizontal,tr("Candidato"));
        Modelo3->setHeaderData(Modelo3->fieldIndex("pa.nombre_partido"),Qt::Horizontal,tr("Partido"));
        Modelo3->setHeaderData(Modelo3->fieldIndex("p.contenido"),Qt::Horizontal,tr("Contenido"));
        Modelo3->setHeaderData(Modelo3->fieldIndex("p.beneficios"),Qt::Horizontal,tr("Beneficios"));
        Modelo3->setHeaderData(Modelo3->fieldIndex("p.validada"),Qt::Horizontal,tr("Validada"));

        Modelo4=new QSqlRelationalTableModel(this,db);
        Modelo4->setTable("voto");
        Modelo4->setEditStrategy(QSqlRelationalTableModel::OnManualSubmit);
        Modelo4->select();
        ui->tableView_voto->setModel(Modelo4);


        Modelo4->setHeaderData(Modelo4->fieldIndex("pa.foto_partido"),Qt::Horizontal,tr("Foto partido"));
        Modelo4->setHeaderData(Modelo4->fieldIndex("c.nombre_candidato"),Qt::Horizontal,tr("Candidato"));
        Modelo4->setHeaderData(Modelo4->fieldIndex("pa.nombre_partido"),Qt::Horizontal,tr("Partido"));
    }
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
    ui->fechaVotacion->setMinimumDate(QDate::currentDate());
    ui->fechaFinPresentacion->setMinimumDate(QDate::currentDate());
    ui->fechaFinRegistro->setMinimumDate(QDate::currentDate());
    ui->fechaInicioPresentacion->setMinimumDate(QDate::currentDate());
    ui->fechaInicioRegistro->setMinimumDate(QDate::currentDate());
    ui->horaInicioVotacion->setMinimumTime(QTime::currentTime());
    ui->horaFinVotacion->setMinimumTime(QTime::currentTime());

    ui->stackedWidget->setCurrentIndex(2);
    ui->actionAdministrador->setCheckable(true);
}

void MainWindow::on_actionGenerarUsuarios_triggered()
{
    QSqlQuery query(db); QString ubicacion;
    int partidos;
    query.exec("select count(*) from partido");
    query.next();
    partidos = query.value(0).toInt();
    query.finish();
    qDebug()<< partidos;
    QStandardItemModel *modelImage = new QStandardItemModel;
    for(int p=0; p<partidos; p++){
        query.exec("SELECT foto_partido FROM partido WHERE id_partido="+QString::number(p+1)+"");
        query.next();
        ubicacion = query.value(0).toString();
        query.finish();

        qDebug()<< ubicacion;


        QImage image(ubicacion);
         QStandardItem *item = new QStandardItem();
        item->setData(QVariant(QPixmap::fromImage(image)), Qt::DecorationRole);
        modelImage->setItem(p, 0, item);
        ui->tableView_logos->setModel(modelImage);



    }

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


void MainWindow::on_actionCrear_propuesta_triggered()
{
    ui->stackedWidget->setCurrentIndex(9);
    ui->actionAdministrador->setCheckable(true);
}

void MainWindow::on_actionCerrar_sesion_3_triggered()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->toolBar_Partido->setVisible(false);
}

void MainWindow::on_pushButton_ingresar_clicked()
{
    if(ui->lineEdit_usuario->text().isEmpty()||ui->label_contrasena->text().isEmpty()){
        QMessageBox::warning(this,"Campos vacíos","Debe completar todos los campos.");
        return;
    }
    if(!db.isOpen()){
        qDebug() <<"Error en la conexion";
        return;
    }
    else {
        //Aqui todo el pinshi codigo
        QString login_usuario = ui->lineEdit_usuario->text();
        QString login_contra = ui->lineEdit_contrasena->text();

        qDebug()<<login_usuario;
        qDebug()<<login_contra;

        QString dbAdminUsuario, nombreVotante, ine, nombrePartido;
        QString dbAdminContra, dbCorreo, vUsuario, pUsuario, vCorreo, pCorreo, pNombre, indice;

        QSqlQuery query(db);

        //Recuperar Contraseña de Admin
        query.exec("SELECT contra_usuario FROM usuario WHERE id_tipo_usuario = 1 ");
        query.next();
        dbAdminContra = query.value(0).toString();
        qDebug()<<dbAdminContra;
        query.finish();

        //Recuperar Usuario de Admin
        query.exec("SELECT id_usuario FROM usuario WHERE id_tipo_usuario = 1 ");
        query.next();
        dbAdminUsuario = query.value(0).toString();
        query.finish();

        query.exec("SELECT correo_usuario FROM usuario WHERE id_tipo_usuario = 1 ");
        query.next();
        dbCorreo = query.value(0).toString();
        query.finish();

        if(login_usuario == dbAdminUsuario && login_contra == dbAdminContra){
            cambiarStacked(1);
            ui->toolBar_Admin->setVisible(true);
            ui->usuario_admin->setText(dbAdminUsuario);
            ui->correo_admin->setText(dbCorreo);
        }

        query.exec("SELECT id_usuario FROM usuario WHERE id_tipo_usuario = 2 ");
        query.next();
        pUsuario = query.value(0).toString();
        int nUsuario= query.value(0).toInt();
        query.finish();

        query.exec("SELECT correo_usuario FROM usuario WHERE id_tipo_usuario = 2 ");
        query.next();
        pCorreo = query.value(0).toString();
        query.finish();

        query.exec("select nombre_partido from partido inner join usuario on usuario.id_usuario=partido.usuario_id_usuario and usuario.id_tipo_usuario=2; ");
        query.next();
        pNombre = query.value(0).toString();
        query.finish();


        query.exec("SELECT * FROM `usuario` WHERE id_usuario = "+login_usuario+" and contra_usuario = '"+login_contra+"' and id_tipo_usuario = 2");
        query.next();
        QString validaPartido = query.value(2).toString();
        qDebug()<<validaPartido;

        query.exec("select partido.id_partido from partido inner join usuario on usuario.id_usuario=partido.usuario_id_usuario and usuario.id_tipo_usuario=2; ");
        query.next();
        indice = query.value(0).toString();
        query.finish();

        query.exec("select foto_partido from partido where id_partido="+indice+"");
        query.next();
        QString ubi = query.value(0).toString();
        query.finish();
        QPixmap logoPartido(ubi);
        ui->imagenPartido->setPixmap(logoPartido);
        //ui->imagenPartido->setMask(logoPartido.mask());

        ui->imagenPartido->show();

        if(!validaPartido.isEmpty()){
            //Ui Partido
            cambiarStacked(8);
            ui->toolBar_Partido->setVisible(true);
            ui->nombreUsuarioPartido->setText(pUsuario);
            ui->nombrePartido->setText(pNombre);
            ui->correoPartido->setText(pCorreo);
        }

        query.exec("SELECT id_usuario FROM usuario WHERE id_tipo_usuario = 3 ");
        query.next();
        vUsuario = query.value(0).toString();
        query.finish();

        query.exec("SELECT correo_usuario FROM usuario WHERE id_tipo_usuario = 3 ");
        query.next();
        vCorreo = query.value(0).toString();
        query.finish();

        query.exec("select nombre_votante from votante inner join usuario on usuario.id_usuario=votante.usuario_id_usuario and usuario.id_tipo_usuario=3"
                   "");
        query.next();
        nombreVotante = query.value(0).toString();
        query.finish();

        query.exec("select ine from votante inner join usuario on usuario.id_usuario=votante.usuario_id_usuario and usuario.id_tipo_usuario=3;");
        query.next();
        ine = query.value(0).toString();
        query.finish();

        query.exec("SELECT * FROM `usuario` WHERE id_usuario = "+login_usuario+" and contra_usuario = '"+login_contra+"' and id_tipo_usuario = 3");
        query.next();
        QString validaVotante = query.value(2).toString();
        qDebug()<<validaVotante;
        if(!validaVotante.isEmpty()){
            //Ui Votante
            cambiarStacked(5);
            ui->toolBar_Votante->setVisible(true);
            ui->nombreUsuarioVotante->setText(vUsuario);
            ui->correoVotante->setText(vCorreo);
            ui->nombreVotante->setText(nombreVotante);
            ui->INE->setText(ine);
        }

    }
}


void MainWindow::on_pushButton_crearEleccion_clicked()
{
    QSqlQuery query(db);
    QDate d1,d2,d3,d4,d5;
    d1=ui->fechaVotacion->date();
    d2=ui->fechaFinPresentacion->date();
    d3=ui->fechaFinRegistro->date();
    d4=ui->fechaInicioPresentacion->date();
    d5=ui->fechaInicioRegistro->date();
    QString h1, h2, id1,id2,id3, id4;
    h1=ui->horaInicioVotacion->text();
    h2=ui->horaFinVotacion->text();

    query.exec("select max(fecha_votacion) from votacion");
    query.next();
    QDate limite = query.value(0).toDate();
    query.finish();

//    if(limite>=d5){
//        QMessageBox::warning(this,"Proceso en curso","No se puede crear"
//                                                     " un proceso electoral"
//                                                     " porque hay otro en curso.");
//        return;
//    }
    if(
            d3<d5
            ||d2<d4

            ){
        QMessageBox::warning(this,"Inconsistencia","Las fechas fin no pueden ser"
                                                   " menores a las de inicio. "

                                                   );
        return;
    }
    if((ui->horaInicioVotacion->time())>=(ui->horaFinVotacion->time())){
        QMessageBox::warning(this,"Inconsistencia",
                                                   "La hora fin no puede ser menor"
                                                   " ni igual a la hora inicio. \n"
                                                   );
        return;
    }
    if( d1<d2||
            d4<d3

            ){
        QMessageBox::warning(this,"Inconsistencia",
                             "La cronología de procesos es: "
                             "registro de propuestas, presentación"
                             " de propuestas y votación."
                                                   );
        return;
    }



    query.exec("INSERT into registro_propuestas(fehca_inicio,fecha_fin) values('"+
               d5.toString("yyyy.MM.dd")+"','"+d3.toString("yyyy.MM.dd")+"')");
    query.next();
    query.finish();

    query.exec("select max(id_registro_propuestas) from registro_propuestas");
    query.next();
    id1 = query.value(0).toString();
    query.finish();

    query.exec("INSERT into presentacion_propuestas(fecha_inicio,fecha_final) values('"+
               d4.toString("yyyy.MM.dd")+"','"+d2.toString("yyyy.MM.dd")+"')");
    query.next();
    query.finish();

    query.exec("select max(id_presentacion_propuestas) from presentacion_propuestas");
    query.next();
    id2 = query.value(0).toString();
    query.finish();

    query.exec("INSERT into votacion(fecha_votacion,hora_inicio,hora_final) values('"+
               d1.toString("yyyy.MM.dd")+"','"+h1+"','"+h2+"')");
    query.next();
    query.finish();

    query.exec("select max(id_votacion) from votacion");
    query.next();
    id3 = query.value(0).toString();
    query.finish();

    query.exec("INSERT INTO proceso_propuestas(id_registro_propuestas,id_presentacion_propuestas) "
               "values("+id1+","+id2+")");
    query.next();
    query.finish();

    query.exec("select max(id_proceso_propuestas) from proceso_propuestas");
    query.next();
    id4 = query.value(0).toString();
    query.finish();

    query.exec("INSERT INTO proceso_electoral(id_votacion,id_proceso_propuestas) "
               "values("+id3+","+id4+")");
    query.next();
    query.finish();
}

void MainWindow::on_pushButton_generarUsuarios_clicked()
{
    int rand_num;
    qDebug()<<rand_num;

    if(!db.isOpen()){
        qDebug() <<"Error en la conexion";
        return;
    }
    else{
        QSqlQuery query(db);
        QSqlQuery creaUsuario(db);
        QSqlQuery query3(db);
        QSqlQuery query4(db);

        query.exec("SELECT ine FROM vista_votantes");
        while(query.next()){
            QString dbine = query.value(0).toString();

            qDebug()<<dbine;

            rand_num = QRandomGenerator::global()->bounded(999999,9999999);
            qDebug()<<rand_num;

            creaUsuario.exec("INSERT INTO `usuario`(`contra_usuario`, `correo_usuario`, `id_tipo_usuario`) VALUES ("+QString::number(rand_num)+",'votante@votante.com',2)");

            query3.exec("SELECT id_usuario FROM usuario WHERE contra_usuario = '"+QString::number(rand_num)+"' ");
            query3.next();
            QString dbid = query3.value(0).toString();
            query3.finish();


            query4.exec("UPDATE `votante` SET `usuario_id_usuario`= "+dbid+" WHERE ine = "+dbine+" ");
            query4.next();
            //QString dbid = query.value(0).toString();
            query4.finish();
        }
    }

    ui->tableView_votantes->setModel(Modelo2);
    Modelo2->select();
}
