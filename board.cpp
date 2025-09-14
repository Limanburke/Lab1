#include "board.h"

Cell_chose::Cell_chose(int size) :
    gen(std::random_device{}()),   
    dist(0, size * size - 1)         
{}

int Cell_chose:: operator() () {
   return dist(gen); 
}

void Board::generate_random_numbers(int num_experiment)
{
    Cell_chose random(n);
    random_numbers.reserve(num_experiment * m);
    for (int i = 0; i < num_experiment * m; i++)
    {
        random_numbers.push_back(random());
    }
}

int Board::one_experiment(int start_index, int end_index) {
    build();

    for (int i = start_index; i < end_index; i++) {
        mark_cell(random_numbers[i]);
    }
    return free_zone_size();
}

Board::Board(int user_n, int user_m) :
    n(user_n), m(user_m) {};

void Board::build() {
    cells.clear();

    for (int i = 0; i < n * n; i++) {
        Cell c;
        cells.push_back(c);
    }
}

void Board::mark_neighbours(int index)
{
    if (index - n >= 0)     // top
        cells[index - n].isNeighbour = true;

    if (index + n < n * n)  // bottom
        cells[index + n].isNeighbour = true;

    if (index % n != 0)     // left
        cells[index - 1].isNeighbour = true;

    if (index % n != n - 1) // right
        cells[index + 1].isNeighbour = true;
}

void Board::mark_cell(int index)
{
    if (!cells[index].isMarked)
    {
        cells[index].isMarked = true;
        mark_neighbours(index);
    }
}

int Board::free_zone_size() {
    int count = 0;
    for (const auto& cell : cells)
        if (!cell.isMarked && !cell.isNeighbour)
            count++;
    return count;
}

double Board::average_free_zone(int num_experiment) {

    double sum = 0.0;

    for (int i = 0; i < num_experiment; i++)
    {
        int start_index = i * m;
        int end_index = start_index + m;
        sum += one_experiment(start_index, end_index);
    }
    return sum / num_experiment;
}

double Board::median_free_zone(int num_experiment) {
    std::vector<int> results;
    results.reserve(num_experiment);

    for (int i = 0; i < num_experiment; i++) {
        int start_index = i * m;
        int end_index = start_index + m;
        results.push_back(one_experiment(start_index, end_index));
    }

    std::sort(results.begin(), results.end());

    if (num_experiment % 2 == 1) 
        return results[num_experiment / 2];
    else 
    {
        int mid1 = results[num_experiment / 2 - 1];
        int mid2 = results[num_experiment / 2];
        return (mid1 + mid2) / 2.0;
    }
}
