#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"enregistrement.h"
#include"historique.h"
#include <QApplication>
#include <QMessageBox>
#include<QPainter>
#include<QtPrintSupport/QPrinter>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(3);
}

MainWindow::~MainWindow()
{
    delete ui;
}



    //void MainWindow::on_pushButton_4_clicked()
    //{


    //}


void MainWindow::on_pushButton_2_clicked()
{
    ui->page->show();
    ui->page_3->hide();
}

void MainWindow::on_pushButton_clicked()
{
   ui->page_1->show();
   ui->page_3->hide();
}

void MainWindow::on_pushButton_5_clicked()
{


        int numero_de_livraison =ui->lineEdit->text().toInt();
        QString type =ui->lineEdit_2->text();
        QString description =ui->lineEdit_3->text();
         QString date_de_reclamation =ui->lineEdit_4->text();
        enregistrement e(numero_de_livraison, type, description, date_de_reclamation);

        bool test =e.ajouter();
        if (test)
        {ui->tablereclamation->setModel(tmpreclamation.afficher());
            QMessageBox :: information(nullptr,QObject::tr("ajouter une reclamation "),
                             QObject::tr("reclamation ajouter\n"
                                         "click cancel to exit "),QMessageBox ::Cancel          );
        }
        else
           {  QMessageBox :: critical(nullptr,QObject::tr("ajouter une reclamation "),
                                         QObject::tr("erreur\n"
                                                     "click cancel to exit "),QMessageBox ::Cancel          );



        }

}

void MainWindow::on_pushButton_6_clicked()
{
    ui->page_4->show();
    ui->page_1->hide();
    ui->page_3->hide();
    ui->page->hide();
}

void MainWindow::on_pushButton_7_clicked()
{
    ui->page_3->show();
    ui->page_1->hide();
    ui->page->hide();
}

void MainWindow::on_pushButton_8_clicked()
{
    ui->page->show();
}

void MainWindow::on_pushButton_9_clicked()
{
   int numero_de_livraison =ui->lineEdit_5->text().toInt();
    QString type =ui->lineEdit_6->text();
    QString description =ui->lineEdit_7->text();
     QString date_de_reclamation =ui->lineEdit_8->text();
    enregistrement e(numero_de_livraison, type, description, date_de_reclamation);
            bool test=e.modifier();
           if(test)
           { ui->tablereclamation->setModel(tmpreclamation.afficher());

               QMessageBox ::information(nullptr,QObject::tr("modifier une reclamation"),
                                                 QObject::tr("reclamation  modifié.\n"
                                                     "click ok to exit"),QMessageBox::Ok);

           }
           else
           {
               QMessageBox ::critical(nullptr,QObject::tr("modifier une reclamation"),
                                                 QObject::tr("Erreur.\n"
                                                     "click cancel to exit"),QMessageBox::Cancel);

           }
           ui->tablereclamation->setModel(tmpreclamation.afficher());
}

void MainWindow::on_pushButton_10_clicked()
{
    ui->page_1->show();
    ui->page_4->hide();

}

void MainWindow::on_pushButton_12_clicked()
{


        int   numero_de_livraison =ui->lineEdit_9->text().toInt();
        bool test =tmpreclamation.supprimer(numero_de_livraison);
        if(test)
        {ui->tablereclamation->setModel(tmpreclamation.afficher());
            QMessageBox ::information(nullptr,QObject::tr("suprimer une reclamation"),
                                      QObject::tr("reclamation supprmier \n"
                                                  "click cancel to exit"),QMessageBox::Cancel);

    }
        else {
            QMessageBox ::critical(nullptr,QObject::tr("suprimer une reclamtion"),
                                      QObject::tr("erreur \n"
                                                  "click cancel to exit"),QMessageBox::Cancel);


        }
        ui->page_1->show();
        ui->page_5->hide();

}

void MainWindow::on_pushButton_11_clicked()
{
    ui->page_5->show();
    ui->page_1->hide();
}

/*void MainWindow::on_pushButton_13_clicked()
{

    int nombre =ui->lineEdit->text().toInt();
    QString identifiant_reclamation =ui->lineEdit_2->text();
    QString pourcentage_de_reclamation =ui->lineEdit_3->text();
    QString pourcentage_augmantation =ui->lineEdit_4->text();//
     QString date_ =ui->lineEdit_5->text();
    historique e(nombre,identifiant_reclamation,pourcentage_de_reclamation, pourcentage_augmentation ,date_);

    bool test =e.ajouter();
    if (test)
    {ui->table_historique->setModel(tmpreclamation.afficher());
        QMessageBox :: information(nullptr,QObject::tr("ajouter une reclamation "),
                         QObject::tr("reclamation ajouter\n"
                                     "click cancel to exit "),QMessageBox ::Cancel          );
    }
    else
       {  QMessageBox :: critical(nullptr,QObject::tr("ajouter une reclamation "),
                                     QObject::tr("erreur\n"
                                                 "click cancel to exit "),QMessageBox ::Cancel          );



    }

}*/





void MainWindow::on_pushButton_78_clicked()
{
    int nombre =ui->lineEdit_73->text().toInt();
     QString identifiant_reclamation=ui->lineEdit_71->text();
     QString pourcentage_de_reclamation =ui->lineEdit_11->text();
      QString pourcentage_augmentation =ui->lineEdit_12->text();
      QString date_ =ui->lineEdit_72->text();
     historique h (nombre, identifiant_reclamation,  pourcentage_de_reclamation, pourcentage_augmentation , date_);
             bool test=h.modifier();
            if(test)
            { ui->tabel_historique->setModel(tmphistorique.afficher());

                QMessageBox ::information(nullptr,QObject::tr("modifier une reclamation"),
                                                  QObject::tr("reclamation  modifié.\n"
                                                      "click ok to exit"),QMessageBox::Ok);

            }
            else
            {
                QMessageBox ::critical(nullptr,QObject::tr("modifier une reclamation"),
                                                  QObject::tr("Erreur.\n"
                                                      "click cancel to exit"),QMessageBox::Cancel);

            }
            ui->tabel_historique->setModel(tmphistorique.afficher());
}



