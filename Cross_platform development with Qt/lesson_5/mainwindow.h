#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "stopwatch.h"
#include <QMainWindow>
//

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void show_time(double cur_time);


private slots:
    void on_pB_start_clicked();

    void on_pB_round_clicked();

    void on_pB_clear_clicked();

private:
    Ui::MainWindow *ui;
    StopWatch* timer;
    int lap = 1;
    double last_round;

};
#endif // MAINWINDOW_H
