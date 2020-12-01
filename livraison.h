#ifndef LIVRAISON_H
#define LIVRAISON_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>


class livraison
{   int codelivraison;
    QString livreur, distance, duree, etat;

public:

    livraison();
    livraison(int,QString,QString,QString,QString);

    int     GetCodeLivraison();
    QString GetLivreur();
    QString GetDistance();
    QString GetDuree();
    QString GetEtat();

    void SetCodeLivraison(int i1){this->codelivraison=i1;}
    void SetLivreur(QString l1){livreur=l1;}
    void SetDistance(QString l2){distance=l2;}
    void SetDuree(QString l3){duree=l3;}
    void SetEtat(QString l4){etat=l4;}


        bool ajouter();
        bool modifier(int);
        QSqlQueryModel * afficher();
        bool supprimerl(int);
        void fill_forml(int);

};
#endif // LIVRAISON_H
