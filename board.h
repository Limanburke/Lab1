#pragma once
#include <vector>
#include <random>

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
    int one_experiment(int start_index, int end_index);
public:
    Board(int user_n, int user_m);

    void build(); 
    void mark_cell(int index);
    void mark_neighbours(int index);
    int free_zone_size(); 
    void generate_random_numbers(int num_experiment);
    double average_free_zone(int num_experiment = 1000);
    double median_free_zone(int num_experiment = 1000);
};
