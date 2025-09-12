#pragma once
#include <vector>
#include <random>

class Board
{
    int n = 0;                      // one side of board (n*n)
    int m = 0;                      // number of cells to be marked randomly
    struct Cell
    {
        bool isMarked = false;
        bool isNeighbour = false;   // cell is a neighbour to marked one
    };
    std::vector<Cell> cells;                                      

public:
    Board(int user_n, int user_m) : n(user_n), m(user_m) {}

    void build();                                                 
    void mark_cell(int index);
    int free_zone_size();                                         //calculate cells that aren't marked and neighbours
    double average_free_zone(int amount_of_lauches = 100);        
    double median_free_zone(int amount_of_lauches = 100);        
    void generate_random_cell();
};

class RandomCellPicker
{
    std::mt19937 gen;
public:
    RandomCellPicker() : gen(std::random_device()()) {}
    int operator()(int number) {
        std::uniform_int_distribution<int> dist(0, number - 1);
        return dist(gen);
    }
};