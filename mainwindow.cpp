#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "ajouter.h"
#include "editseance.h"
#include "supseance.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    ui->pushButton_2->hide();
}
MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    ajouter win2;
    win2.setModal(true);
    win2.exec();
}

void MainWindow::on_pushButton_2_clicked()
{
    editSeance win3;
    win3.setModal(true);
    win3.exec();
}

void MainWindow::on_pushButton_4_clicked()
{
    supSeance win4;
    win4.setModal(true);
    win4.exec();
}
