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

    int one_experiment(Cell_chose& random);
public:
    Board(int user_n, int user_m);

    void build(); 
    void mark_cell(int index);
    void mark_neighbours(int index);
    int free_zone_size(); 
    double average_free_zone(int num_experiment = 1000);
    double median_free_zone(int num_experiment = 1000);
};
