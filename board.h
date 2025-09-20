#pragma once
#include <vector>
#include <random>
#include <algorithm>

class Cell_chose {
private:
    std::mt19937 gen;
    std::uniform_int_distribution<> dist;
public:
    Cell_chose(int size);
    int operator() ();
};

class Board
{
    int n = 0;
    int m = 0;

    struct Cell
    {
        bool isMarked = false;
        bool isNeighbour = false;
    };

    std::vector<Cell> cells;
    std::vector<int> random_numbers;
    std::vector<double> run_experiments(int num_experiment);

    void build();
    void mark_cell(int index);
    void mark_neighbours(int index);
    int free_zone_size();

public:
    Board(int user_n, int user_m);
    void generate_random_numbers(int num_experiment);
    double average_free_zone(int num_experiment);
    double median_free_zone(int num_experiment);
};