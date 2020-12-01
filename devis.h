#ifndef DEVIS_H
#define DEVIS_H
#include<QSqlQueryModel>
#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include<QSqlQuery>

class devis
{
    QString code ;
    QString destination ;
    QString type_de_livraison;
    QString quantite ;
    QString prix ;
    QString id_fournisseur;
public:

    devis();
    QString get_code(){return code;}
    QString get_destination(){return  destination;}
    QString get_type_de_livraison(){return type_de_livraison;}
    QString get_quantite(){return quantite;}
    QString get_prix(){return prix;}
    QString get_id_fournisseur(){return id_fournisseur;}
    void set_code(QString cd){ code=cd;}
    void set_destination(QString des){destination=des;}
    void set_type_de_livraison(QString type){ type_de_livraison=type;}
    void set_quantite(QString quan){ quantite=quan;}
    void set_prix(QString pr){ prix=pr;}
    void set_id_fournisseur(QString id){id_fournisseur=id;}
    bool ajouterDevis();
    QSqlQueryModel * afficherDevis();
    bool update_D(QString ,QString,QString, QString, QString, QString ,int );
    bool supprimer(QString);
};

#endif // DEVIS_H