void MainWindow::on_pushButton_77_clicked()
{
     ui->stackedWidget->setCurrentIndex(4);
}




void MainWindow::on_pushButton_13_clicked()
{

    QString identifiant_reclamation =ui->lineEdit_idrec->text();
    QString date_ =ui->lineEdit_datee->text();
    int nombre =ui->lineEdit_nbrr->text().toInt();
    QString  pourcentage_de_reclamation=ui->lineEdit_pour->text();
     QString pourcentage_augmentation =ui->lineEdit_au->text();
    historique h(nombre,identifiant_reclamation,pourcentage_de_reclamation,pourcentage_augmentation,date_);

    bool test =h.ajouter();
    if (test)
    {ui->tabel_historique->setModel(tmphistorique.afficher());
        QMessageBox :: information(nullptr,QObject::tr("ajouter une reclamation "),
                         QObject::tr("reclamation ajouter\n"
                                     "click cancel to exit "),QMessageBox ::Cancel          );
    }
    else
       {  QMessageBox :: critical(nullptr,QObject::tr("ajouter une reclamation "),
                                     QObject::tr("erreur\n"
                                                 "click cancel to exit "),QMessageBox ::Cancel          );



    }

}




void MainWindow::on_pushButton_modifierhis_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}



void MainWindow::on_pushButton_supphist_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);

}



void MainWindow::on_okh_istorique_clicked()
{

    int  nombre=ui->lineEdit_10->text().toInt();
    bool test =tmphistorique.supprimer(nombre);
    if(test)
    {ui->tabel_historique->setModel(tmphistorique.afficher());
        QMessageBox ::information(nullptr,QObject::tr("suprimer identifiant"),
                                  QObject::tr("identifiant supprmier \n"
                                              "click cancel to exit"),QMessageBox::Cancel);

}
    else {
        QMessageBox ::critical(nullptr,QObject::tr("suprimer identifiant"),
                                  QObject::tr("erreur \n"
                                              "click cancel to exit"),QMessageBox::Cancel);


    }
    ui->tabel_historique->setModel(tmphistorique.afficher());


}



void MainWindow::on_pushButton_suppp_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);

}

void MainWindow::on_pushButton_14_clicked()
{
    QPrinter printer;
            printer.setOutputFormat(QPrinter::PdfFormat);
            printer.setOutputFileName("C:\\Users\\Public\\reclamation.pdf");
            QPainter painter;

            if (! painter.begin(&printer)) { // failed to open file
                qWarning("failed to open file, is it writable?");
            }

            QSqlQuery   query ;
            qDebug() << query.prepare("select sysdate from dual  ");
            if ( query.exec() )
            {

                QString S= QDate::currentDate().toString();
                painter.drawText(850,50,S);
                QPen penred(Qt::black);

                painter.setFont(QFont("Arial", 30));
                penred.setWidth(1);
                painter.setPen(penred);

                painter.drawText(330,100," reclamation ");
                painter.setFont(QFont("Arial",30));
                painter.setPen(Qt::black);

            }

             QString numero_de_livraison, type,description,date_de_reclamation;
            QSqlQuery   qry ;
            int i =50;
            int k=0;
            qDebug() << qry.prepare("select * from enregistrement where numero_de_livraison=(select max(numero_de_livraison) from enregistrement) ");

            if ( qry.exec() )
            {

                while(qry.next())
                {

                    if ( k % 13 ==0)
                    {   i=250;
                        painter.setFont(QFont("Arial",10));
                        QPen penblack(Qt::black);

                        painter.setPen(penblack);
        painter.drawText (0,200,"numero_de_livraison");
        painter.drawText (120,200,"type");
        painter.drawText (300,200,"description");
        painter.drawText (540,200,"date_de_reclamation");

                    }

                    painter.setFont(QFont("Arial",10));
                    QPen penblack(Qt::black);

                    painter.setPen(penblack);
                    int j=0;
                    numero_de_livraison= qry.value(0).toString();
                    painter.drawText(j*20,i, numero_de_livraison);
                    j++;
                    type=qry.value(1).toString();
                    painter.drawText(j*120,i, type);
                    j++;
                    description=qry.value(2).toString();
                    painter.drawText(j*150,i, description);
                    j++;
                    date_de_reclamation=qry.value(3).toString();
                    painter.drawText(j*180,i, date_de_reclamation);
                    j++;

                    i+=80;
                    k++;

                }
            }

            painter.end();


}

void MainWindow::on_pushtrier_clicked()
{
    ui->tabel_historique->setModel(tmphistorique.affichertri());
}

void MainWindow::on_rechercher_clicked()
{


        QString text;

        text=ui->lineEdit_13->text();

        if(text == "")

        {

            ui->tabel_historique->setModel(tmphistorique.afficher());

        }

        else

        {



            ui->tabel_historique->setModel(tmphistorique.recherche(text));

        }

}

void MainWindow::on_pushButton_15_clicked()
{
    QString n;
    n=ui->lineEdit_nbrr->text();
    n+="%";
    ui->lineEdit_pour->setText(n);

}
