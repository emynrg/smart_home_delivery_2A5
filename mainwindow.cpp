#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "promotion.h"
#include "historique_client.h"
#include <QMessageBox>
#include <QTextDocument>
#include <QTextStream>
#include <QComboBox>
#include <QTabWidget>
#include <QObject>
#include <QSqlTableModel>
#include <QSqlQuery>
#include <QDateEdit>
#include <QComboBox>
#include <QtPrintSupport/QPrintDialog>
#include <QtPrintSupport/QPrinter>
#include <QDialog>
#include <QSound>
#include <QValidator>
#include <QPropertyAnimation>
#include <QEasingCurve>
#include <QSequentialAnimationGroup>
#include <QState>
#include <QStateMachine>
#include <QSignalTransition>
#include <QPainter>

#include"fournisseur.h"
#include<QString>
#include"devis.h"
#include<QSound>
#include<QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintDialog>
#include<QStatusBar>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    ui->le_cin_historique->setValidator(new QIntValidator(10000000, 99999999, this));
    QValidator *validator_String=new QRegExpValidator(QRegExp("[A-Za-z ' ']+"),this);
    QValidator *validator_id_historique=new QRegExpValidator(QRegExp("[H-C]\\d{5}[0-9]"),this);
    QValidator *validator_id_promotion=new QRegExpValidator(QRegExp("[P]\\d{5}[0-9]"),this);
    //QValidator *validator_prix=new QRegExpValidator(QRegExp("[0-9]d{0,3}\\?(,)?"),this);
    ui->le_id_historique->setValidator(validator_id_historique);
    ui->le_id->setValidator(validator_id_promotion);
    ui->le_nom->setValidator(validator_String);
    ui->le_description->setValidator(validator_String);
    ui->le_nom_historique->setValidator(validator_String);
    ui->le_prenom_historique->setValidator(validator_String);
    ui->le_num_historique->setValidator((new QIntValidator(10000000,99999999,this)));

    ui->CIN->setValidator(new QIntValidator(1000000 ,99999999,this));

    ui->stackedWidget->setCurrentIndex(0);
    h.afficher();
    p.afficher();




    //*****************jamoussi
    ui->tabemploye->setModel(tmpemploye.Afficher_Employe());
    ui->tabemploye2->setModel(tmpemploye.Afficher_Employe());
    ui->tabconge->setModel(tmpconge.Afficher_conge());
    ui->tabconge2->setModel(tmpconge.Afficher_conge());

}

MainWindow::~MainWindow()
{
    delete ui;
}

QString rep;


void MainWindow::on_pb_affprom_clicked()
{
    QSound bts("D:/Téléchargements/CRUD/button-3.wav");
    bts.play();


    ui->tableView->setModel(p.afficher());
    ui->stackedWidget->setCurrentIndex(1);


}

void MainWindow::on_pb_valider_clicked()
{

    QPushButton button("Appuyer sur OK!");
    button.show();

    QPropertyAnimation animation(&button, "geometry");
    animation.setDuration(3000);
    animation.setStartValue(QRect(500, 500, 200, 30));
    animation.setEndValue(QRect(780, 280, 300, 50));

    animation.setEasingCurve(QEasingCurve::OutBounce);

    animation.start();

    QSound bts("D:/Téléchargements/CRUD/button-3.wav");
        bts.play();
    QString id=ui->le_id->text();
    float prix=ui->le_prix->text().toFloat();
    QString nom=ui->le_nom->text();
    QDate datefin=ui->de_datefin_promotion->date();
     QDate datedeb=ui->de_datedeb_promotion->date();
     QString description=ui->le_description->text();
 promotion p(id,prix,nom,datefin,datedeb,description);
 bool test=p.ajouter();
 on_pb_annuler_2_clicked();
 QMessageBox msgBox;

 if(test)
   {  msgBox.setText("Ajout avec succes.");
     ui->tableView->setModel(p.afficher());
 }
 else
     msgBox.setText("Echec d'ajout");
     msgBox.exec();
}



