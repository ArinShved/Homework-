#pragma once

#include <vector>
#include <thread>

int one_vec_sum(std::vector<int> arr_1);
std::vector<int> thread_sum_of_vec(std::vector<int> arr_1, std::vector<int> arr_2, int num_of_threads);