#pragma once

#include <iostream>
#include <vector>

void print_pyramid(std::vector<int> arr);
int parent_index(int a);
void print_index(std::vector<int> arr, int a);
int child_left(std::vector<int> arr, int a);
int child_right(std::vector<int> arr, int a);