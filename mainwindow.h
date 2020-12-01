#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_2_clicked();


    void on_Button_affiche_clicked();

    void on_button_updat_clicked();

    void update_fournisseur();

    void on_back_3_clicked();

   void on_back_2_clicked();

   void on_back_clicked();

   void on_tableauModification_cellChanged(int row, int column);






   void on_ajouterbouton_clicked();



   void on_supprimer_bouton_clicked();

   void on_pushButton_clicked();

   void on_boutonGestionFournisseur_clicked();

   void on_pushButton_3_clicked();

   void on_BoutonGestionDevis_clicked();

   void on_ajouterbouton_devis_clicked();

   void on_afficherbouton_devis_clicked();

   void on_modifierbouton_devis_clicked();

   void on_pushButton_4_clicked();

   void on_pushButton_6_clicked();

   void on_pushButton_7_clicked();

   void on_ajouterdevis_clicked();

   void update_DEVIS();



   void on_tableWidgetdevis_cellChanged(int row, int column);

   void on_pushButton_supprimerDevis_clicked();

   void on_pushButton_CHERCHER_clicked();



   void on_pushButton_IMPRIMER_clicked();

private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
