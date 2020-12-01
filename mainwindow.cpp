#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "connection.h"
#include "colis.h"
#include "livraison.h"
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Connection t;
    t.createconnect();
    show_tables();
    show_tables1();
    QGuiApplication::setWindowIcon(QIcon("C:/Users/bedou/Downloads/delivery"));
}

MainWindow::~MainWindow()
{
    delete ui;
    //show_tables();
}

// colis
void MainWindow::on_pushButton_clicked()
{
        int numcolis=ui->lineEdit->text().toInt();
        QString depart=ui->lineEdit_2->text();
        QString destination=ui->lineEdit_3->text();
        QString date_envoi=ui->dateEdit->date().toString("dd.MM.yyyy");
        QString assurance=ui->comboBox->currentText();
        QString poids=ui->comboBox_2->currentText();


         if(numcolis<1000){
            QMessageBox::critical(nullptr, QObject::tr("OK"),
                                     QObject::tr("numéro du colis invalide\n""Click Cancel to exit")
                                     ,QMessageBox::Cancel);
        }
         else if(depart.isEmpty())
         {
             QMessageBox::critical(nullptr, QObject::tr("OK"),
                                      QObject::tr("Veuillez indiquer le depart\n""Click Cancel to exit")
                                      ,QMessageBox::Cancel);
         }
        else if(destination.isEmpty()){
            QMessageBox::critical(nullptr, QObject::tr("OK"),
                                     QObject::tr("Veuillez indiquer la destination\n""Click Cancel to exit")
                                     ,QMessageBox::Cancel);

        }
        else{
            colis A(numcolis,depart,destination,date_envoi,assurance,poids);
            bool test=A.ajouter();
            if (test){
                QMessageBox::information(nullptr, QObject::tr("OK"),
                                         QObject::tr("Ajout Effectué\n""Click Cancel to exit")
                                         ,QMessageBox::Cancel);
            }
            show_tables();
        }

}
void MainWindow::show_tables(){

    proxy = new QSortFilterProxyModel();

    proxy->setSourceModel(tmp.afficher());

    proxy->setFilterCaseSensitivity(Qt::CaseInsensitive);
    proxy->setFilterKeyColumn(-1);
    ui->tableView->setModel(proxy);

}

void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
    selected=ui->tableView->model()->data(index).toInt();
}



void MainWindow::on_pushButton_2_clicked()
{
    colis mc;
      mc.supprimer(selected);

     //refresh du tableau (affichage)
       show_tables();
}

void MainWindow::on_lineEdit_4_textChanged(const QString &arg1)
{
    proxy->setFilterFixedString(arg1);
}

QString MainWindow::get_date() const { //date
    return ui->dateEdit->date().toString("dd.MM.yyyy");
}
QString MainWindow::get_depart() const { //date
    return ui->lineEdit_2->text();
}
QString MainWindow::get_destination() const { //date
    return ui->lineEdit_3->text();
}
QString MainWindow::get_assurance() const { //combo box

    return ui->comboBox->currentText();
}
QString MainWindow::get_poids() const { //combo box

    return ui->comboBox_2->currentText();
}
int MainWindow::get_numcolis() const{ //integer

    return ui->lineEdit->text().toInt();
}

void MainWindow::fill_form(int selected ) {
QSqlQuery query;
    query.prepare("select * from CRUD where NUM_COLIS= :num_colis");
    query.bindValue(":num_colis", selected);
    query.exec();
    while(query.next()){
        ui->dateEdit->setDate(QDate::fromString(query.value(3).toString(),"dd.MM.yyyy"));//date
 ui->lineEdit->setText(query.value(0).toString());
 ui->lineEdit_3->setText(query.value(2).toString());//text edit
  ui->lineEdit_2->setText(query.value(1).toString()); //line edit
   ui->comboBox->setCurrentText(query.value(4).toString()); //combobox
    ui->comboBox_2->setCurrentText(query.value(5).toString());

    }
}
void MainWindow::on_tableView_doubleClicked(const QModelIndex &index)
{

    fill_form(selected);
}


