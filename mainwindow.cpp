#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "connection.h"
#include "signup.h"
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Connection t;
    t.createconnect();
    QGuiApplication::setWindowIcon(QIcon("C:/Users/bedou/Downloads/delivery"));
    setMinimumSize(QSize(883,502));

    setMaximumSize(QSize(883,502));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_3_clicked()
{
    QString poste=ui->comboBox->currentText();
    QString name=ui->lineEdit_password->text();
    QString username=ui->lineEdit_name->text();
    QString password=ui->lineEdit_username->text();
    signup A(username,password, name, poste);
    bool test=A.ajouter();
                if(name.isEmpty()){QMessageBox::warning(nullptr, QObject::tr("Nom et prénom"),
                                                                 QObject::tr("Veuillez indiquer votre nom et prénom\n""Click Cancel to exit")
                                                                 ,QMessageBox::Cancel);}
                else if(username.isEmpty()){QMessageBox::warning(nullptr, QObject::tr("Nom d'utilisateur"),
                                                                 QObject::tr("Veuillez indiquer votre nom d'utilisateur\n""Click Cancel to exit")
                                                                 ,QMessageBox::Cancel);}
                else if(password.isEmpty()){QMessageBox::warning(nullptr, QObject::tr("Mot de passe"),
                                                                 QObject::tr("Veuillez indiquer votre mot de passe\n""Click Cancel to exit")
                                                                 ,QMessageBox::Cancel);}
                else if (test){
                                QMessageBox::information(nullptr, QObject::tr("OK"),
                                                         QObject::tr("Compte creer\n""Click Cancel to exit")
                                                         ,QMessageBox::Cancel);}
                else{
                                QMessageBox::warning(nullptr, QObject::tr("OK"),
                                             QObject::tr("Nom d'utilisateur existe déjà\n""Click Cancel to exit")
                                             ,QMessageBox::Cancel);}


}

void MainWindow::on_pushButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

}
void MainWindow::resizeEvent(QResizeEvent *evt)
{
QPixmap bkgnd("C:/Users/bedou/OneDrive/Documents/Login/orgg.png");
bkgnd = bkgnd.scaled(size(), Qt::IgnoreAspectRatio);
QPalette p = palette(); //copy current, not create new
p.setBrush(QPalette::Background, bkgnd);
setPalette(p);

QMainWindow::resizeEvent(evt); //call base implementation
}

void MainWindow::on_pushButton_7_clicked()
{
    QString username,password;
    username=ui->lineEdit_7->text();
    password=ui->lineEdit_9->text();

    QSqlQuery qry;
    if(qry.exec("select * from SIGNUP where USERNAME= '"+username +"' and PASSWORD= '"+password+"'"))
    {
        int count=0;
        while(qry.next())
        {
            count++;
        }
        if (count==1)
        {   QMessageBox::information(nullptr, QObject::tr("Connected"),
                                 QObject::tr("Connexion réussite\n""Click Cancel to exit")
                                 ,QMessageBox::Cancel);
            ui->stackedWidget->setCurrentIndex(1);}
        if (count>1)
            QMessageBox::warning(nullptr, QObject::tr("Duplicated"),
                         QObject::tr("Duplication\n""Click Cancel to exit")
                         ,QMessageBox::Cancel);
        if (count<1)
            QMessageBox::warning(nullptr, QObject::tr("Erreur"),
                         QObject::tr("Nom d'utilisateur ou mot de passe incorrecte\n""Click Cancel to exit")
                         ,QMessageBox::Cancel);
    }
}

void MainWindow::on_pushButton_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}
