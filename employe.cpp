#include "employe.h"
#include<QString>
#include "mainwindow.h"
#include "QSqlQuery"
#include<QMessageBox>
#include <QObject>
#include<QDate>
#include <QPrinter>
#include<QPainter>


Employe::Employe()
{
idemp=0;
nomemp="";

emailemp="";
posteemp="";
codecarte="";
historiqueacces="";
}
Employe::Employe(int idemp,QString nomemp,QDate datedenaissanceemp,QString emailemp,QString posteemp,QString codecarte,QString historiqueacces)
{

    this->idemp=idemp;
    this->nomemp=nomemp;
    this->datedenaissanceemp=datedenaissanceemp;
    this->emailemp=emailemp;
    this->posteemp=posteemp;
this->codecarte=codecarte;
    this->historiqueacces=historiqueacces;
}
int Employe::get_id()
{
    return idemp;
}

QString Employe::get_nom()
{
    return nomemp;
}

QDate Employe::get_datedenaissance()
{
    return datedenaissanceemp;
}

QString Employe::get_email()
{
    return emailemp;
}
QString Employe::get_poste()
{
    return posteemp;
}
QString Employe::get_codecarte()
{
    return codecarte;
}
bool Employe::ajouter ()
{
    QSqlQuery qry;
   QString res=QString::number(idemp);
    qry.prepare("INSERT INTO Employe(IDEMP,NOMEMP,DATEDENAISSANCEEMP,EMAILEMP,POSTEEMP,CODECARTE,HISTORIQUEACCES)""VALUES(:idemp,:nomemp,:datedenaissanceemp,:emailemp,:posteemp,:codecarte,:historiqueacces)");
    qry.bindValue(":idemp",idemp);
    qry.bindValue(":nomemp",nomemp);
    qry.bindValue(":datedenaissanceemp",datedenaissanceemp);
    qry.bindValue(":emailemp",emailemp);
    qry.bindValue(":posteemp",posteemp);
    qry.bindValue(":codecarte",codecarte);
    qry.bindValue(":historiqueacces",historiqueacces);

    return qry.exec();

}
QSqlQueryModel * Employe::Afficher_Employe()
{
QSqlQueryModel* model= new QSqlQueryModel();

model->setQuery("select * from Employe");
model->setHeaderData(0,Qt::Vertical,QObject::tr("IDEMP"));
model->setHeaderData(1,Qt::Vertical,QObject::tr("Nomemp"));
model->setHeaderData(2,Qt::Vertical,QObject::tr("datedenaissanceemp"));
model->setHeaderData(3,Qt::Vertical,QObject::tr("emailemp"));
model->setHeaderData(4,Qt::Vertical,QObject::tr("Posteemp"));
model->setHeaderData(5,Qt::Vertical,QObject::tr("codecarte"));
model->setHeaderData(6,Qt::Vertical,QObject::tr("historiqueacces"));
return model;
}
bool Employe::Supprimer_Employe(int idd)
{
    QSqlQuery qry;
    QString res=QString::number(idd);
    qry.prepare("delete from employe where IDEMP = :idemp");
    qry.bindValue(":idemp",res);
    return qry.exec();
}
bool Employe::Modifier_Employe(int idemp,QString nomemp,QDate datedenaissanceemp,QString emailemp,QString posteemp,QString codecarte,QString historiqueacces)
{
    QSqlQuery qry;

    qry.prepare("update employe set NOMEMP=:nomemp,DATEDENAISSANCEEMP=:datedenaissanceemp,EMAILEMP=:emailemp,POSTEEMP=:posteemp ,CODECARTE=:codecarte ,HISTORIQUEACCES=:historiqueacces where ID=:id");
    qry.bindValue(":idemp", idemp);
    qry.bindValue(":nomemp",nomemp);
    qry.bindValue(":datedenaissanceemp",datedenaissanceemp);
    qry.bindValue(":emailemp",emailemp);
    qry.bindValue(":posteemp",posteemp);
    qry.bindValue(":codecarte",codecarte);
    qry.bindValue(":historiqueacces",historiqueacces);
    return qry.exec();
}
//*********************imprimer*****************
