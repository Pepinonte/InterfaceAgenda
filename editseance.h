#ifndef EDITSEANCE_H
#define EDITSEANCE_H

#include <QDialog>

namespace Ui {
class editSeance;
}

class editSeance : public QDialog
{
    Q_OBJECT

public:
    explicit editSeance(QWidget *parent = nullptr);
    ~editSeance();

private slots:
    void on_pushButton_clicked();
    void on_calendarWidget_clicked(const QDate &date);

private:
    Ui::editSeance *ui;
};

#endif // EDITSEANCE_H
