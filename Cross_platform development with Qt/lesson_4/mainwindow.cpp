#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    ui->BarProgress->setTitle("Загрузка");
    ui->RadioButtons->setTitle("Состояние кнопки");

//progress bar
    ui->prBar_bar->setMinimum(0);
    ui->prBar_bar->setMaximum(10);
    ui->prBar_bar->setValue(0);
//radio buttons
    ui->rB_working->setChecked(true);
    ui->rB_stop->setText("Кнопка неактивна");
    ui->rB_working->setText("Кнопка активна");

// list
    for(int i = 0; i < 5; i++){
    ui->cB_list->addItem(QString("Состояние: " + QString::number(i)));
    }

//button
    ui->pB_prog->setText("Увеличить прогресс");
    ui->pB_prog->setCheckable(1);


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pB_prog_clicked()
{
    if(ui->rB_working->isChecked() == true){
        if(ui->prBar_bar->value() == 10){
            ui->prBar_bar->setValue(0);
            return;
        }
        int cur_value = ui->prBar_bar->value();
        ui->prBar_bar->setValue(cur_value+1);
    }

}

