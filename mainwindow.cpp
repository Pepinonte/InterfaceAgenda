#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "ajouter.h"
#include "editseance.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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
