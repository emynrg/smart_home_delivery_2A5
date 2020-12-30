#include "devis.h"
#include<QSqlQuery>
#include<QSqlQueryModel>
#include"QDebug"
devis::devis()
{

}


bool devis:: ajouterDevis()
{
    QSqlQuery query;
    query.prepare("insert into DEVIS (CODE,DESTINATION,TYPE_DE_LIVRAISON,QUANTITE,PRIX,ID_FOURNISSEUR) "
                  "values(:code,:destination,:type_de_livraison,:quantite,:prix,:id_fournisseur)");
   query.bindValue(":code",code);
   query.bindValue(":destination",destination);
   query.bindValue(":type_de_livraison",type_de_livraison);
   query.bindValue(":quantite",quantite);
   query.bindValue(":prix",prix);
   qDebug()<<prix;
   query.bindValue(":id_fournisseur",id_fournisseur);
   return query.exec();
}

QSqlQueryModel * devis:: afficherDevis()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM DEVIS");
    return model ;
}


bool devis:: update_D(QString code ,QString destination,QString type, QString quantite , QString prix ,QString fourni ,int column )
{
    QSqlQuery query;
        if (column==1)
                  {

          query.prepare( "update DEVIS set  DESTINATION = : destination where code=:code " );

                  }
        else if (column==2)
        {
            query.prepare( "update DEVIS set  TYPE_DE_LIVRAISON= :type_de_livraison where code=:code " );

        }
        else if (column==3)
        {
            query.prepare( "update DEVIS set  QUANTITE= :quantite where code=:code " );

        }
        else if (column==4)
        {
            query.prepare( "update DEVIS set  PRIX= :prix where code=:code " );

        }
        else if(column==5)
        {
            query.prepare("update DEVIS set ID_FOURNISSEUR= :id_fournisseur where code=:code");
        }

        query.bindValue(":code",code);
        query.bindValue(":destination",destination);
        query.bindValue(":type_de_livraison",type);
        query.bindValue(":quantite",quantite);
        query.bindValue(":prix",prix);
        query.bindValue(":id_fournisseur",fourni);
        query.exec();


        return query.exec();
}
bool devis::supprimer(QString code)
{
    QSqlQuery query;

     query.prepare("DELETE  FROM DEVIS WHERE code=:code");
     query.bindValue(":code",code);
     return query.exec();
}
void devis::exporter(QTableView *table)
{
    QString filters("CSV files (.csv);;All files (.*)");
        QString defaultFilter("csv files (*.csv)");
        QString fileName = QFileDialog::getSaveFileName(0, "Save file", QCoreApplication::applicationDirPath(),
                                                        filters, &defaultFilter);
        QFile file(fileName);
        QAbstractItemModel *model =  table->model();
        if (file.open(QFile::WriteOnly | QFile::Truncate)) {
            QTextStream data(&file);
            QStringList strList;
            for (int i = 0; i < model->columnCount(); i++) {
                if (model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString().length() > 0)
                    strList.append("\"" + model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString() + "\"");
                else
                    strList.append("");
            }
            data << strList.join(";") << "\n";
            for (int i = 0; i < model->rowCount(); i++) {
                strList.clear();
                for (int j = 0; j < model->columnCount(); j++) {

                    if (model->data(model->index(i, j)).toString().length() > 0)
                        strList.append("\"" + model->data(model->index(i, j)).toString() + "\"");
                    else
                        strList.append("");
                }
                data << strList.join(";") + "\n";
            }
            file.close();
        }
}
