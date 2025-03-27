
#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include "stopwatch.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->pB_round->setEnabled(false);

    timer = new StopWatch(this);


    connect(timer, &StopWatch::sig_update_time, this, &MainWindow::show_time);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pB_start_clicked()
{

    if(ui->pB_start->text() == "Старт"){
        ui->pB_start->setText("Стоп");
        ui->pB_round->setEnabled(true);

        timer->start_timer();

    }
    else{
        ui->pB_start->setText("Старт");
        ui->pB_round->setEnabled(false);
        timer->stop_timer();
    }
}


void MainWindow::on_pB_round_clicked()
{
    double cur_time = timer->get_time();


    if(lap != 1){
      cur_time -= last_round;
    }

    int ms = static_cast<int>(cur_time * 10) % 10;
    int s = static_cast<int>(cur_time) % 60;
    int m = static_cast<int>(cur_time / 60) % 60;
    int h = cur_time / 3600;

    QString time = QString("%1:%2:%3:%4").arg(h).arg(m).arg(s).arg(ms);
    ui->tB_text->append(QString("Круг %1, время: %2").arg(lap).arg(time));
    last_round = timer->get_time();
    lap++;
}


void MainWindow::show_time(double cur_time){
    int ms = static_cast<int>(cur_time * 10) % 10;
    int s = static_cast<int>(cur_time) % 60;
    int m = static_cast<int>(cur_time / 60) % 60;
    int h = cur_time / 3600;

    QString time = QString("%1:%2:%3:%4").arg(h).arg(m).arg(s).arg(ms);


    ui->l_time->setText(time);

}




void MainWindow::on_pB_clear_clicked()
{
    timer->clear_timer();

    ui->l_time->setText("00:00:00");
    ui->tB_text->clear();
    lap = 1;
    if(ui->pB_start->text() == "Стоп"){
      timer->start_timer();
    }
}

