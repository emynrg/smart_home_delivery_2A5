#ifndef ENREGISTREMENT_H
#define ENREGISTREMENT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include"QDate"

class enregistrement
{
public:
    enregistrement();
    enregistrement(int numero_de_livraison,QString type, QString description,QString date_de_reclamation);

    int getnumero_de_livraison(){return numero_de_livraison;}
    QString gettype(){return type;}
    QString getdescription(){return description;}
    QString getdate(){return date_de_reclamation;}
    void setnumero_de_livraison(int numero_de_livraison){this->numero_de_livraison=numero_de_livraison;}
    void settype(QString type){this->type=type;}
    void setdate_de_reclamation(QString date_de_reclamation){this->date_de_reclamation=date_de_reclamation;}


    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier();


private:
    int numero_de_livraison;
    QString type, description;
    QString date_de_reclamation;
};

#endif // ENREGISTREMENT_H
