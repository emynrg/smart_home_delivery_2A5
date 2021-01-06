#include "enregistrement.h"


enregistrement::enregistrement()
{
    this->numero_de_livraison=0;
    this->TYPE_de_reclamation="";
    this->description="";
    this->date_de_reclamation="";
}
enregistrement::enregistrement(int numero_de_livraison,QString TYPE_de_reclamation, QString description,QString date_de_reclamation){

    this->numero_de_livraison=numero_de_livraison;
    this->TYPE_de_reclamation=TYPE_de_reclamation;
    this->description=description;
    this->date_de_reclamation=date_de_reclamation;
}



bool enregistrement::ajouter(){

    QSqlQuery query;

    query.prepare("insert into enregistrement (numero_de_livraison,TYPE_de_reclamation,description,date_de_reclamation)"
                  "values(:numero_de_livraison,:TYPE_de_reclamation,:description,:date_de_reclamation)");
    QString ids=QString::number(numero_de_livraison);
    query.bindValue(":numero_de_livraison",ids);
    query.bindValue(":type",TYPE_de_reclamation);
    query.bindValue(":description",description);
    query.bindValue(":date_de_reclamation",date_de_reclamation);

    return query.exec();
}

QSqlQueryModel * enregistrement::afficher(){

    QSqlQueryModel * query = new QSqlQueryModel();
    query->setQuery("select * from enregistrement");
    query->setHeaderData(0,Qt::Horizontal,QObject::tr("Identifiant"));
    query->setHeaderData(1,Qt::Horizontal,QObject::tr("TYPE_de_reclamation"));
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
    query1.prepare("UPDATE enregistrement set TYPE_de_reclamation=:TYPE_de_reclamation,description=:description,date_de_reclamation=:date_de_reclamation WHERE numero_de_livraison=:numero_de_livraison");
    query1.bindValue(":numero_de_livraison",numero_de_livraison);
    query1.bindValue(":TYPE_de_reclamation",TYPE_de_reclamation);
    query1.bindValue(":description",description);
    query1.bindValue(":date_de_reclamation",date_de_reclamation);


    return (query1.exec());
}
