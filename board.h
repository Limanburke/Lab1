#pragma once
#include <vector>

class Board
{
    int n = 0;                      // one side of board (n*n)
    int m = 0;                      // number of cells to be marked randomly
    struct Cell
    {
        bool isMarked = false;
        bool isNeighbour = false;   // cell is a neighbour to marked one
    };
    std::vector<Cell> cells;        // contains all cells from board

public:
    Board(int user_n, int user_m) : n(user_n), m(user_m) {};

    void build();                   // builds Board n*n
    void mark_cell(int index);
    int free_zone_size();           //calculate cells that aren't marked and neighbours
    double average_free_zone();     //calculate average from multiple launches
    double median_free_zone();      // calculate median from multiple launches

};