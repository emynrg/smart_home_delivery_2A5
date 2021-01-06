#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"enregistrement.h"
#include"historique.h"
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

    void on_pushButton_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_13_clicked();

    void on_label_14_linkActivated(const QString &link);

    void on_pushButton_14_clicked();

    void on_pushButton_78_clicked();

    void on_pushButton_61_clicked();

    void on_pushButton_77_clicked();

    void on_pushButton_79_clicked();

    void on_pushButton_modifierhis_clicked();

    void on_pushButton_supphist_clicked();

    void on_okh_istorique_clicked();

    void on_pushButton_suppp_clicked();

    void on_pushtrier_clicked();

    void on_rechercher_clicked();

    void on_pushButton_15_clicked();

    void on_pdf_clicked();

    void on_ajouter_reclamation_clicked();

    void on_modifie_reclamation_clicked();

    void on_supprimer_reclamation_clicked();

    void on_retour_enregistrement_reclamation_clicked();

    void on_line_customContextMenuRequested(const QPoint &pos);

    void on_lineEdit_cursorPositionChanged(int arg1, int arg2);

    void on_lineEdit_2_cursorPositionChanged(int arg1, int arg2);

    void on_ok_modifier_reclamation_clicked();

    void on_retour_modifier_reclamation_clicked();

    void on_enregistrer_modifier_reclamation_clicked();

    void on_lineEdit_5_cursorPositionChanged(int arg1, int arg2);

    void on_ok_supprimer_reclamation_clicked();

    void on_enregsiter_reclamation_page_acceuil_clicked();

    void on_historique_page_acceuil_clicked();

    void on_pushButton_3_clicked();

    void on_pourcentage_clicked();

    void on_ajouter_historique_clicked();

    void on_retour_modd_historique_clicked();

    void on_enregistrer_modd_historique_clicked();

private:
    Ui::MainWindow *ui;
    enregistrement tmpreclamation;
    historique tmphistorique;

};
#endif // MAINWINDOW_H
