#include "connexion.h"

connexion::connexion()
{}

bool connexion::ouvrirconnexion()
{ db=QSqlDatabase::addDatabase("QODBC");

db.setDatabaseName("Projet2A");
db.setUserName("mehdi");
db.setPassword("mehdi");

if (db.open())
return true;
    return  false;
}

void connexion::fermerconnexion()
{db.close();}
