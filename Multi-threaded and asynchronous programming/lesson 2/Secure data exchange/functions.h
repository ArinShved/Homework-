#pragma once
#include<iostream>
#include "class.h"


void swap(Data& first, Data& second);
void swap_lock(Data& first, Data& second);
void swap_scopedlock(Data& first, Data& second);
void swap_uniquelock(Data& first, Data& second);
void print_func(void(*func_name)(Data&, Data&), Data& first, Data& second);
