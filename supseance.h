#ifndef SUPSEANCE_H
#define SUPSEANCE_H

#include <QDialog>
#include "gestionxml.h"

namespace Ui {
class supSeance;
}

class supSeance : public QDialog
{
    Q_OBJECT

public:
    explicit supSeance(QWidget *parent = nullptr);
    ~supSeance();

private slots:
    void on_pushButton_clicked();

private:
    Ui::supSeance *ui;
    gestionXml xml;
};

#endif // SUPSEANCE_H
