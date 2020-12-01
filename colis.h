#ifndef COLIS_H
#define COLIS_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>


class colis
{   int numcolis;
    QString depart, destination, date_envoi, assurance, poids;

public:

    colis();
    colis(int,QString,QString,QString,QString,QString);

    int     GetNum();
    QString GetDepart();
    QString GetDestination();
    QString GetDate();
    QString GetAssurance();
    QString GetPoids();

    void SetNum(int i){this->numcolis=i;}
    void SetDepart(QString s1){depart=s1;}
    void SetDestination(QString s2){destination=s2;}
    void SetDate(QString s3){date_envoi=s3;}
    void SetAssurance(QString s4){poids=s4;}
    void SetPoids(QString s5){assurance=s5;}

        bool ajouter();
        bool modifier(int);
        QSqlQueryModel * afficher();
        bool supprimer(int);
        void fill_form(int);

};



#endif // COLIS_H
