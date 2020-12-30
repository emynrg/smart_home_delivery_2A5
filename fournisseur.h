#ifndef FOURNISSEUR_H
#define FOURNISSEUR_H
#include<QString>
#include<QSqlQueryModel>


class fournisseur
{
    QString nom ;
    QString prenom ;
    QString adresse;
    QString id ;
    QString cin ;

public:
    fournisseur();
    fournisseur(QString,QString,QString,QString,QString);

    QString get_prenom(){return prenom;}
    QString get_adresse(){return  adresse;}
    QString get_ID(){return id;}
    QString get_CIN(){return cin;}
    QString get_NOM(){return nom;}
    void set_NOM(QString nm){ nom=nm;}
    void set_prenom(QString pren){prenom=pren;}
     void set_ADRESSE(QString add){ adresse=add;}
     void set_ID(QString idd){ id=idd;}
    void set_CIN(QString cint){ cin=cint;}

    bool ajouterFournisseur();
    QSqlQueryModel * afficherFournisseur();
    bool update_F(QString ,QString,QString, QString, QString ,int );
    bool supprimer(QString);
    QSqlQueryModel * rechercher (const QString &aux );

};

#endif // FOURNISSEUR_H
