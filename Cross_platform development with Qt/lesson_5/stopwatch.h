#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <QTimer>
#include <QTime>
#include <QObject>


class StopWatch : public QObject
{
    Q_OBJECT;
public:
    StopWatch(QObject *parent = nullptr);
    void start_timer();
    void stop_timer();
    void clear_timer();
    int get_time();

signals:
    void sig_update_time(int time);

private slots:
    void update_time();

private:
    QTimer *timer;
    int cur_time;
    int last_time;
    bool running = false;
};

#endif // STOPWATCH_H
