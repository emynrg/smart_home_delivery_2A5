#include "mainwindow.h"

#include <QApplication>
#include <QMessageBox>
#include <QDebug>
#include "connexion.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    connexion c;
    bool test=c.ouvrirconnexion();
    MainWindow w;
         if(test)
         {

             w.show();
             QMessageBox::information(nullptr, QObject::tr("database is open"),
                         QObject::tr("connexion successful.\n""Click Cancel to exit."), QMessageBox::Cancel);

             // qDebug()<<"connexion successful";
         }
         else

             QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                         QObject::tr("connexion failed.\n""Click Cancel to exit."), QMessageBox::Cancel);

    return a.exec();
}
