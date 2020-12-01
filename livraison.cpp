#include "livraison.h"

livraison::livraison()
{
    codelivraison=0;
    livreur="";
    duree="";
    distance="";
    etat="";
}

livraison::livraison(int codelivraison, QString livreur,QString duree,QString distance,QString etat)
{
    this->codelivraison=codelivraison;
    this->livreur=livreur;
    this->duree=duree;
    this->distance=distance;
    this->etat=etat;
}

int livraison::GetCodeLivraison(){return codelivraison;}
QString livraison::GetLivreur(){return livreur;}
QString livraison::GetDuree(){return duree;}
QString livraison::GetDistance(){return distance;}
QString livraison::GetEtat(){return etat;}

bool livraison::ajouter()
{
QSqlQuery query;
QString res= QString::number(codelivraison);
 query.prepare("INSERT INTO CRUD1 (CODE_LIVRAISON, LIVREUR, DUREE, DISTANCE, ETAT)"
        "VALUES(:codelivraison, :livreur, :duree, :distance, :etat)");
 query.bindValue(":codelivraison",res);
 query.bindValue(":livreur",livreur);
 query.bindValue(":duree",duree);
 query.bindValue(":distance",distance);
 query.bindValue(":etat",etat);

return query.exec();
}

QSqlQueryModel * livraison::afficher()
{
    QSqlQueryModel * model = new QSqlQueryModel ();
    model->setQuery("select * from CRUD1");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("codelivraison"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("livreur"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("duree"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("distance"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("etat"));

    return model;
}
bool livraison::supprimerl(int selected1){

    QSqlQuery query;
    query.prepare("Delete from CRUD1 where CODE_LIVRAISON = :sel1 ");
    query.bindValue(":sel1", selected1);
    return    query.exec();


}
bool livraison::modifier(int selected1){

    QSqlQuery query;


    query.prepare(" UPDATE CRUD1 SET CODE_LIVRAISON= :code_livraison, LIVREUR= :livreur ,DUREE= :duree ,DISTANCE= :distance"
                  ",ETAT= :etat where CODE_LIVRAISON= :code_livraison");
    query.bindValue(":code_livraison", selected1);
    query.bindValue(":livreur", livreur);
    query.bindValue(":duree", duree);
    query.bindValue(":distance", distance);
    query.bindValue(":etat", etat);
    return    query.exec();

}




