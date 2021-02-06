#include "ajouter.h"
#include "ui_ajouter.h"
#include <QDebug>
#include <QFile>
#include <QXmlStreamWriter>

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

    QString fileXmlName = "C:/Users/Christian GROS/Desktop/xmlClass/test3.xml";
    QFile fileXml(fileXmlName);

    // Ouverture du fichier en écriture et en texte. (sort de la fonction si le fichier ne s'ouvre pas)
    if(!fileXml.open(QFile::WriteOnly | QFile::Text))
        qDebug()<<"erreur";

    QXmlStreamWriter writer(&fileXml);

    // Active l'indentation automatique du fichier XML pour une meilleur visibilité
    writer.setAutoFormatting(true);

    // Insert la norme de codification du fichier XML :
    writer.writeStartDocument();

    // Élément racine du fichier XML
    writer.writeStartElement("seances");

    // Ajoute l'élément "seance" dans le fichier XML
    writer.writeStartElement("seance");

    // Ajoute un élément "dateArrivee", lui applique le texte "bzhenel" et ferme l'élément "nom"
    writer.writeTextElement("dateArrivee", dateArrivee.toString());

    // Ajoute l'élément "heureArrivee", lui applique le texte "www.bzhenel.fr" et ferme l'élément "url"
    writer.writeTextElement("heureArrivee", heureArrivee.toString());

    // Ajoute un élément "dateArrivee", lui applique le texte "bzhenel" et ferme l'élément "nom"
    writer.writeTextElement("dateDepart", dateDepart.toString());

    // Ajoute l'élément "heureArrivee", lui applique le texte "www.bzhenel.fr" et ferme l'élément "url"
    writer.writeTextElement("heureDepart", heureDepart.toString());

    // Ajoute l'élément "heureArrivee", lui applique le texte "www.bzhenel.fr" et ferme l'élément "url"
    writer.writeTextElement("typeClient", type);

    // Ferme l'élément seance
    writer.writeEndElement();

    // Finalise le document XML
    writer.writeEndDocument();

    // Fermer le fichier pour bien enregistrer le document et ferme l'élément root
    fileXml.close();







}
