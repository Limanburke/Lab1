#include "board.h"
#include "cell_selection.h"

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
