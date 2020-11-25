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

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{


    ui->setupUi(this);
    //ui->le_id->setValidator(new QIntValidator(10, 99999, this));
    //ui->le_id_historique->setValidator(new QIntValidator(10, 99999, this));

    ui->stackedWidget->setCurrentIndex(0);
    h.afficher();
    p.afficher();
}

MainWindow::~MainWindow()
{
    delete ui;
}

QString rep;


void MainWindow::on_pb_affprom_clicked()
{
    ui->tableView->setModel(p.afficher());
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pb_valider_clicked()
{
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
    promotion p1; p1.setid(ui->le_recherche_promotion->text());
    bool test=p1.supprimer(p1.getid());
    QMessageBox msgBox;

    if(test)
       { msgBox.setText("Suppression avec succes.");
    ui->tableView->setModel(p.afficher());

    }
    else{
        msgBox.setText("Echec de suppression");
        msgBox.exec();
    }
}

void MainWindow::on_pb_ajouter_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pb_annuler_2_clicked()
{
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
    ui->tableView_2->setModel(h.afficher());
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_pb_ajouter_historique_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pb_promotion_historique_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pb_historique_promotion_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}



void MainWindow::on_pb_valider_historique_clicked()
{
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
        QMessageBox::information(nullptr, QObject::tr("modifier un client"),
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

void MainWindow::on_pb_tri_nom_historique_clicked()
{
    ui->tableView_2->setModel(h.trie());
}


void MainWindow::on_pb_tri_prix_promotion_clicked()
{
    ui->tableView->setModel(p.trie());
}
