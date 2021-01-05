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
id=0;
nom="";

email="";
poste="";
codecarte="";
historiqueacces="";
}
Employe::Employe(int id,QString nom,QDate datedenaissance,QString email,QString poste,QString codecarte,QString historiqueacces)
{

    this->id=id;
    this->nom=nom;
    this->datedenaissance=datedenaissance;
    this->email=email;
    this->poste=poste;
this->codecarte=codecarte;
    this->historiqueacces=historiqueacces;
}
int Employe::get_id()
{
    return id;
}

QString Employe::get_nom()
{
    return nom;
}

QDate Employe::get_datedenaissance()
{
    return datedenaissance;
}

QString Employe::get_email()
{
    return email;
}
QString Employe::get_poste()
{
    return poste;
}
QString Employe::get_codecarte()
{
    return codecarte;
}
bool Employe::ajouter ()
{
    QSqlQuery qry;
   QString res=QString::number(id);
    qry.prepare("INSERT INTO Employe(ID,NOM,DATEDENAISSANCE,EMAIL,POSTE,CODECARTE,HISTORIQUEACCES)""VALUES(:id,:nom,:datedenaissance,:email,:poste,:codecarte,:historiqueacces)");
    qry.bindValue(":id",id);
    qry.bindValue(":nom",nom);
    qry.bindValue(":datedenaissance",datedenaissance);
    qry.bindValue(":email",email);
    qry.bindValue(":poste",poste);
    qry.bindValue(":codecarte",codecarte);
    qry.bindValue(":historiqueacces",historiqueacces);

    return qry.exec();

}
QSqlQueryModel * Employe::Afficher_Employe()
{
QSqlQueryModel* model= new QSqlQueryModel();

model->setQuery("select * from Employe");
model->setHeaderData(0,Qt::Vertical,QObject::tr("ID"));
model->setHeaderData(1,Qt::Vertical,QObject::tr("Nom"));
model->setHeaderData(2,Qt::Vertical,QObject::tr("datedenaissance"));
model->setHeaderData(3,Qt::Vertical,QObject::tr("email"));
model->setHeaderData(4,Qt::Vertical,QObject::tr("Poste"));
model->setHeaderData(5,Qt::Vertical,QObject::tr("codecarte"));
model->setHeaderData(6,Qt::Vertical,QObject::tr("historiqueacces"));
return model;
}
bool Employe::Supprimer_Employe(int idd)
{
    QSqlQuery qry;
    QString res=QString::number(idd);
    qry.prepare("delete from employe where ID = :id");
    qry.bindValue(":id",res);
    return qry.exec();
}
bool Employe::Modifier_Employe(int id,QString nom,QDate datedenaissance,QString email,QString poste,QString codecarte,QString historiqueacces)
{
    QSqlQuery qry;

    qry.prepare("update employe set NOM=:nom,DATEDENAISSANCE=:datedenaissance,EMAIL=:email,POSTE=:poste ,CODECARTE=:codecarte ,HISTORIQUEACCES=:historiqueacces where ID=:id");
    qry.bindValue(":id", id);
    qry.bindValue(":nom",nom);
    qry.bindValue(":datedenaissance",datedenaissance);
    qry.bindValue(":email",email);
    qry.bindValue(":poste",poste);
    qry.bindValue(":codecarte",codecarte);
    qry.bindValue(":historiqueacces",historiqueacces);
    return qry.exec();
}
//*********************imprimer*****************
