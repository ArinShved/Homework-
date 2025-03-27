
#include "stopwatch.h"


StopWatch::StopWatch(QObject *parent): QObject(parent), timer(new QTimer(this)), running(false), cur_time(0), last_time(0)
{


}

void StopWatch::start_timer(){
    running = true;
    cur_time = last_time;


    connect(timer, &QTimer::timeout, this, &StopWatch::update_time);
    timer->start(100);

}

void StopWatch::update_time(){
    if(running){
      cur_time += 0.1;
      emit sig_update_time(cur_time);
    }
}

void StopWatch::stop_timer(){

      running = false;
      timer->stop();
      disconnect(timer, &QTimer::timeout, this, &StopWatch::update_time);
      last_time = cur_time;

}

void StopWatch::clear_timer(){
      timer->stop();
      running = false;
      disconnect(timer, &QTimer::timeout, this, &StopWatch::update_time);
      cur_time = 0;
      last_time = 0;

}

double StopWatch::get_time(){
    return cur_time;
}


