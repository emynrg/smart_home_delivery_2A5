#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"promotion.h"
#include <QMainWindow>
#include "historique_client.h"
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintDialog>
#include <QSound>
#include <QSequentialAnimationGroup>
#include <QTableWidgetItem>
#include <QMediaPlayer>
#include "employe.h"
#include "conge.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void musicClick();


private slots:

    void on_pb_valider_clicked();
    void on_pb_affprom_clicked();


    void on_pb_supprimer_clicked();

    void on_pb_ajouter_clicked();

    void on_pb_annuler_2_clicked();

    void on_pb_afficher_historique_clicked();

    void on_pb_ajouter_historique_clicked();

    void on_pb_promotion_historique_clicked();

    void on_pb_historique_promotion_clicked();

    void on_pb_valider_historique_clicked();

    void on_pb_annule_historique_clicked();

    void on_pb_supprimer_historique_clicked();

    void on_pb_modifier_promotion_clicked();

    void on_pb_modifier_historique_clicked();

    void on_le_recherche_promotion_textChanged(const QString &arg1);

    void on_le_recherche_historique_textChanged(const QString &arg1);

    void on_pb_selection_historique_clicked();

    void on_pb_select_promotion_clicked();

    void on_pb_trier_historique_clicked();

    void on_pb_imprimer_historique_clicked();

    void on_pb_imprimer_promotion_clicked();


    void on_pb_trier_promotion_clicked();

    void on_cb_choix_historique_activated(const QString &arg1);



    //**********jamoussi******************
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
    void on_pb_login_promotion_clicked();

    void on_pb_login_rh_clicked();

    void on_pb_rh_login_clicked();

    void on_pb_promotion_login_clicked();
    //*********************************************************rgaaaaayaaa*******************************************************************
    //*********************************************************rgaaaaayaaa*******************************************************************


    void on_pushButton_ajouterfourni_clicked();



    void on_Button_affichefourni_clicked();

    void on_button_updatfourni_clicked();

    void update_fournisseur();

    void on_backamine_2_clicked();

   void on_backamine_3_clicked();

   void on_backamine_4_clicked();

   void on_tableauModification_cellChanged(int row, int column);






   void on_ajouterfournibouton_clicked();



   void on_supprimerfourni_bouton_clicked();



   void on_boutonGestionFournisseur_clicked();

   void on_backamine_5_clicked();

   void on_BoutonGestionDevis_clicked();

   void on_ajouterbouton_devis_clicked();

   void on_afficherbouton_devis_clicked();

   void on_modifierbouton_devis_clicked();

   void on_backamine_6_clicked();

   void on_backamine_7_clicked();

   void on_backamine_8_clicked();

   void on_ajouterdevis_clicked();

   void update_DEVIS();



   void on_tableWidgetdevis_cellChanged(int row, int column);

   void on_pushButton_supprimerDevis_clicked();

   void on_pushButton_CHERCHERfourni_clicked();



   void on_pushButton_IMPRIMERdevis_clicked();

   void on_pushButton_exporterdevis_clicked();

   void on_backamine_clicked();


   void on_pb_login_rgaya_clicked();

   void on_pb_rgaya_login_clicked();


private:
    Ui::MainWindow *ui;
    promotion p;
    historique h;
    QSequentialAnimationGroup* animationGroup;
    //***********jamoussi
    Employe tmpemploye;
    conge tmpconge;
    QMediaPlayer *musicC= new QMediaPlayer();
};


#endif // MAINWINDOW_H
