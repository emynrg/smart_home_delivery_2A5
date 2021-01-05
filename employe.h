#ifndef EMPLOYE_H
#define EMPLOYE_H

#include<QMessageBox>
#include <QObject>
#include "QTableWidgetItem"

#include<QString>
#include "QDebug"
#include<QDate>
#include <QSqlQuery>
#include"QSqlQueryModel"
class Employe
{
public:
    Employe();
    Employe(int,QString,QDate,QString,QString,QString,QString);
    int get_id();
       QString get_nom();
       QDate get_datedenaissance();
       QString get_email();
       QString get_poste();
       QString get_codecarte();
       QString get_historiqueacces();

       bool ajouter();
      // void Ajouter_Employe(int id,QString nom,QString prenom,QString email,QString poste);
       bool Supprimer_Employe(int);
       bool Modifier_Employe(int id,QString nom,QDate datedenaissance,QString email,QString poste,QString codecarte,QString historiqueacces);
       QSqlQueryModel * Afficher_Employe();
       void Rechercher_Employe();
      void pdf_liste();

private :
       int id;
       QString nom,email,poste,codecarte,historiqueacces;
QDate datedenaissance;
};

#endif // EMPLOYE_H
