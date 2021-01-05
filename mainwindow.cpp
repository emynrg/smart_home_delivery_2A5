#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QString>
#include <QMessageBox>
#include <QObject>
#include<QDate>
#include <QPrinter>
#include<QPainter>
#include <QWidget>
#include "employe.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{


    ui->setupUi(this);
    ui->tabemploye->setModel(tmpemploye.Afficher_Employe());
    ui->tabemploye2->setModel(tmpemploye.Afficher_Employe());
    ui->tabconge->setModel(tmpconge.Afficher_conge());
    ui->tabconge2->setModel(tmpconge.Afficher_conge());

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_clicked()
{musicClick();
    ui->stackedWidget->setCurrentIndex(0);

}

void MainWindow::on_pushButton_2_clicked()
{musicClick();
    ui->stackedWidget->setCurrentIndex(0);

}

void MainWindow::on_pushButton_3_clicked()
{musicClick();    ui->stackedWidget->setCurrentIndex(0);

}

void MainWindow::on_pushButton_4_clicked()
{musicClick();
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_5_clicked()
{musicClick();
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_6_clicked()
{musicClick();
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_afficheremp_clicked()
{musicClick();
  ui->stackedWidget->setCurrentIndex(3);

}

void MainWindow::on_pushButton_ajouteremploye_clicked()
{musicClick();
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_modifieremploye_clicked()
{musicClick();
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_ajouterconge_clicked()
{musicClick();
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_pushButton_modifierconge_clicked()
{musicClick();
    ui->stackedWidget->setCurrentIndex(5);

}

void MainWindow::on_pushButton_afficherconge_clicked()
{musicClick();
    ui->stackedWidget->setCurrentIndex(6);
}
//******************************************* ajouter employe ****************************************************************


void MainWindow::on_ajouteremp_clicked()
{musicClick();

    int id= ui->lineEdit_ID->text().toInt();
    QString nom= ui->lineEdit_Nom->text();
    QDate datedenaissance= ui->dateEdit_datedenaissance->date();
    QString email= ui->lineEdit_email->text();
    QString poste= ui->lineEdit_poste->text();
    QString codecarte= ui->lineEdit_codecarte->text();
    QString historiqueacces= ui->lineEdit_historiqueacces->text();
if(nom.isEmpty()){
    QMessageBox::critical(nullptr, QObject::tr("OK"),
                                       QObject::tr("veuillez remplire le champ Nom rt Prenom \n""Click Cancel to exit")
                                       ,QMessageBox::Cancel);
}
else {Employe e(id,nom,datedenaissance,email,poste,codecarte,historiqueacces);
    bool test=e.ajouter();
if (test)
{
    ui->tabemploye->setModel(tmpemploye.Afficher_Employe());
    ui->tabemploye2->setModel(tmpemploye.Afficher_Employe());

    QMessageBox::information(nullptr,QObject::tr("ajouter un employe"),QObject::tr("employe ajouté.\n"
                                                                                   "click cancel to exit."),QMessageBox::Cancel);
}
}}

//******************************************* supprimer employe ****************************************************************

void MainWindow::on_pushButton_supprimeremp_clicked()
{musicClick();
    int id=ui->lineEdit_id->text().toInt();
    bool test=tmpemploye.Supprimer_Employe(id);
    if(test)
    {
        ui->tabemploye->setModel(tmpemploye.Afficher_Employe());
        QMessageBox::information(nullptr,QObject::tr("supprimer un employe"),QObject::tr("employe supprimer.\n"
                                                                                       "click cancel to exit."),QMessageBox::Cancel);
    }
}
//******************************************* modifier employe ****************************************************************

void MainWindow::on_pushButton_modifierparid_clicked()
{musicClick();

    QSqlQuery query;
    int id= ui->lineEdit_ID_2->text().toInt();
        QString nom= ui->lineEdit_Nom_2->text();
        QDate datedenaissance= ui->dateEdit_datedenaissance_2->date();
        QString email= ui->lineEdit_email_2->text();
        QString poste= ui->lineEdit_poste_2->text();
        QString codecarte= ui->lineEdit_codecarte_2->text();
        QString historiqueacces= ui->lineEdit_historiqueacces_2->text();

Employe e(id,nom,datedenaissance,email,poste,codecarte,historiqueacces);
bool test =e.Modifier_Employe(id,nom,datedenaissance,email,poste,codecarte,historiqueacces);

    if(test)
    {ui->tabemploye->setModel(e.Afficher_Employe());
ui->tabemploye2->setModel(e.Afficher_Employe());
        QMessageBox::information(nullptr, QObject::tr("modifier un employe"),
                                 QObject::tr("employe  modifié.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
               {
                   QMessageBox ::critical(nullptr,QObject::tr("modifier un employe"),
                                                     QObject::tr("Erreur.\n"
                                                         "click cancel to exit"),QMessageBox::Cancel);

               }

}
//******************************************* ajouter conge ****************************************************************
void MainWindow::on_pushButton_ajouterunconge_clicked()
{musicClick();
    int code = ui->lineEdit_codeconge->text().toInt();
    int id = ui->l_id->text().toInt();
    int solde= ui->l_solde->text().toInt();
    QString historique =ui->l_historiqueconge->text();
    conge c(code,id,solde,historique);
    bool test=c.ajouter();
   if(code<1000){  QMessageBox::critical(nullptr, QObject::tr("OK"),
                                         QObject::tr("ERREUR,le code necessite 4 chiffres  \n""Click Cancel to exit")
                                         ,QMessageBox::Cancel);}
    else {
    if (test)
        {
            ui->tabconge->setModel(c.Afficher_conge());
            ui->tabconge2->setModel(c.Afficher_conge());


            QMessageBox::information(nullptr,QObject::tr("ajouter un conger"),QObject::tr("conge ajouté.\n"
                                                                                           "click cancel to exit."),QMessageBox::Cancel);

        }}
}
//******************************************* supprimer conge ****************************************************************

void MainWindow::on_pushButton_211_clicked()
{musicClick();
    int code=ui->lineEdit_supp->text().toInt();
    bool test=tmpconge.Supprimer_conge(code);
    if(test)
    {
        ui->tabconge->setModel(tmpconge.Afficher_conge());
        QMessageBox::information(nullptr,QObject::tr("supprimer un conger"),QObject::tr("conge supprimer.\n"
                                                                                       "click cancel to exit."),QMessageBox::Cancel);
    }
}
//******************************************* modifier conge ****************************************************************


//*******************************************************************************************
void MainWindow::on_pushButton_204_clicked()
{musicClick();
    ui->stackedWidget->setCurrentIndex(0);
}
//*********************************TRI*****
void MainWindow::on_pushButton_212_clicked()
{musicClick();
    ui->tabconge->setModel(tmpconge.TRIER_conge());

}

//*********************chercher*********************************
void MainWindow::on_chercherbut_clicked()
{musicClick();
    QString text;

     text=ui->lineEdit_supp->text();

     if(text == "")

     {

         ui->tabconge->setModel(tmpconge.Afficher_conge());

     }

     else

     {
         ui->tabconge->setModel(tmpconge.CHERCHER_conge(text));
     }
}
//***************************************************************
void MainWindow::musicClick()
{
    musicC=new QMediaPlayer();
    musicC->setMedia(QUrl("qrc:/Sound/sound/10706.mp3"));
    musicC->setVolume(200);
    musicC->play();
}
//********************************PDF********************************



void MainWindow::on_pushButton_pdf_clicked()
{musicClick();
    QPrinter printer;
                printer.setOutputFormat(QPrinter::PdfFormat);
                printer.setOutputFileName("C://Users//azizj//Pictures//Atelier_Connexion//pdf//employe.pdf");
                QPainter painter;

                if (! painter.begin(&printer)) { // failed to open file
                    qWarning("failed to open file, is it writable?");
                }

                QSqlQuery   query ;
                qDebug() << query.prepare("select sysdate from dual ");
                if ( query.exec() )
                {

                    QString S= QDate::currentDate().toString();
                    painter.drawText(850,50,S);
                    QPen penred(Qt::black);

                    painter.setFont(QFont("Arial", 30));
                    penred.setWidth(1);
                    painter.setPen(penred);

                    painter.drawText(350,100," Employes ");
                    painter.setFont(QFont("Arial",30));
                    painter.setPen(Qt::black);

                }

                QString ID ,nom,datedenaissance,email,poste,codecarte, historiqueacces;
                QSqlQuery   qry ;
                int i =50;
                int k=0;
                qDebug() << qry.prepare("select * from employe ");

                if ( qry.exec() )
                {

                    while(qry.next())
                    {

                        if ( k % 13 ==0)
                        {   i=250;
                            painter.setFont(QFont("Arial",10));
                            QPen penblack(Qt::black);

                            painter.setPen(penblack);
            painter.drawText (0,200,"id");
            painter.drawText (90,200,"nom");
            painter.drawText (230,200,"date_de_naissance");
            painter.drawText (420,200,"email");
            painter.drawText (530,200,"poste");
            painter.drawText(630,200," codecarte");
            painter.drawText(780,200,"historique_acces ");
                        }

                        painter.setFont(QFont("Arial",10));
                        QPen penblack(Qt::black);

                        painter.setPen(penblack);
                        int j=0;
                        ID= qry.value(0).toString();
                        painter.drawText(j*20,i, ID);
                        j++;
                        nom=qry.value(1).toString();
                        painter.drawText(j*90,i, nom);
                        j++;
                       datedenaissance=qry.value(2).toString();
                        painter.drawText(j*100,i, datedenaissance);
                        j++;
                        poste=qry.value(3).toString();
                        painter.drawText(j*139,i, poste);
                        j++;
                       email=qry.value(4).toString();
                        painter.drawText(j*140,i, email);
                        j++;
                       codecarte=qry.value(5).toString();
                         painter.drawText(j*140,i, codecarte);
                         j++;
                         historiqueacces=qry.value(6).toString();
                           painter.drawText(j*140,i, historiqueacces);
                        i+=80;
                        k++;

                    }
                }

                painter.end();
}

//****************************MODIFIER CONGE*********************************

void MainWindow::on_pushButton_205_clicked()
{
    musicClick();
    QSqlQuery query;
    int code = ui->lineEdit_codeconge_2->text().toInt();
    int id = ui->l_id_2->text().toInt();
    int solde= ui->l_solde_2->text().toInt();
    QString historique =ui->l_historiqueconge_2->text();
    conge c(code,id,solde,historique);
bool test =c.Modifier_conge(code,id,solde,historique);

    if(test)
    { ui->tabconge->setModel(c.Afficher_conge());
        ui->tabconge2->setModel(c.Afficher_conge());

        QMessageBox::information(nullptr, QObject::tr("modifier un conge"),
                                 QObject::tr("conge  modifié.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
               {
                   QMessageBox ::critical(nullptr,QObject::tr("modifier un conge"),
                                                     QObject::tr("Erreur.\n"
                                                         "click cancel to exit"),QMessageBox::Cancel);

               }
}


void MainWindow::on_pushButton_213_clicked()
{
    musicClick();
        ui->tabconge->setModel(tmpconge.TRIER2_conge());
}
