#include <iostream>

#include "class.h"


    int Counter::increaseCounter(){
        return num++;
    };
    int Counter::reduceCounter(){
        return num--;
    };
    void Counter::showCounter(){
        std::cout << num << "\n";
    };
    Counter::Counter(){
        num = 1;
    };
    Counter::Counter(int num){
        this->num = num;
    }



