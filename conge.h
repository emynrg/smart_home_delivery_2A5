#ifndef CONGE_H
#define CONGE_H

#include<QMessageBox>
#include <QObject>
#include<QString>
#include "QDebug"
#include<QDate>
#include <QSqlQuery>
#include"QSqlQueryModel"
class conge
{
public:
    conge();
    conge(int,int,int,QString);
    int get_code();
       int get_id();
       int get_solde();
       QString get_historique();


       bool ajouter();
    //  void Ajouter_conge(int code,int id,int solde ,QString historique);
       bool Supprimer_conge(int);
       bool Modifier_conge(int codecon,int idemp,int solde,QString historiquecon);
       QSqlQueryModel * Afficher_conge();
      // void envoyer_mail();
       QSqlQueryModel *  TRIER_conge();
       QSqlQueryModel *  TRIER2_conge();

       QSqlQueryModel *CHERCHER_conge(const QString &aux);

private :
       int codecon,idemp,solde;
       QString historiquecon,aux;

};

#endif // CONGE_H
