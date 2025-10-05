#pragma once
#include <vector>

class Cell_chose;

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

    void build();
    void mark_cell(int index);
    void mark_neighbours(int index);
    int free_zone_size();
public:
    Board(int user_n, int user_m);
    int size() const;
    int marks() const;
    std::vector<double> run_experiments(int num_experiment, Cell_chose& chooser);
};