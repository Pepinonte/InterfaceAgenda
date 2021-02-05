#include "ajouter.h"
#include "ui_ajouter.h"
#include <QDebug>
#include <QFile>

ajouter::ajouter(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ajouter)
{
    ui->setupUi(this);
    ui->dateDepart->setDate(QDate::currentDate());
    ui->dateArrivee->setDate(QDate::currentDate());
    ui->heureArrivee->setTime(QTime::currentTime());
    ui->heureDepart->setTime(QTime::currentTime());
    ui->type->addItem("debutant");
    ui->type->addItem("confirme");
}

ajouter::~ajouter()
{
    delete ui;
}

void ajouter::on_pushButton_clicked()
{
    QDate dateArrivee = ui->dateArrivee->date();
    QDate dateDepart = ui->dateDepart->date();
    QTime heureDepart = ui->heureDepart->time();
    QTime heureArrivee = ui->heureArrivee->time();
    QString type = ui->type->currentText();

    qDebug()<<"dateArrivee:"<<dateArrivee.toString();
    qDebug()<<"dateDepart:"<<dateDepart.toString();
    qDebug()<<"heureArrivee:"<<heureArrivee.toString();
    qDebug()<<"heureDepart:"<<heureDepart.toString();


    QString fichier = "C:/Users/Christian GROS/Desktop/agendaInterface-20210129T071652Z-001/agendaInterface/xml/test3.xml";

    QFile file(fichier); // Appel du constructeur de la classe QFile

    if (file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
    // Si l'ouverture du fichier en écriture à réussie

    // écrire dans le fichier

    QTextStream out(&file);
    out<<("<!-- structure des séances -->\n");
    out<<("<seances>\n");
    out<<("    <seance id=\"1\">\n");
    out<<("        <dateArrivee>" + dateArrivee.toString() + "</dateArrivee>\n");
    out<<("        <heureArrivee>" + heureArrivee.toString() + "</heureArrivee>\n");
    out<<("        <dateDepart>" + dateDepart.toString() + "</dateDepart>\n");
    out<<("        <heureDepart>" + heureDepart.toString() + "</heureDepart>\n");
    out<<("        <typeClient>" + type + "</typeClient>\n");
    out<<("    </seance>\n");
    out<<("</seances>\n");

    // Fermer le fichier
    file.close();


    }

}
