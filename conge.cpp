#include "conge.h"
#include<QString>
#include "mainwindow.h"
#include "QSqlQuery"
#include<QMessageBox>
#include <QObject>
#include"QSqlQueryModel"

conge::conge()
{
code=0;
id=0;
solde=0;
historique="";
}
conge::conge(int code,int id,int solde,QString historique)
{

    this->code=code;
    this->id=id;
    this->solde=solde;
    this->historique=historique;
}
//**************************************************************************
int conge::get_code()
{
    return code;
}

int conge::get_id()
{
    return id;
}



int conge::get_solde()
{
    return solde;
}
QString conge::get_historique()
{
    return historique;
}
//**********************************AJOUTER*******************************
bool conge::ajouter()
{
    QSqlQuery qry;
   QString  res=QString::number(code);
    qry.prepare("INSERT INTO conge1(CODE,ID,SOLDE,HISTORIQUE)""VALUES(:code,:id,:solde,:historique)");
    qry.bindValue(":code",code);
    qry.bindValue(":id",id);
    qry.bindValue(":solde",solde);

    qry.bindValue(":historique",historique);
    return qry.exec();

}
//*****************************************AFFICHER*******************************
QSqlQueryModel * conge::Afficher_conge()
{
QSqlQueryModel* model= new QSqlQueryModel();
model->setQuery("select * from conge1");
model->setHeaderData(0,Qt::Vertical,QObject::tr("code"));
model->setHeaderData(1,Qt::Vertical,QObject::tr("id"));
model->setHeaderData(2,Qt::Vertical,QObject::tr("solde"));
model->setHeaderData(3,Qt::Vertical,QObject::tr("historique"));

return model;
}
//********************************************SUPPRIMER***********************
bool conge::Supprimer_conge(int conn)
{
    QSqlQuery qry;
    QString res=QString::number(conn);
    qry.prepare("delete from conge1 where CODE = :code");
    qry.bindValue(":code",res);
    return qry.exec();
}
//***********************************************recherche******************************
QSqlQueryModel * conge::CHERCHER_conge(const QString &aux)
{
    QSqlQueryModel * model = new QSqlQueryModel();

    model->setQuery("select * from conge1 where ((code ) LIKE '%"+aux+"%')");
    model->setHeaderData(0,Qt::Vertical,QObject::tr("code"));
    model->setHeaderData(1,Qt::Vertical,QObject::tr("id"));
    model->setHeaderData(2,Qt::Vertical,QObject::tr("solde"));
    model->setHeaderData(3,Qt::Vertical,QObject::tr("historique"));
    return model;
}
//***********************************************MODIFIER*******************************µ
bool conge::Modifier_conge(int code,int id,int solde,QString historique)
{
    QSqlQuery qry;

    qry.prepare("update CONGE1 set CODE=:code,ID=:id,SOLDE=:solde,HISTORIQUE=:historique where CODE=:code");
    qry.bindValue(":code", code);
    qry.bindValue(":id",id);
    qry.bindValue(":solde",solde);
    qry.bindValue(":historique",historique);
    return qry.exec();
}
//********************************************************************************
QSqlQueryModel * conge::TRIER_conge()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from conge1 order by solde desc");
    model->setHeaderData(0,Qt::Vertical,QObject::tr("code"));
    model->setHeaderData(1,Qt::Vertical,QObject::tr("id"));
    model->setHeaderData(2,Qt::Vertical,QObject::tr("solde"));
    model->setHeaderData(3,Qt::Vertical,QObject::tr("historique"));

    return model ;

}
QSqlQueryModel * conge::TRIER2_conge()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from conge1 order by code desc");
    model->setHeaderData(0,Qt::Vertical,QObject::tr("code"));
    model->setHeaderData(1,Qt::Vertical,QObject::tr("id"));
    model->setHeaderData(2,Qt::Vertical,QObject::tr("solde"));
    model->setHeaderData(3,Qt::Vertical,QObject::tr("historique"));

    return model ;

}
