#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    newWindow = new Dialog(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pB_ok_clicked()
{
   QString hostname = ui->lE_hostname->text();
   QString bdname = ui->lE_bdname->text();
   QString login = ui->lE_login->text();
   QString password = ui->lE_password->text();
   uint prot = ui->sB_prot->value();
   ui->statusbar->showMessage("Host: "+hostname+" BD: "+bdname+" Login: "+login+" Password: "+password+" prot: "+QString::number(prot), 1000);
}


void MainWindow::on_pB_open_clicked()
{
    newWindow->show( );
}

