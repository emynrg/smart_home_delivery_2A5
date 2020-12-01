#include "devis.h"
#include<QSqlQuery>
#include<QSqlQueryModel>
#include"QDebug"
devis::devis()
{

}


bool devis:: ajouterDevis()
{
    QSqlQuery query;
    query.prepare("insert into DEVIS (CODE,DESTINATION,TYPE_DE_LIVRAISON,QUANTITE,PRIX,ID_FOURNISSEUR) "
                  "values(:code,:destination,:type_de_livraison,:quantite,:prix,:id_fournisseur)");
   query.bindValue(":code",code);
   query.bindValue(":destination",destination);
   query.bindValue(":type_de_livraison",type_de_livraison);
   query.bindValue(":quantite",quantite);
   query.bindValue(":prix",prix);
   qDebug()<<prix;
   query.bindValue(":id_fournisseur",id_fournisseur);
   return query.exec();
}

QSqlQueryModel * devis:: afficherDevis()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM DEVIS");
    return model ;
}


bool devis:: update_D(QString code ,QString destination,QString type, QString quantite , QString prix ,QString fourni ,int column )
{
    QSqlQuery query;
        if (column==1)
                  {

          query.prepare( "update DEVIS set  DESTINATION = : destination where code=:code " );

                  }
        else if (column==2)
        {
            query.prepare( "update DEVIS set  TYPE_DE_LIVRAISON= :type_de_livraison where code=:code " );

        }
        else if (column==3)
        {
            query.prepare( "update DEVIS set  QUANTITE= :quantite where code=:code " );

        }
        else if (column==4)
        {
            query.prepare( "update DEVIS set  PRIX= :prix where code=:code " );

        }
        else if(column==5)
        {
            query.prepare("update DEVIS set ID_FOURNISSEUR= :id_fournisseur where code=:code");
        }

        query.bindValue(":code",code);
        query.bindValue(":destination",destination);
        query.bindValue(":type_de_livraison",type);
        query.bindValue(":quantite",quantite);
        query.bindValue(":prix",prix);
        query.bindValue(":id_fournisseur",fourni);
        query.exec();


        return query.exec();
}
bool devis::supprimer(QString code)
{
    QSqlQuery query;

     query.prepare("DELETE  FROM DEVIS WHERE code=:code");
     query.bindValue(":code",code);
     return query.exec();
}
