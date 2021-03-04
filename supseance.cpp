#include "supseance.h"
#include "ui_supseance.h"

supSeance::supSeance(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::supSeance)
{
    ui->setupUi(this);
}

supSeance::~supSeance()
{
    delete ui;
}

void supSeance::on_pushButton_clicked()
{
    xml.supElement("seance", "2");
}
