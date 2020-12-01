#include "historique.h"
#include "mainwindow.h"

#include <QString>
#include <QSqlQuery>
#include "QSqlQueryModel"
#include"QDate"
#include"QDebug"
#include<QObject>
#include<QMessageBox>


historique::historique()
{
    this->nombre=0;
    this->identifiant_reclamation="";
    this->pourcentage_de_reclamation="";
    this->pourcentage_augmentation="";
     this->date_="";
}
historique::historique(int nombre,QString identifiant_reclamation, QString pourcentage_de_reclamation,QString pourcentage_augmentation ,QString date_)
{
    this->identifiant_reclamation=identifiant_reclamation;
    this->date_=date_;
    this->nombre=nombre;
    this->pourcentage_augmentation=pourcentage_augmentation;
    this->pourcentage_de_reclamation=pourcentage_de_reclamation;
}



bool historique::ajouter(){

    QSqlQuery query;
    QString ids=QString::number(nombre);

    query.prepare("insert into historique (IDENTIFIANT_RECLAMATION,DATE_,NOMBRE,POURCENTAGE_DE_RECLAMATION,POURCENTAGE_AUGMENTATION)"
                  "VALUES(:identifiant_reclamation,:date_,:nombre,:pourcentage_de_reclamation,:pourcentage_augmentation)");
    query.bindValue(":nombre",nombre);
    query.bindValue(":identifiant_reclamation",identifiant_reclamation);
    query.bindValue(":pourcentage_augmentation",pourcentage_augmentation);
    query.bindValue(":date_de_reclamation",pourcentage_de_reclamation);
    query.bindValue(":date_",date_);

    return query.exec();
}

QSqlQueryModel * historique::afficher(){

    QSqlQueryModel * query = new QSqlQueryModel();
    query->setQuery("select * from historique");
    query->setHeaderData(2,Qt::Vertical,QObject::tr("nombre"));
    query->setHeaderData(0,Qt::Vertical,QObject::tr("identifiant_reclamation"));
    query->setHeaderData(3,Qt::Vertical,QObject::tr("pourcentage_augmentation"));
    query->setHeaderData(4,Qt::Vertical,QObject::tr("pourcentage_de_reclamation"));
    query->setHeaderData(1,Qt::Vertical,QObject::tr("date_"));
    return query;

}

bool historique::supprimer(int nombree)
{
    QSqlQuery query;


    QString res =QString ::number(nombree);
    query.prepare("Delete from historique where NOMBRE=:nombre");
    query.bindValue(":nombre",res);
    return query.exec();

}

bool historique::modifier(){
    QSqlQuery query1;
    query1.prepare("UPDATE historique set IDENTIFIANT_RECLAMATION=:identifiant_reclamation ,POURCENTAGE_AUGMENTATION=:pourcentage_augmentation,DATE_=:date_,POURCENTAGE_DE_RECLAMATION=:pourcentage_de_reclamation WHERE  NOMBRE=:nombre");
    query1.bindValue(":nombre",nombre);
    query1.bindValue(":pourcentage_augmentation",pourcentage_augmentation);
    query1.bindValue(":pourcentage_de_reclamation",pourcentage_de_reclamation);
    query1.bindValue(":date_",date_);
     query1.bindValue(":identifiant_reclamation",identifiant_reclamation);


    return (query1.exec());
}
QSqlQueryModel * historique ::affichertri()
{QSqlQueryModel * model =new QSqlQueryModel();
    model ->setQuery("select * from historique order by nombre");
    model->setHeaderData(0,Qt::Horizontal,QObject ::tr("identfiant_reclamation"));
    model->setHeaderData(1,Qt::Horizontal,QObject ::tr("date_"));
    model->setHeaderData(2,Qt::Horizontal,QObject ::tr("nombre"));
    model->setHeaderData(3,Qt::Horizontal,QObject ::tr("pourcentage_augmentation"));
    model->setHeaderData(4,Qt::Horizontal,QObject ::tr("pourcentage_de_reclamation"));
    return model;


}
QSqlQueryModel * historique :: recherche (const QString &aux)

{

    QSqlQueryModel * model = new QSqlQueryModel();
         model->setQuery("select * from historique where ((identifiant_reclamation || date_|| nombre|| pourcentage_augmentation|| pourcentage_de_reclamation) LIKE '%"+aux+"%')");
         model->setHeaderData(0,Qt::Horizontal,QObject ::tr("identfiant_reclamation"));
         model->setHeaderData(1,Qt::Horizontal,QObject ::tr("date_"));
         model->setHeaderData(2,Qt::Horizontal,QObject ::tr("nombre"));
         model->setHeaderData(3,Qt::Horizontal,QObject ::tr("pourcentage_augmentation"));
         model->setHeaderData(4,Qt::Horizontal,QObject ::tr("pourcentage_de_reclamation"));
         return model;



            return model;



    return model;
}
