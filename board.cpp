#include "board.h"

Cell_chose::Cell_chose(int size) :
    gen(std::random_device{}()),
    dist(0, size* size - 1)
{
}

int Cell_chose:: operator() ()
{
    return dist(gen);
}

void Cell_chose::generate_random_numbers(int marks, int num_experiment)
{
    random_numbers.reserve(num_experiment * marks);

    for (int i = 0; i < num_experiment * marks; i++)
        random_numbers.push_back((*this)());
}

std::vector<double> Board::run_experiments(int num_experiment, Cell_chose& chooser)
{
    std::vector<double> results;
    results.reserve(num_experiment);

    if (cells.empty())
        build();

    auto& random_numbers = chooser.get_random_numbers();

    for (int i = 0; i < num_experiment; i++)
    {
        for (auto& cell : cells)
        {
            cell.isMarked = false;
            cell.isNeighbour = false;
        }

        int start_index = i * m;
        int end_index = start_index + m;

        for (int j = start_index; j < end_index; j++)
            mark_cell(random_numbers[j]);

        results.push_back(free_zone_size());
    }

    return results;
}

Board::Board(int user_n, int user_m) :
    n(user_n), m(user_m) {
};

int Board::size() const {
    return n;
}

int Board::marks() const {
    return m;
}

std::vector<int>& Cell_chose::get_random_numbers()
{
    return random_numbers;
}

void Board::build()
{
    cells.clear();

    for (int i = 0; i < n * n; i++)
    {
        Cell c;
        cells.push_back(c);
    }
}

void Board::mark_neighbours(int index)
{
    if (index - n >= 0)
        cells[index - n].isNeighbour = true;

    if (index + n < n * n)
        cells[index + n].isNeighbour = true;

    if (index % n != 0)
        cells[index - 1].isNeighbour = true;

    if (index % n != n - 1)
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

int Board::free_zone_size()
{
    int count = 0;

    for (const auto& cell : cells)
        if (!cell.isMarked && !cell.isNeighbour)
            count++;

    return count;
}

double Experiment::average_free_zone(const std::vector<double>& result)
{
    double sum = 0.0;
    for (double el : result)
        sum += el;

    return sum / result.size();
}

double Experiment::median_free_zone(std::vector<double> result)
{

    std::sort(result.begin(), result.end());

    if (result.size() % 2 == 1)
        return result[result.size() / 2];
    else
    {
        double mid1 = result[result.size() / 2 - 1];
        double mid2 = result[result.size() / 2];
        return (mid1 + mid2) / 2.0;
    }
}