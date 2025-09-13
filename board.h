#pragma once

using namespace std;

#include <vector>
#include <random>
#include <algorithm>

class Cell_chose {
private:
    int n;
    mt19937 gen;
    uniform_int_distribution<> dist;
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
    vector<Cell> cells; 

    int one_experiment(Cell_chose& random);
public:
    Board(int user_n, int user_m);

    void build(); 
    void mark_cell(int index);
    int free_zone_size(); 
    double average_free_zone(); 
    double median_free_zone(); 

};
