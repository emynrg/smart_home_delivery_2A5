#include "conge.h"
#include<QString>
#include "mainwindow.h"
#include "QSqlQuery"
#include<QMessageBox>
#include <QObject>
#include"QSqlQueryModel"

conge::conge()
{
codecon=0;
idemp=0;
solde=0;
historiquecon="";
}
conge::conge(int codecon,int idemp,int solde,QString historiquecon)
{

    this->codecon=codecon;
    this->idemp=idemp;
    this->solde=solde;
    this->historiquecon=historiquecon;
}
//**************************************************************************
int conge::get_code()
{
    return codecon;
}

int conge::get_id()
{
    return idemp;
}



int conge::get_solde()
{
    return solde;
}
QString conge::get_historique()
{
    return historiquecon;
}
//**********************************AJOUTER*******************************
bool conge::ajouter()
{
    QSqlQuery qry;
   QString  res=QString::number(codecon);
    qry.prepare("INSERT INTO conge1(CODECONGE,IDEMPLOYE,SOLDE,HISTORIQUECONGE)""VALUES(:codecon,:idemp,:solde,:historiquecon)");
    qry.bindValue(":codecon",codecon);
    qry.bindValue(":idemp",idemp);
    qry.bindValue(":solde",solde);

    qry.bindValue(":historiquecon",historiquecon);
    return qry.exec();

}
//*****************************************AFFICHER*******************************
QSqlQueryModel * conge::Afficher_conge()
{
QSqlQueryModel* model= new QSqlQueryModel();
model->setQuery("select * from conge1");
model->setHeaderData(0,Qt::Vertical,QObject::tr("codecon"));
model->setHeaderData(1,Qt::Vertical,QObject::tr("idemp"));
model->setHeaderData(2,Qt::Vertical,QObject::tr("solde"));
model->setHeaderData(3,Qt::Vertical,QObject::tr("historiquecon"));

return model;
}
//********************************************SUPPRIMER***********************
bool conge::Supprimer_conge(int conn)
{
    QSqlQuery qry;
    QString res=QString::number(conn);
    qry.prepare("delete from conge1 where CODECONGE = :codecon");
    qry.bindValue(":codecon",res);
    return qry.exec();
}
//***********************************************recherche******************************
QSqlQueryModel * conge::CHERCHER_conge(const QString &aux)
{
    QSqlQueryModel * model = new QSqlQueryModel();

    model->setQuery("select * from conge1 where ((codecon ) LIKE '%"+aux+"%')");
    model->setHeaderData(0,Qt::Vertical,QObject::tr("codecon"));
    model->setHeaderData(1,Qt::Vertical,QObject::tr("idemp"));
    model->setHeaderData(2,Qt::Vertical,QObject::tr("solde"));
    model->setHeaderData(3,Qt::Vertical,QObject::tr("historiquecon"));
    return model;
}
//***********************************************MODIFIER*******************************µ
bool conge::Modifier_conge(int codecon,int idemp,int solde,QString historiquecon)
{
    QSqlQuery qry;

    qry.prepare("update CONGE1 set CODECONGE=:codecon,IDEMPLOYE=:idemp,SOLDE=:solde,HISTORIQUECONGE=:historiquecon where CODECONGE=:codecon");
    qry.bindValue(":codecon", codecon);
    qry.bindValue(":idemp",idemp);
    qry.bindValue(":solde",solde);
    qry.bindValue(":historiquecon",historiquecon);
    return qry.exec();
}
//********************************************************************************
QSqlQueryModel * conge::TRIER_conge()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from conge1 order by solde desc");
    model->setHeaderData(0,Qt::Vertical,QObject::tr("codecon"));
    model->setHeaderData(1,Qt::Vertical,QObject::tr("idemp"));
    model->setHeaderData(2,Qt::Vertical,QObject::tr("solde"));
    model->setHeaderData(3,Qt::Vertical,QObject::tr("historiquecon"));

    return model ;

}
QSqlQueryModel * conge::TRIER2_conge()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from conge1 order by codecon desc");
    model->setHeaderData(0,Qt::Vertical,QObject::tr("codecon"));
    model->setHeaderData(1,Qt::Vertical,QObject::tr("idemp"));
    model->setHeaderData(2,Qt::Vertical,QObject::tr("solde"));
    model->setHeaderData(3,Qt::Vertical,QObject::tr("historiquecon"));

    return model ;

}
