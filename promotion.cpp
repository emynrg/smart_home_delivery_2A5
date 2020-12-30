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
         query.prepare("INSERT INTO promotions (id_promotion, prix_promotion, nom_promotion, datedeb_promotion, datefin_promotion, description_promotion) "
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
         query.prepare("Delete from promotions where id_promotion=:id");
         query.bindValue(0, id);

        return query.exec();


}
QSqlQueryModel* promotion::afficher()
{

  QSqlQueryModel* model=new QSqlQueryModel();

   model->setQuery("SELECT * FROM promotions");

  return  model;
}


bool promotion::modifier(QString id,float prix ,QString nom,QDate datedeb, QDate datefin , QString description )
{
    QSqlQuery query;
    //QString res= QString::number(id);
    QString prixx= QString::number(prix);

    query.prepare("update promotions set prix_promotion=:prix,nom_promotion=:nom,description_promotion=:description,datedeb_promotion=:datedeb, datefin_promotion=:datefin where id_promotion=:id");
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

    model->setQuery("select * from promotions where ((id_promotion || prix_promotion || nom_promotion || description_promotion || datedeb_promotion || datefin_promotion) LIKE '%"+aux+"%')");
    return model;
}


QSqlQueryModel *  promotion::trier(const QString &critere, const QString &mode )
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from promotions order by "+critere+" "+mode+"");

/*model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("cin"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("num_telephone"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("date_commande"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("promotion"));*/

    return model;
}




