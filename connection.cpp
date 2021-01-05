#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("projet_2aa");//inserer le nom de la source de données ODBC
db.setUserName("jamoussi1202");//inserer nom de l'utilisateur
db.setPassword("jamoussi1202");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}
