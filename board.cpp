#include "board.h"
#include <iostream>

void Board::build()
{
    for (size_t i = 0; i < n * n; i++)
    {
        cells.push_back(Cell{ false, false });
    }
}

void Board::generate_random_cell()
{
    RandomCellPicker rand;
    for (int i = 0; i < m; i++)
    {
        mark_cell(rand(n * n));
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

int Board::free_zone_size()
{
    int count = 0;
    for (int i = 0; i < n * n; i++)
    {
        if (!cells[i].isMarked && !cells[i].isNeighbour)
            ++count;
    }
    return count;
}

void Board::clear()
{
    for (Cell& c : cells)
    {
        c.isMarked = false;
        c.isNeighbour = false;
    }
}

double Board::average_free_zone(int amount_of_lauches)
{
    long long sum = 0;
    for (long long i = 0; i < amount_of_lauches; i++)
    {
        clear();
        generate_random_cell();
        sum += free_zone_size();
    }

    return static_cast<long long>(sum / amount_of_lauches);
}

double Board::median_free_zone(int amount_of_launches)
{
    std::vector<int> container;
    container.reserve(amount_of_launches);

    for (int i = 0; i < amount_of_launches; i++)
    {
        clear();
        generate_random_cell();
        container.push_back(free_zone_size());
    }

    std::sort(container.begin(), container.end());

    size_t size = container.size();
    if (size % 2 != 0)
    {
        return container[size / 2];
    }
    else
    {
        return (container[size / 2 - 1] + container[size / 2]) / 2.0;
    }
}