void MainWindow::on_pb_supprimer_clicked()
{
    QSound bts("D:/Téléchargements/CRUD/button-3.wav");
    bts.play();
    promotion p1; p1.setid(ui->le_recherche_promotion->text());
    bool test=p1.supprimer(p1.getid());
    QMessageBox msgBox;

    if(test)
        {msgBox.setText("Suppression avec succes.");
         ui->tableView->setModel(p.afficher());

        }
    else{
        msgBox.setText("Echec de suppression");
        msgBox.exec();
        }
}

void MainWindow::on_pb_ajouter_clicked()
{
    QSound bts("D:/Téléchargements/CRUD/button-3.wav");
    bts.play();
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pb_annuler_2_clicked()
{
    //animationGroup->start();
    QSound bts("D:/Téléchargements/CRUD/button-3.wav");
    bts.play();
    QDate d=QDate::currentDate();
    ui->le_id->setText("");
    ui->le_nom->setText("");
    ui->le_prix->setText("");
    ui->le_description->setText("");
    ui->de_datedeb_promotion->setDate(d);
    ui->de_datefin_promotion->setDate(d);
}

void MainWindow::on_pb_afficher_historique_clicked()
{


    QSound bts("D:/Téléchargements/CRUD/button-3.wav");
    bts.play();
    ui->tableView_2->setModel(h.afficher());
    ui->stackedWidget->setCurrentIndex(3);


}

void MainWindow::on_pb_ajouter_historique_clicked()
{
    QSound bts("D:/Téléchargements/CRUD/button-3.wav");
    bts.play();
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pb_promotion_historique_clicked()
{
    QSound bts("D:/Téléchargements/CRUD/button-3.wav");
    bts.play();
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pb_historique_promotion_clicked()
{
    QSound bts("D:/Téléchargements/CRUD/button-3.wav");
    bts.play();
    ui->stackedWidget->setCurrentIndex(2);
}



void MainWindow::on_pb_valider_historique_clicked()
{
    QPushButton button("Appuyer sur OK");
    button.show();

    QPropertyAnimation animation(&button, "geometry");
    animation.setDuration(3000);
    animation.setStartValue(QRect(500, 500, 200, 30));
    animation.setEndValue(QRect(780, 280, 300, 50));

    animation.setEasingCurve(QEasingCurve::OutBounce);

    animation.start();

    QSound bts("D:/Téléchargements/CRUD/button-3.wav");
    bts.play();
    QSqlQuery query;
    if(ui->oui_historique->isChecked()==true)
        rep="oui";
    else
        if(ui->non_historique->isChecked()==true)
            rep="non";
    query.prepare ("INSERT INTO historique_clients (promotion) "
                   "VALUES (rep)");

    QString id=ui->le_id_historique->text();
    QString nom=ui->le_nom_historique->text();
    QString prenom=ui->le_prenom_historique->text();
    QString cin=ui->le_cin_historique->text();
    QString num =ui->le_num_historique->text();
    QDate date=ui->de_historique->date();
    QString promotion=rep;
    historique h(id,nom,prenom,cin,num,date,promotion);
    bool test=h.ajouter();
        on_pb_annule_historique_clicked();
        QMessageBox msgBox;

    if(test)
       {
            msgBox.setText("Ajout avec succes.");
            ui->tableView_2->setModel(h.afficher());
       }
    else
            msgBox.setText("Echec d'ajout");
            msgBox.exec();
       }



void MainWindow::on_pb_annule_historique_clicked()
{
    QSound bts("D:/Téléchargements/CRUD/button-3.wav");
    bts.play();
    QDate d=QDate::currentDate();
    ui->le_id_historique->setText("");
    ui->le_nom_historique->setText("");
    ui->le_prenom_historique->setText("");
    ui->le_cin_historique->setText("");
    ui->le_num_historique->setText("");
    ui->de_historique->setDate(d);
    ui->oui_historique->setChecked(0);
    ui->non_historique->setChecked(0);

}

void MainWindow::on_pb_supprimer_historique_clicked()
{
    QSound bts("D:/Téléchargements/CRUD/button-3.wav");
    bts.play();
    historique h; h.setid(ui->le_recherche_historique->text());
    bool test=h.supprimer(h.getid());
    QMessageBox msgBox1;

    if(test)
       { msgBox1.setText("Suppression avec succes.");
    ui->tableView_2->setModel(h.afficher());

    }
    else{
        msgBox1.setText("Echec de suppression");
        msgBox1.exec();
    }
}



void MainWindow::on_pb_modifier_promotion_clicked()
{
    QSound bts("D:/Téléchargements/CRUD/button-3.wav");
    bts.play();
    QString id = ui->le_id->text();
    QString nom = ui->le_nom->text();
    QString description= ui->le_description->text();
    float prix= ui->le_prix->text().toFloat();
    QDate datedeb = ui->de_datedeb_promotion->date();
    QDate datefin = ui->de_datefin_promotion->date();

    promotion p(id,prix,nom,datedeb,datefin,description) ;
    bool test =p.modifier(id,prix,nom,datedeb,datefin,description);
    if(test)
    {ui->tableView->setModel(p.afficher());
        QMessageBox::information(nullptr, QObject::tr("modifier une promotion"),
                                 QObject::tr("promotion modifiée.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);}
    else
        QMessageBox::critical(nullptr, QObject::tr("Modifier une promotion"),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
}



void MainWindow::on_pb_modifier_historique_clicked()
{
    QSound bts("D:/Téléchargements/CRUD/button-3.wav");
    bts.play();
    QSqlQuery query;
    if(ui->oui_historique->isChecked()==true)
        rep="oui";
    else
        if(ui->non_historique->isChecked()==true)
            rep="non";
    QString id = ui->le_id_historique->text();
    QString nom = ui->le_nom_historique->text();
    QString prenom= ui->le_prenom_historique->text();
    QString cin= ui->le_cin_historique->text();
    QString num= ui->le_num_historique->text();
    QDate date= ui->de_historique->date();
    QString promotion =rep ;

    historique h(id,nom,prenom,cin,num,date,promotion);
    bool test =h.modifier(id,nom,prenom,cin,num,date,promotion);

    if(test)
    {ui->tableView_2->setModel(h.afficher());
        QMessageBox::information(nullptr, QObject::tr("Modifier un client"),
                                 QObject::tr("client  modifié.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
        on_pb_annule_historique_clicked();
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Modifier un client"),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
}



void MainWindow:: on_le_recherche_promotion_textChanged(const QString &arg1)
{

        if(ui->le_recherche_promotion->text() == "")
            {
                ui->tableView->setModel(p.afficher());
            }
            else
            {
                 ui->tableView->setModel(p.rechercher(ui->le_recherche_promotion->text()));
            }

}



void MainWindow::on_le_recherche_historique_textChanged(const QString &arg1)
{
    if(ui->le_recherche_historique->text() == "")
        {
            ui->tableView_2->setModel(h.afficher());
        }
        else
        {
             ui->tableView_2->setModel(h.rechercher(ui->le_recherche_historique->text()));
        }
}

void MainWindow::on_pb_selection_historique_clicked()
{
            QSound bts("D:/Téléchargements/CRUD/button-3.wav");
            bts.play();

           int row=ui->tableView_2->selectionModel()->currentIndex().row();
           QString id=ui->tableView_2->model()->index(row,0).data().toString();
           QString nom=ui->tableView_2->model()->index(row,1).data().toString();
           QString prenom=ui->tableView_2->model()->index(row,2).data().toString();
           QString cin=ui->tableView_2->model()->index(row,3).data().toString();
           QString num=ui->tableView_2->model()->index(row,4).data().toString();
           QDate date=ui->tableView_2->model()->index(row,5).data().toDate();
           QString promotion=ui->tableView_2->model()->index(row,6).data().toString();
           if(row==-1)
           {
               QMessageBox ::information(nullptr,QObject::tr("modifier un client"),
                                                 QObject::tr("aucune selection.\n"
                                                     "click ok to exit"),QMessageBox::Ok);
           }
           else
           {
               ui->le_id_historique->setText(id);
               ui->le_nom_historique->setText(nom);
               ui->le_prenom_historique->setText(prenom);
               ui->le_cin_historique->setText(cin);
               ui->le_num_historique->setText(num);
               ui->de_historique->setDate(date);
               if(promotion=="oui")
                   ui->oui_historique->setChecked(1);
               else if(promotion=="non")
                   ui->non_historique->setChecked(1);

           }
           ui->stackedWidget->setCurrentIndex(2);

}

void MainWindow::on_pb_select_promotion_clicked()
{
    QSound bts("D:/Téléchargements/CRUD/button-3.wav");
    bts.play();
    int row=ui->tableView->selectionModel()->currentIndex().row();
           QString id=ui->tableView->model()->index(row,0).data().toString();
           QString nom=ui->tableView->model()->index(row,2).data().toString();
           QString description=ui->tableView->model()->index(row,5).data().toString();
           QDate datedeb=ui->tableView->model()->index(row,3).data().toDate();
           QDate datefin=ui->tableView->model()->index(row,4).data().toDate();
           float prix=ui->tableView->model()->index(row,1).data().toFloat();
           QString prix_string=QString:: number(prix);
           if(row==-1)
           {
               QMessageBox ::information(nullptr,QObject::tr("modifier un client"),
                                                 QObject::tr("aucune selection.\n"
                                                     "click ok to exit"),QMessageBox::Ok);
           }
           else
           {
               ui->le_id->setText(id);
               ui->le_nom->setText(nom);
               ui->le_description->setText(description);
               ui->de_datedeb_promotion->setDate(datedeb);
               ui->de_datefin_promotion->setDate(datefin);
               ui->le_prix->setText(prix_string);
           }

           ui->stackedWidget->setCurrentIndex(0);
}





void MainWindow::on_pb_trier_historique_clicked()
{
    QSound bts("D:/Téléchargements/CRUD/button-3.wav");
    bts.play();
    QString critere=ui->cb_historique->currentText();
        QString mode;
         if (ui->rb_asc_historique->isChecked()==true)
    {
             mode="ASC";
    }
         else if(ui->rb_desc_historique->isChecked()==true)
         {
             mode="DESC";
         }
      ui->tableView_2->setModel(h.trier(critere,mode));
}


void MainWindow::on_pb_trier_promotion_clicked()
{
    QSound bts("D:/Téléchargements/CRUD/button-3.wav");
    bts.play();
    QString critere=ui->cb_promotion->currentText();
        QString mode;
         if (ui->rb_asc_promotion->isChecked()==true)
    {
             mode="ASC";
    }
         else if(ui->rb_desc_promotion->isChecked()==true)
         {
             mode="DESC";
         }
      ui->tableView->setModel(p.trier(critere,mode));
}

void MainWindow::on_pb_imprimer_historique_clicked()
{
    QSound bts("D:/Téléchargements/CRUD/button-3.wav");
    bts.play();
    QPrinter printer;
    printer.setPrinterName ("le nom de l'imprimante");
    QPrintDialog dialog(&printer,this);
    if (dialog.exec()== QDialog::Rejected)return;
    ui->tableView_2->render(&printer);

}


void MainWindow::on_pb_imprimer_promotion_clicked()
{
    QSound bts("D:/Téléchargements/CRUD/button-3.wav");
    bts.play();
    QPrinter printer;
    printer.setPrinterName ("le nom de l'imprimante");
    QPrintDialog dialog(&printer,this);
    if (dialog.exec()== QDialog::Rejected)return;
    ui->tableView->render(&printer);
}

void MainWindow::on_cb_choix_historique_activated(const QString &arg1)
{

    //ui->cb_choix_historique->setModel(p.afficher());

}
//***************jamoussi********************************************************************************************************
//***************jamoussi********************************************************************************************************







void MainWindow::on_pushButton_clicked()
{musicClick();
    ui->stackedWidget->setCurrentIndex(4);

}

void MainWindow::on_pushButton_2_clicked()
{musicClick();
    ui->stackedWidget->setCurrentIndex(4);

}

void MainWindow::on_pushButton_3_clicked()
{musicClick();
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_pushButton_4_clicked()
{musicClick();
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_pushButton_5_clicked()
{musicClick();
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_pushButton_6_clicked()
{musicClick();
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_pushButton_afficheremp_clicked()
{musicClick();
  ui->stackedWidget->setCurrentIndex(7);

}

void MainWindow::on_pushButton_ajouteremploye_clicked()
{musicClick();
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_pushButton_modifieremploye_clicked()
{musicClick();
    ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_pushButton_ajouterconge_clicked()
{musicClick();
    ui->stackedWidget->setCurrentIndex(8);
}

void MainWindow::on_pushButton_modifierconge_clicked()
{musicClick();
    ui->stackedWidget->setCurrentIndex(9);

}

void MainWindow::on_pushButton_afficherconge_clicked()
{musicClick();
    ui->stackedWidget->setCurrentIndex(10);
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
    ui->stackedWidget->setCurrentIndex(4);
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
    musicC->setMedia(QUrl("qrc:/icons/10706.mp3"));
    musicC->setVolume(200);
    musicC->play();
}
//********************************PDF********************************



void MainWindow::on_pushButton_pdf_clicked()
{musicClick();
    QPrinter printer;
                printer.setOutputFormat(QPrinter::PdfFormat);
                printer.setOutputFileName("D://Téléchargements//CRUD//pdf//employe.pdf");
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

void MainWindow::on_pb_login_promotion_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pb_login_rh_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_pb_rh_login_clicked()
{
    ui->stackedWidget->setCurrentIndex(11);
}

void MainWindow::on_pb_promotion_login_clicked()
{
    ui->stackedWidget->setCurrentIndex(11);

}


//******************************************************************************************************************************
// rrrrrrrrrrrrrrrrrrrrgaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaayaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
void MainWindow::on_pushButton_ajouterfourni_clicked()
{ fournisseur f;
    f.set_ID(ui->ID->text());
    f.set_NOM(ui->NOM->text());
    f.set_prenom(ui->PRENOM->text());
    f.set_ADRESSE(ui->ADRESSE->text());
    f.set_CIN(ui->CIN->text());
    f.ajouterFournisseur();
     ui->stackedWidget->setCurrentIndex(13);
    ui->ID->clear();
    ui->NOM->clear();
    ui->PRENOM->clear();
    ui->ADRESSE->clear();
    ui->CIN->clear();


}



void MainWindow::on_Button_affichefourni_clicked()
{
    fournisseur f;
    ui->stackedWidget->setCurrentIndex(15);
ui->affichage_fournisseur->setModel(f.afficherFournisseur());
ui->affichage_fournisseur->resizeRowsToContents();
ui->affichage_fournisseur->resizeColumnsToContents();
ui->affichage_fournisseur->show();

}

void MainWindow::on_button_updatfourni_clicked()
{
    ui->stackedWidget->setCurrentIndex(16);
    update_fournisseur();
}


void MainWindow::update_fournisseur()
{
    fournisseur f;
    QStringList Titres;
        Titres <<"   ID " <<"  NOM  "<<" PRENOM "<<" ADRESSE   "<<" CIN    ";
        ui->tableauModification->resizeColumnsToContents();

        ui->tableauModification->setColumnCount(5);
        ui->tableauModification->setHorizontalHeaderLabels(Titres);

    ui->affichage_fournisseur->setModel(f.afficherFournisseur());
    ui->tableauModification->setRowCount(0);

   for(int row=0;row<ui->affichage_fournisseur->model()->rowCount();++row)

   {ui->tableauModification->insertRow(ui->tableauModification->rowCount());

       for(int col=0;col< ui->affichage_fournisseur->model()->columnCount();++col)
       {

                   QModelIndex index =ui->affichage_fournisseur->model()->index(row,col);

               ui->tableauModification->setItem(row,col,new QTableWidgetItem(index.data().toString()));

               ui->tableauModification->setItem(row,col,new QTableWidgetItem(index.data().toString()));

               ui->tableauModification->setItem(row,col,new QTableWidgetItem(index.data().toString()));

               ui->tableauModification->setItem(row,col,new QTableWidgetItem(index.data().toString()));

               ui->tableauModification->setItem(row,col,new QTableWidgetItem(index.data().toString()));


                  }




   }

}


void MainWindow::on_tableauModification_cellChanged(int row, int column)
{
     fournisseur f;
     const QAbstractItemModel *model=ui->tableauModification->model();
     const QString identifiant= model->data(model->index(row,0),Qt::DisplayRole).toString();
     const QString nom=model->data(model->index(row,1),Qt::DisplayRole).toString();
     const QString prenom=model->data(model->index(row,2),Qt::DisplayRole).toString();
     const QString adresse=model->data(model->index(row,3),Qt::DisplayRole).toString();
    const QString cin=model->data(model->index(row,4),Qt::DisplayRole).toString();

    f.update_F(identifiant,nom,prenom,adresse,cin,column);
}



void MainWindow::on_backamine_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(13);
}

void MainWindow::on_backamine_3_clicked()
{
     ui->stackedWidget->setCurrentIndex(13);
}

void MainWindow::on_backamine_4_clicked()
{
     ui->stackedWidget->setCurrentIndex(13);
}


void MainWindow::on_ajouterfournibouton_clicked()
{
    ui->stackedWidget->setCurrentIndex(14);
}






void MainWindow::on_supprimerfourni_bouton_clicked()
{
    fournisseur f;
    //ui->linesupprimer->text();
    QString id;

   f.supprimer(ui->linesupprimer->text());
   ui->affichage_fournisseur->setModel(f.afficherFournisseur());
    update_fournisseur();
    ui->linesupprimer->clear();

}
void MainWindow::on_pushButton_CHERCHERfourni_clicked()
{
    fournisseur f;
    if(ui->lineEdit_CHERCHER->text() == "")
              {
                  ui->affichage_fournisseur->setModel(f.afficherFournisseur());
              }
              else
              {
                   ui->affichage_fournisseur->setModel(f.rechercher(ui->lineEdit_CHERCHER->text()));
              }
    ui->lineEdit_CHERCHER->clear();
}

void MainWindow::on_backamine_clicked()
{
    ui->stackedWidget->setCurrentIndex(12);
}

void MainWindow::on_boutonGestionFournisseur_clicked()
{
    QSound bts("C:/Users/DELL/Documents/GestionFournisseur/click.wav");
    bts.play();
    ui->stackedWidget->setCurrentIndex(13);

}

void MainWindow::on_backamine_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(12);
}

void MainWindow::on_BoutonGestionDevis_clicked()
{
    ui->stackedWidget->setCurrentIndex(17);
}

void MainWindow::on_ajouterbouton_devis_clicked()
{


    ui->stackedWidget->setCurrentIndex(18);
}

void MainWindow::on_afficherbouton_devis_clicked()
{  //bouton  from devis (CRUD) to devis LIST
    devis d;
    ui->stackedWidget->setCurrentIndex(20);
    ui->tableViewDevis->setModel(d.afficherDevis());
    ui->tableViewDevis->resizeRowsToContents();
    ui->tableViewDevis->resizeColumnsToContents();
    ui->tableViewDevis->show();

}
void MainWindow::on_pushButton_exporterdevis_clicked()
{ devis d;
    d.exporter(ui->tableViewDevis );
           // ui->statusbar->showMessage("EXPORT TABLE ",5000);
}



void MainWindow::on_backamine_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(17);
}

void MainWindow::on_backamine_7_clicked()
{
    ui->stackedWidget->setCurrentIndex(17);
}
void MainWindow::on_backamine_8_clicked()
{
    ui->stackedWidget->setCurrentIndex(17);
}
//PARTIE DEVIS
void MainWindow::on_ajouterdevis_clicked()
{
     devis d;
        d.set_code(ui->CODE->text());
        d.set_destination(ui->DESTINATION->text());
        d.set_type_de_livraison(ui->TYPE_DE_LIVRAISON->text());
        d.set_quantite(ui->QUANTITE->text());
        d.set_prix(ui->PRIX->text());
        d.set_id_fournisseur(ui->ID_FOURNISSEUR->text());
        d.ajouterDevis();
         ui->stackedWidget->setCurrentIndex(17);
        ui->CODE->clear();
        ui->DESTINATION->clear();
        ui->TYPE_DE_LIVRAISON->clear();
        ui->QUANTITE->clear();
        ui->PRIX->clear();
        ui->ID_FOURNISSEUR->clear();
}


void MainWindow::on_modifierbouton_devis_clicked()
{
    ui->stackedWidget->setCurrentIndex(20);
    update_DEVIS();

}


void MainWindow:: update_DEVIS()
{
    devis d;

    QStringList Titres;
        Titres <<"  CODE " <<" DESTINATION  "<<" TYPE_DE_LIVRAISON "<<" QUANTITE  "<<" PRIX"<<"ID_FOURNISSEUR";
        ui->tableWidgetdevis->resizeColumnsToContents();

        ui->tableWidgetdevis->setColumnCount(6);
        ui->tableWidgetdevis->setHorizontalHeaderLabels(Titres);

    ui->tableViewDevis->setModel(d.afficherDevis());
    ui->tableWidgetdevis->setRowCount(0);

   for(int row=0;row<ui->tableViewDevis->model()->rowCount();++row)

   {ui->tableWidgetdevis->insertRow(ui->tableWidgetdevis->rowCount());

       for(int col=0;col< ui->tableViewDevis->model()->columnCount();++col)
       {

                   QModelIndex index =ui->tableViewDevis->model()->index(row,col);

               ui->tableWidgetdevis->setItem(row,col,new QTableWidgetItem(index.data().toString()));

               ui->tableWidgetdevis->setItem(row,col,new QTableWidgetItem(index.data().toString()));

               ui->tableWidgetdevis->setItem(row,col,new QTableWidgetItem(index.data().toString()));

               ui->tableWidgetdevis->setItem(row,col,new QTableWidgetItem(index.data().toString()));

               ui->tableWidgetdevis->setItem(row,col,new QTableWidgetItem(index.data().toString()));
               ui->tableWidgetdevis->setItem(row,col,new QTableWidgetItem(index.data().toString()));


                  }




   }
}



void MainWindow::on_tableWidgetdevis_cellChanged(int row, int column)
{
    devis d;

    const QAbstractItemModel *model=ui->tableWidgetdevis->model();

    const QString code= model->data(model->index(row,0),Qt::DisplayRole).toString();
    const QString destination=model->data(model->index(row,1),Qt::DisplayRole).toString();
    const QString type_de_livraison=model->data(model->index(row,2),Qt::DisplayRole).toString();
    const QString quantite=model->data(model->index(row,3),Qt::DisplayRole).toString();
    const QString prix=model->data(model->index(row,4),Qt::DisplayRole).toString();
    const QString id_fournisseur=model->data(model->index(row,5),Qt::DisplayRole).toString();

    d.update_D(code , destination, type_de_livraison,  quantite ,  prix , id_fournisseur, column );
}




void MainWindow::on_pushButton_supprimerDevis_clicked()
{
    devis d ;
    d.supprimer(ui->lineEdit_supprimerparID->text());
    ui->tableViewDevis->setModel(d.afficherDevis());
     update_DEVIS();
     ui->linesupprimer->clear();

}




void MainWindow::on_pushButton_IMPRIMERdevis_clicked()
{
    QPrinter printer;
    printer.setPrinterName ("le nom de l'imprimante");
        QPrintDialog dialog(&printer,this);
        if (dialog.exec()== QDialog::Rejected)return;
        ui->tableViewDevis->render(&printer);
}










void MainWindow::on_pb_login_rgaya_clicked()
{
    ui->stackedWidget->setCurrentIndex(12);
}

void MainWindow::on_pb_rgaya_login_clicked()
{
    ui->stackedWidget->setCurrentIndex(11);

}


