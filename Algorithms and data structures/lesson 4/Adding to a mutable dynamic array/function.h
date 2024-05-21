#pragma once
#include<iostream>

void print_dynamic_array(int* arr, int logical_size, int actual_size);

int* append_to_dynamic_array(int* arr, int& logical_size, int& actual_size, int new_i);