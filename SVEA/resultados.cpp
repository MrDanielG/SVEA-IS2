#include "resultados.h"
#include "ui_resultados.h"
#include "QString"
#include <QtSql>
#include <QSqlDatabase>
Resultados::Resultados(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Resultados)
{
    ui->setupUi(this);

    QSqlQuery candidatoQuery(db), partidoQuery(db), numVotosQuery(db);
    QString candidato1, candidato2, candidato3;
    QString partido1, partido2, partido3;
    QString numVotos1, numVotos2, numVotos3;

    candidatoQuery.exec("SELECT nombre_candidato FROM candidato WHERE id_candidato = 1");
    candidatoQuery.next();
    candidato1 = candidatoQuery.value(0).toString();
    candidatoQuery.finish();

    candidatoQuery.exec("SELECT nombre_candidato FROM candidato WHERE id_candidato = 2");
    candidatoQuery.next();
    candidato2 = candidatoQuery.value(0).toString();
    candidatoQuery.finish();

    candidatoQuery.exec("SELECT nombre_candidato FROM candidato WHERE id_candidato = 3");
    candidatoQuery.next();
    candidato3 = candidatoQuery.value(0).toString();
    candidatoQuery.finish();

    partidoQuery.exec("SELECT nombre_partido FROM partido WHERE id_partido = 1");
    partidoQuery.next();
    partido1 = partidoQuery.value(0).toString();
    partidoQuery.finish();

    partidoQuery.exec("SELECT nombre_partido FROM partido WHERE id_partido = 2");
    partidoQuery.next();
    partido2 = partidoQuery.value(0).toString();
    partidoQuery.finish();

    partidoQuery.exec("SELECT nombre_partido FROM partido WHERE id_partido = 3");
    partidoQuery.next();
    partido3 = partidoQuery.value(0).toString();
    partidoQuery.finish();

    numVotosQuery.exec("SELECT COUNT(id_boleta) FROM boleta WHERE candidato_id_candidato = 1;");
    numVotosQuery.next();
    numVotos1 = numVotosQuery.value(0).toString();
    numVotosQuery.finish();

    numVotosQuery.exec("SELECT COUNT(id_boleta) FROM boleta WHERE candidato_id_candidato = 2;");
    numVotosQuery.next();
    numVotos2 = numVotosQuery.value(0).toString();
    numVotosQuery.finish();

    numVotosQuery.exec("SELECT COUNT(id_boleta) FROM boleta WHERE candidato_id_candidato = 3;");
    numVotosQuery.next();
    numVotos3 = numVotosQuery.value(0).toString();
    numVotosQuery.finish();

    //Labels Partido
    ui->label_3->setText(partido1);
    ui->label_4->setText(partido2);
    ui->label_5->setText(partido3);

    //Labels Candidato
    ui->label_6->setText(candidato1);
    ui->label_7->setText(candidato2);
    ui->label_8->setText(candidato3);

    //Labels Candidato
    ui->label_9->setText(numVotos1);
    ui->label_10->setText(numVotos2);
    ui->label_11->setText(numVotos3);

    QString ganador;
    if (numVotos1.toInt() > numVotos2.toInt() && numVotos1.toInt() > numVotos3.toInt()){
        ganador = candidato1;
    } else if (numVotos2.toInt() > numVotos1.toInt() && numVotos2.toInt() > numVotos3.toInt()) {
        ganador = candidato2;
    } else if (numVotos3.toInt() > numVotos1.toInt() && numVotos3.toInt() > numVotos2.toInt()) {
        ganador = candidato3;
    }

    ui->label_12->setText(ganador);
}

Resultados::~Resultados()
{
    delete ui;
}
