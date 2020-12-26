#include "signup.h"

signup::signup()
{
    username="";
    password="";
    name="";
    poste="";
}

signup::signup(QString username,QString password, QString name, QString poste)
{
    this->username=username;
    this->password=password;
    this->name=name;
    this->poste=poste;

}

QString signup::GetUsername(){return username;}
QString signup::GetPassword(){return password;}
QString signup::GetName(){return name;}
QString signup::GetPoste(){return poste;}

bool signup::ajouter()
{
QSqlQuery query;
 query.prepare("INSERT INTO SIGNUP (USERNAME, PASSWORD, NAME, POSTE)"
        "VALUES(:username, :password, :name, :poste)");
 query.bindValue(":username",username);
 query.bindValue(":password",password);
 query.bindValue(":name",name);
 query.bindValue(":poste",poste);
return query.exec();
}
