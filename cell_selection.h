#pragma once
#include <random>
#include <vector>

class Cell_chose {
private:
    std::mt19937 gen;
    std::uniform_int_distribution<> dist;
    std::vector<int> random_numbers;
public:
    Cell_chose(int size);
    int operator() ();
    void generate_random_numbers(int marks, int num_experiment);
    std::vector<int>& get_random_numbers();
};
