#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"promotion.h"
#include <QMainWindow>
#include "historique_client.h"

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

    void on_pb_tri_nom_historique_clicked();

    void on_pb_tri_prix_promotion_clicked();

private:
    Ui::MainWindow *ui;
    promotion p;
    historique h;
};
#endif // MAINWINDOW_H
