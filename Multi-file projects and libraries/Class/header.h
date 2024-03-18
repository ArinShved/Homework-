#pragma once

class Counter{
private:
    int num;
public:
    int increaseCounter();
    int reduceCounter();
    void showCounter();
    Counter();
    Counter(int num);
};

void choosingCommand(Counter& counter, char users_response);