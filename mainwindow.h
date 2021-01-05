#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"employe.h"
#include"conge.h"
#include <QMainWindow>
#include<QString>
#include<QMessageBox>
#include <QObject>
#include <QMediaPlayer>
#include <QWidget>
#include "employe.h"


namespace Ui {
class MainWindow;

}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
void musicClick();
private slots:





    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();
    void on_ajouteremp_clicked();

    void on_pushButton_afficheremp_clicked();

    void on_pushButton_ajouteremploye_clicked();

    void on_pushButton_modifieremploye_clicked();

    void on_pushButton_ajouterconge_clicked();

    void on_pushButton_modifierconge_clicked();

    void on_pushButton_afficherconge_clicked();

    void on_pushButton_supprimeremp_clicked();

    void on_pushButton_modifierparid_clicked();

    void on_pushButton_ajouterunconge_clicked();

    void on_pushButton_211_clicked();

    void on_pushButton_203_clicked();

    void on_pushButton_204_clicked();

    void on_pushButton_212_clicked();

    void on_pushButton_210_clicked();

    void on_chercherbut_clicked();

    void on_pushButton_pdf_clicked();

    void on_pushButton_pdf_2_clicked();

    void on_pushButton_205_clicked();

    void on_MODIFF_itemClicked(QTableWidgetItem *item);

    void on_pushButton_213_clicked();

private:
    Ui::MainWindow *ui;
    Employe tmpemploye;
    conge tmpconge;
    QMediaPlayer *musicC= new QMediaPlayer();
};

#endif // MAINWINDOW_H
