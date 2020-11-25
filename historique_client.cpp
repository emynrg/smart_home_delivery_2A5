#include "historique_client.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QMessageBox>
#include <QTextDocument>
#include <QTextStream>
#include <QComboBox>
#include <QTabWidget>
#include <QSqlTableModel>
historique::historique()
{
    id=""; nom="";prenom="";cin="";num="";/*date=""*/;promotion="";
}

historique::historique(QString id,QString nom,QString prenom,QString cin,QString num, QDate date,QString promotion)
{
    this->id=id;
    this->nom=nom;
    this->prenom=prenom;
    this->cin=cin;
    this->num=num;
    this->date=date;
    this->promotion=promotion;
}

QString historique::getid(){return id;}
QString historique::getnom(){return nom;}
QString historique::getprenom(){return prenom;}
QString historique::getcin(){return cin;}
QString historique::getnum(){return num;}
QDate historique::getdate(){return date;}
QString historique::getpromotion(){return promotion;}

void historique::setid(QString id){this->id=id;}
void historique::setnom(QString nom){this->nom=nom;}
void historique::setprenom(QString prenom){this->prenom=prenom;}
void historique::setcin(QString cin){this->cin=cin;}
void historique::setnum(QString num){this->num=num;}
void historique::setdate(QDate date){this->date=date;}
void historique::setpromotion(QString promotion){this->promotion=promotion;}



bool historique::ajouter()
{

    QSqlQuery query;
  //QString id_string= QString::number(id);
  //QString cin_string= QString::number(cin);
         query.prepare("INSERT INTO historique_clients (id, nom, prenom,cin,num_telephone,date_commande,promotion) "
                       "VALUES (:id,:nom, :prenom,:cin,:num_telephone,:date_commande,:promotion)");
         query.bindValue(":id",id);
         query.bindValue(":nom",nom);
         query.bindValue(":prenom", prenom);
         query.bindValue(":cin", cin);
         query.bindValue(":num_telephone",num);
         query.bindValue(":date_commande",date);
         query.bindValue(":promotion",promotion);
        return query.exec();

}


QSqlQueryModel* historique::afficher()
{

  QSqlQueryModel* model=new QSqlQueryModel();

   model->setQuery("SELECT* FROM historique_clients");
   /*model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("cin"));
   model->setHeaderData(4, Qt::Horizontal, QObject::tr("num_telephone"));
   model->setHeaderData(5, Qt::Horizontal, QObject::tr("date_commande"));
   model->setHeaderData(6, Qt::Horizontal, QObject::tr("promotion"));*/


  return  model;
}

bool historique::supprimer(QString id)
{
    QSqlQuery query;
         query.prepare("Delete from historique_clients where id=:id");
         query.bindValue(0, id);

        return query.exec();


}

bool historique::modifier(QString id,QString nom, QString prenom,QString cin, QString num, QDate date, QString promotion )
{
    QSqlQuery query;
    //QString res= QString::number(id);
    //QString cin1= QString::number(cin);
    //QString numero= QString::number(num);


    query.prepare("update historique_clients set nom=:nom,prenom=:prenom,cin=:cin,num_telephone=:num ,date_commande=:date ,promotion=:promotion where id=:id");
    query.bindValue(":id", id);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":cin", cin);
    query.bindValue(":num",num);
    query.bindValue(":date",date);
    query.bindValue(":promotion",promotion);


    return query.exec();
}


QSqlQueryModel * historique::rechercher (const QString &aux)

{
    QSqlQueryModel * model = new QSqlQueryModel();

    model->setQuery("select * from historique_clients where ((id || nom || prenom || cin || num_telephone || date_commande || promotion) LIKE '%"+aux+"%')");

    /*model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom "));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("cin"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("num"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("date"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("promotion"));*/



    return model;
}

QSqlQueryModel* historique::trie()
{
    QSqlQueryModel* model = new QSqlQueryModel();

        model->setQuery("select * from hitstorique_clients ORDER BY NOM ASC");

    /*model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("cin"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("num_telephone"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("date_commande"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("promotion"));*/

    return model;
}






