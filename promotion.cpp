#include "promotion.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
promotion::promotion()
{
id=""; prix=0; nom=" "; ; description="";
}

promotion::promotion(QString id,float prix, QString nom, QDate datefin, QDate datedeb, QString description)
{this->id=id;this->prix=prix; this->nom=nom; this->datefin=datefin; this->datedeb=datedeb;this->description=description;}
QString promotion::getid(){return id;}
float promotion::getprix(){return prix;}
QString promotion::getnom(){return  nom;}
QDate promotion::getdatefin(){return datefin;}
QDate promotion::getdatedeb(){return datedeb;}
QString promotion::getdescription(){return description;}
void promotion::setid(QString id){this->id=id;}
void promotion::setprix(float prix){this->prix=prix;}
void promotion::setnom(QString nom){this->nom=nom;}
void promotion::setdatefin(QDate datefin){this->datefin=datefin;}
void promotion::setdatedeb(QDate datedeb){this->datedeb=datedeb;}
void promotion::setdescription(QString description){this->description=description;}


bool promotion::ajouter()
{

    QSqlQuery query;
  //QString id_string= QString::number(id);
  QString id_prix=QString::number(prix);
         query.prepare("INSERT INTO promotions (id, prix, nom_promotion, datedeb, datefin, description) "
                       "VALUES (:id,:prix, :nom, :datedeb, :datefin, :description)");
         query.bindValue(":id",id);
         query.bindValue(":prix",id_prix);
         query.bindValue(":nom", nom);
         query.bindValue(":datedeb", datedeb);
         query.bindValue(":datefin",datefin);
         query.bindValue(":description",description);
        return query.exec();

}
bool promotion::supprimer(QString id)
{
    QSqlQuery query;
         query.prepare("Delete from promotions where id=:id");
         query.bindValue(0, id);

        return query.exec();


}
QSqlQueryModel* promotion::afficher()
{

  QSqlQueryModel* model=new QSqlQueryModel();

   model->setQuery("SELECT* FROM promotions");



  return  model;
}


bool promotion::modifier(QString id,float prix ,QString nom,QDate datedeb, QDate datefin , QString description )
{
    QSqlQuery query;
    //QString res= QString::number(id);
    QString prixx= QString::number(prix);

    query.prepare("update promotions set prix=:prix,nom_promotion=:nom,description=:description,datedeb=:datedeb, datefin=:datefin where id=:id");
    query.bindValue(":id", id);
    query.bindValue(":prix", prixx);
    query.bindValue(":nom",nom);
    query.bindValue(":description",description);
    query.bindValue(":datedeb", datedeb);
    query.bindValue(":datefin",datefin);
    return query.exec();
}

QSqlQueryModel * promotion::rechercher (const QString &aux)

{
    QSqlQueryModel * model = new QSqlQueryModel();

    model->setQuery("select * from promotions where ((id || prix || nom_promotion || description || datedeb || datefin) LIKE '%"+aux+"%')");

    /*model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("prix"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("nom "));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("description"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("datedeb"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("datefin"));*/


    return model;
}

QSqlQueryModel* promotion::trie()
{
    QSqlQueryModel* model = new QSqlQueryModel();

        model->setQuery("select * from promotions ORDER BY prix ASC");

    /*model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("cin"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("num_telephone"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("date_commande"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("promotion"));*/


    return model;
}



