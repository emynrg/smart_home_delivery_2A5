#ifndef HISTORIQUE_H
#define HISTORIQUE_H
#include <QString>
#include <QSqlQuery>
#include "QSqlQueryModel"
#include"QDate"
#include"QDebug"
#include<QObject>
class historique
{
public:
    historique();
    historique(int NOMBRE_DE_RECLAMATION,QString identifiant_reclamation, QString pourcentage_de_reclamation,QString pourcentage_augmentation ,QString date_);

    int getnombre(){return NOMBRE_DE_RECLAMATION;}
    QString getidentifiant_reclamation(){return identifiant_reclamation;}
    QString getpourcentage_reclamation(){return pourcentage_de_reclamation;}
    QString getpourcentage_augmentation(){return pourcentage_augmentation;}
    QString getdate(){return date_;}



    void setnombre(int NOMBRE_DE_RECLAMATION){this->NOMBRE_DE_RECLAMATION=NOMBRE_DE_RECLAMATION;}
    void setpourcentage_de_reclamation(QString pourcentage_de_reclamation){this->pourcentage_de_reclamation=pourcentage_de_reclamation;}
    void setpourcentage_augmentation(QString pourcentage_augmentation){this->pourcentage_augmentation=pourcentage_augmentation;}
    void setidentifiant_reclamation(QString identifiant_reclamation){this->identifiant_reclamation=identifiant_reclamation;}
    void setdate(QString date_){this->date_=date_;}


    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    QSqlQueryModel * affichertri();
    bool modifier();
    QSqlQueryModel * recherche (const QString & aux);

private:
    int NOMBRE_DE_RECLAMATION;
    QString identifiant_reclamation;
    QString pourcentage_de_reclamation;
    QString pourcentage_augmentation;
    QString date_;
};
//***************************************

#endif // HISTORIQUE_H
