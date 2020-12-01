#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "colis.h"
#include "livraison.h"
#include <QSortFilterProxyModel>
#include <QTextTableFormat>
#include <QStandardItemModel>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    livraison tmp1;
    colis tmp;

    QSortFilterProxyModel *proxy;

    QString get_date() const ;
    QString get_depart() const ;
    QString get_assurance() const;
    QString get_poids() const ;
    int get_numcolis() const;
    QString get_destination() const ;
    void fill_form(int);
    void show_tables();

    QString get_duree() const ;
    QString get_distance() const ;
    QString get_livreur() const;
    QString get_etat() const ;
    int get_codelivraison() const;
    void fill_form1(int);
    void show_tables1();

private slots:
    void on_pushButton_clicked();

    void on_tableView_clicked(const QModelIndex &index);

    void on_pushButton_2_clicked();

    void on_lineEdit_4_textChanged(const QString &arg1);

    void on_tableView_doubleClicked(const QModelIndex &index);

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_5_clicked();

    void on_tableView_2_clicked(const QModelIndex &index);

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_lineEdit_7_textChanged(const QString &arg1);

    void on_tableView_2_doubleClicked(const QModelIndex &index);

    void on_pushButton_8_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_11_clicked();

private:
    Ui::MainWindow *ui;
    int selected = 0;
    int selected1=0;
};
#endif // MAINWINDOW_H
