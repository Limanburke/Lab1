#pragma once
#include <vector>
#include <random>
#include <algorithm>

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

public:
    Board(int user_n, int user_m);
    int size() const;
    int marks() const;
    int free_zone_size();
    std::vector<double> run_experiments(int num_experiment, Cell_chose& chooser);
};

struct Experiment {
    static double average_free_zone(const std::vector<double>& result);
    static double median_free_zone(std::vector<double> result);
};