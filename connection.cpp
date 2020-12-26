#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("Projet");//inserer le nom de la source de données ODBC
db.setUserName("bedouimehdi");//inserer nom de l'utilisateur
db.setPassword("bedoui123");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;

    return  test;
}

void Connection::closeConnexion(){db.close();}
