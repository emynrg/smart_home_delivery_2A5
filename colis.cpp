#include "colis.h"
#include <QMessageBox>

colis::colis()
{
    numcolis=0;
    depart="";
    destination="";
    date_envoi="";
    assurance="";
    poids="";
}

colis::colis(int numcolis, QString depart,QString destination,QString date,QString assurance,QString poids)
{
    this->numcolis=numcolis;
    this->depart=depart;
    this->destination=destination;
    this->date_envoi=date;
    this->assurance=assurance;
    this->poids=poids;
}

int colis::GetNum(){return numcolis;}
QString colis::GetDepart(){return depart;}
QString colis::GetDestination(){return destination;}
QString colis::GetDate(){return date_envoi;}
QString colis::GetAssurance(){return assurance;}
QString colis::GetPoids(){return poids;}

bool colis::ajouter()
{
QSqlQuery query;
QString res= QString::number(numcolis);
 query.prepare("INSERT INTO CRUD (NUM_COLIS, DEPART, DESTINATION, DATE_ENVOI, ASSURANCE, POIDS)"
        "VALUES(:numcolis, :depart, :destination, :date_envoi, :assurance, :poids)");
 query.bindValue(":numcolis",res);
 query.bindValue(":depart",depart);
 query.bindValue(":destination",destination);
 query.bindValue(":date_envoi",date_envoi);
 query.bindValue(":assurance",assurance);
 query.bindValue(":poids",poids);


return query.exec();
}

QSqlQueryModel * colis::afficher()
{
    QSqlQueryModel * model = new QSqlQueryModel ();
    model->setQuery("select * from CRUD");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("numcolis"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("depart"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("destination"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("date"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("assurance"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("poids"));

    return model;
}
bool colis::supprimer(int selected){

    QSqlQuery query;
    query.prepare("Delete from CRUD where NUM_COLIS = :sel ");
    query.bindValue(":sel", selected);
    return    query.exec();


}
bool colis::modifier(int selected){

    QSqlQuery query;


    query.prepare(" UPDATE CRUD SET NUM_COLIS= :num_colis, DEPART= :depart ,DESTINATION= :destination ,DATE_ENVOI= :date_envoi,ASSURANCE= :assurance"
                  ",POIDS= :poids where NUM_COLIS= :num_colis");
    query.bindValue(":num_colis", selected);
    query.bindValue(":depart", depart);
    query.bindValue(":destination", destination);
    query.bindValue(":date_envoi", date_envoi);
    query.bindValue(":assurance", assurance);
    query.bindValue(":poids", poids);
    return    query.exec();

}