void MainWindow::on_pushButton_3_clicked()
{
        QString s1=get_depart();
        QString s2=get_destination();
        QString s3=get_date();
        QString s4=get_assurance();
        QString s5=get_poids();
        colis mc(selected,s1,s2,s3,s4,s5);
            mc.modifier(selected);
            show_tables();
}
// home
void MainWindow::on_pushButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_9_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_10_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

// livraison


void MainWindow::on_pushButton_5_clicked()
{
    int codelivraison=ui->lineEdit_5->text().toInt();
    QString livreur=ui->lineEdit_6->text();
    QString duree=ui->comboBox_3->currentText();
    QString distance=ui->comboBox_4->currentText();
    QString etat=ui->comboBox_5->currentText();

     if(codelivraison<1000){
        QMessageBox::critical(nullptr, QObject::tr("OK"),
                                 QObject::tr("Veuillez indiquer un code de livraison valide\n""Click Cancel to exit")
                                 ,QMessageBox::Cancel);
    }
     else if(livreur.isEmpty())
     {
         QMessageBox::critical(nullptr, QObject::tr("OK"),
                                  QObject::tr("Veuillez indiquer le livreur\n""Click Cancel to exit")
                                  ,QMessageBox::Cancel);
     }
    else{
        livraison A(codelivraison,livreur,duree,distance,etat);
        bool test=A.ajouter();
        if (test){
            QMessageBox::information(nullptr, QObject::tr("OK"),
                                     QObject::tr("Ajout Effectué\n""Click Cancel to exit")
                                     ,QMessageBox::Cancel);
        }
    show_tables1();
    }
}

void MainWindow::show_tables1(){

    proxy = new QSortFilterProxyModel();

    proxy->setSourceModel(tmp1.afficher());

    proxy->setFilterCaseSensitivity(Qt::CaseInsensitive);
    proxy->setFilterKeyColumn(-1);
    ui->tableView_2->setModel(proxy);

}

void MainWindow::on_tableView_2_clicked(const QModelIndex &index)
{
    selected1=ui->tableView_2->model()->data(index).toInt();
}

void MainWindow::on_pushButton_7_clicked()
{
    livraison mc;
      mc.supprimerl(selected1);

     //refresh du tableau (affichage)
       show_tables1();
}

void MainWindow::on_lineEdit_7_textChanged(const QString &arg1)
{
    proxy->setFilterFixedString(arg1);
}

QString MainWindow::get_duree() const { //date
     return ui->comboBox_3->currentText();
}
QString MainWindow::get_livreur() const { //date
    return ui->lineEdit_6->text();
}
QString MainWindow::get_distance() const { //combo box

    return ui->comboBox_4->currentText();
}
QString MainWindow::get_etat() const { //combo box

     return ui->comboBox_5->currentText();
}
int MainWindow::get_codelivraison() const{ //integer

    return ui->lineEdit_5->text().toInt();
}
void MainWindow::fill_form1(int selected1 ) {
QSqlQuery query;
    query.prepare("select * from CRUD1 where CODE_LIVRAISON= :code_livraison");
    query.bindValue(":code_livraison", selected1);
    query.exec();
    while(query.next()){
    ui->lineEdit_5->setText(query.value(0).toString());
    ui->lineEdit_6->setText(query.value(1).toString()); //line edit
    ui->comboBox_3->setCurrentText(query.value(2).toString()); //combobox
    ui->comboBox_4->setCurrentText(query.value(3).toString()); //combobox
    ui->comboBox_5->setCurrentText(query.value(4).toString());
    }
}

void MainWindow::on_tableView_2_doubleClicked(const QModelIndex &index)
{
    fill_form1(selected1);
}

void MainWindow::on_pushButton_8_clicked()
{
    QString s1=get_livreur();
    QString s2=get_duree();
    QString s3=get_distance();
    QString s4=get_etat();
    livraison mc(selected1,s1,s2,s3,s4);
        mc.modifier(selected1);
        show_tables1();
}

void MainWindow::on_pushButton_12_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_11_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}
