#include "fournisseur.h"
#include<QSqlQuery>
#include<QSqlQueryModel>

fournisseur::fournisseur()
{/* id="";
   nom="";
   prenom="";
   adresse="";
   cin="";*/
}
/*fournisseur::fournisseur(QString id,QString nom,QString prenom ,QString adresse,QString cin )
{
    this->id=id;
    this->nom=nom;
    this->prenom=prenom;
    this->adresse=adresse;
    this->cin=cin;
}*/
bool fournisseur::ajouterFournisseur()
{
 QSqlQuery query;
 query.prepare("insert into FOURNISSEUR (ID,NOM,PRENOM,ADRESSE,CIN) "
               "values(:id,:nom,:prenom,:adresse,:cin)");
query.bindValue(":id",id);
query.bindValue(":nom",nom);
query.bindValue(":prenom",prenom);
query.bindValue(":adresse",get_adresse());
query.bindValue(":cin",get_CIN());
return query.exec();

}
QSqlQueryModel * fournisseur::afficherFournisseur()
{
 QSqlQueryModel *model=new QSqlQueryModel();
 model->setQuery("SELECT * FROM FOURNISSEUR");
 return model ;
}


bool fournisseur::update_F(QString ident ,QString nom ,QString prenom,QString adresse,QString cin ,int column)
{ QSqlQuery query;
    if (column==1)
              {

      query.prepare( "update FOURNISSEUR set  NOM= :nom where ID=:id " );

              }
    else if (column==2)
    {
        query.prepare( "update FOURNISSEUR set  PRENOM= :prenom where ID=:id " );

    }
    else if (column==3)
    {
        query.prepare( "update FOURNISSEUR set  ADRESSE= :adresse where ID=:id " );

    }
    else if (column==4)
    {
        query.prepare( "update FOURNISSEUR set  CIN= :cin where ID=:id " );

    }

    query.bindValue(":id",ident);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":adresse",adresse);
    query.bindValue(":cin",cin);
    query.exec();


    return query.exec();
}

bool fournisseur::supprimer(QString id)
{
    QSqlQuery query;

     query.prepare("DELETE  FROM FOURNISSEUR WHERE id=:id");
     query.bindValue(":id",id);
     return query.exec();
}


QSqlQueryModel * fournisseur ::rechercher(const QString &aux)
{
    QSqlQueryModel * model = new QSqlQueryModel();

    model->setQuery("select * from FOURNISSEUR where ((id || nom || prenom || adresse || cin ) LIKE '%"+aux+"%')");
    return model;
}






