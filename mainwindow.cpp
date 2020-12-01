#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"fournisseur.h"
#include<QString>
#include"devis.h"
#include<QSound>
#include<QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintDialog>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->CIN->setValidator(new QIntValidator(1000000 ,99999999,this));//control saisie cin


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_2_clicked()
{ fournisseur f;
    f.set_ID(ui->ID->text());
    f.set_NOM(ui->NOM->text());
    f.set_prenom(ui->PRENOM->text());
    f.set_ADRESSE(ui->ADRESSE->text());
    f.set_CIN(ui->CIN->text());
    f.ajouterFournisseur();
     ui->stackedWidget->setCurrentIndex(1);
    ui->ID->clear();
    ui->NOM->clear();
    ui->PRENOM->clear();
    ui->ADRESSE->clear();
    ui->CIN->clear();


}



void MainWindow::on_Button_affiche_clicked()
{
    fournisseur f;
    ui->stackedWidget->setCurrentIndex(3);
ui->affichage_fournisseur->setModel(f.afficherFournisseur());
ui->affichage_fournisseur->resizeRowsToContents();
ui->affichage_fournisseur->resizeColumnsToContents();
ui->affichage_fournisseur->show();

}

void MainWindow::on_button_updat_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
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



void MainWindow::on_back_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_back_2_clicked()
{
     ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_back_clicked()
{
     ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_ajouterbouton_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}






void MainWindow::on_supprimer_bouton_clicked()
{
    fournisseur f;
    //ui->linesupprimer->text();
    QString id;

   f.supprimer(ui->linesupprimer->text());
   ui->affichage_fournisseur->setModel(f.afficherFournisseur());
    update_fournisseur();
    ui->linesupprimer->clear();

}
void MainWindow::on_pushButton_CHERCHER_clicked()
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

void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_boutonGestionFournisseur_clicked()
{
    QSound bts("C:/Users/DELL/Documents/GestionFournisseur/click.wav");
    bts.play();
    ui->stackedWidget->setCurrentIndex(1);

}

void MainWindow::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_BoutonGestionDevis_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_ajouterbouton_devis_clicked()
{


    ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_afficherbouton_devis_clicked()
{  //bouton  from devis (CRUD) to devis LIST
    devis d;
    ui->stackedWidget->setCurrentIndex(7);
    ui->tableViewDevis->setModel(d.afficherDevis());
    ui->tableViewDevis->resizeRowsToContents();
    ui->tableViewDevis->resizeColumnsToContents();
    ui->tableViewDevis->show();

}



void MainWindow::on_pushButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_pushButton_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}
void MainWindow::on_pushButton_7_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
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
         ui->stackedWidget->setCurrentIndex(5);
        ui->CODE->clear();
        ui->DESTINATION->clear();
        ui->TYPE_DE_LIVRAISON->clear();
        ui->QUANTITE->clear();
        ui->PRIX->clear();
        ui->ID_FOURNISSEUR->clear();
}


void MainWindow::on_modifierbouton_devis_clicked()
{
    ui->stackedWidget->setCurrentIndex(8);
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




void MainWindow::on_pushButton_IMPRIMER_clicked()
{
    QPrinter printer;
    printer.setPrinterName ("le nom de l'imprimante");
        QPrintDialog dialog(&printer,this);
        if (dialog.exec()== QDialog::Rejected)return;
        ui->tableViewDevis->render(&printer);
}
