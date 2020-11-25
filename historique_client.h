#ifndef HISTORIQUE_CLIENT_H
#define HISTORIQUE_CLIENT_H
#include <QString>
#include <QSqlQueryModel>
#include <QString>
#include <QString>
#include <QDate>
class historique
{
public:
    historique();
    historique(QString,QString,QString,QString,QString,QDate,QString);
    QString getid();
    QString getnom();
    QString getprenom();
    QString getcin();
    QString getnum() ;
    QDate getdate();
    QString getpromotion();
    void setid(QString);
    void setnom(QString);
    void setprenom(QString);
    void setcin(QString);
    void setnum(QString);
    void setdate(QDate);
    void setpromotion(QString);
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(QString);
    bool modifier(QString ,QString, QString ,QString , QString , QDate , QString );
    QSqlQueryModel * rechercher (const QString &aux);
    QSqlQueryModel* trie();




private:
    QString id,num;
    QString cin;
    QString nom, prenom,  promotion;
    QDate date;
};


#endif // HISTORIQUE_CLIENT_H
