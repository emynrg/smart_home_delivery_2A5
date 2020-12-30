#ifndef promotion_H
#define promotion_H

#include <QString>
#include <QSqlQueryModel>
#include <QDate>
class promotion
{
public:
    promotion();
    promotion(QString,float,QString,QDate,QDate,QString);
    QString getid();
    float getprix();
    QString getnom();
    QDate getdatefin();
    QDate getdatedeb();
    QString getdescription() ;
    void setid(QString);
    void setprix(float);
    void setnom(QString);
    void setdatefin(QDate);
    void setdatedeb(QDate);
    void setdescription(QString);
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(QString);
    bool modifier(QString, float , QString , QDate ,QDate,QString );
    QSqlQueryModel * rechercher (const QString &aux);
    QSqlQueryModel * trier(const QString &critere, const QString &mode );



private:
    float prix;
    QString nom, description,id;
    QDate datedeb,datefin;
};

#endif // promotion_H
