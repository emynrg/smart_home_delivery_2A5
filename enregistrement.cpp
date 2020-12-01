#include "enregistrement.h"


enregistrement::enregistrement()
{
    this->numero_de_livraison=0;
    this->type="";
    this->description="";
    this->date_de_reclamation="";
}
enregistrement::enregistrement(int numero_de_livraison,QString type, QString description,QString date_de_reclamation){

    this->numero_de_livraison=numero_de_livraison;
    this->type=type;
    this->description=description;
    this->date_de_reclamation=date_de_reclamation;
}



bool enregistrement::ajouter(){

    QSqlQuery query;

    query.prepare("insert into enregistrement (numero_de_livraison,type,description,date_de_reclamation)"
                  "values(:numero_de_livraison,:type,:description,:date_de_reclamation)");
    QString ids=QString::number(numero_de_livraison);
    query.bindValue(":numero_de_livraison",ids);
    query.bindValue(":type",type);
    query.bindValue(":description",description);
    query.bindValue(":date_de_reclamation",date_de_reclamation);

    return query.exec();
}

QSqlQueryModel * enregistrement::afficher(){

    QSqlQueryModel * query = new QSqlQueryModel();
    query->setQuery("select * from enregistrement");
    query->setHeaderData(0,Qt::Horizontal,QObject::tr("Identifiant"));
    query->setHeaderData(1,Qt::Horizontal,QObject::tr("type"));
    query->setHeaderData(2,Qt::Horizontal,QObject::tr("description"));
    query->setHeaderData(3,Qt::Horizontal,QObject::tr("date_de_reclamation"));
    return query;

}

bool enregistrement::supprimer(int numero_de_livraison)
{
    QSqlQuery query;

    query.prepare("Delete from enregistrement where numero_de_livraison=:numero_de_livraison");
    QString numero_de_livraisons=QString::number(numero_de_livraison);
    query.bindValue(":numero_de_livraison",numero_de_livraisons);
    return query.exec();

}

bool enregistrement::modifier(){
    QSqlQuery query1;
    query1.prepare("UPDATE enregistrement set type=:type,description=:description,date_de_reclamation=:date_de_reclamation WHERE numero_de_livraison=:numero_de_livraison");
    query1.bindValue(":numero_de_livraison",numero_de_livraison);
    query1.bindValue(":type",type);
    query1.bindValue(":description",description);
    query1.bindValue(":date_de_reclamation",date_de_reclamation);


    return (query1.exec());
}
