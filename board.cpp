#include "board.h"
#include <iostream>

void Board::build() 
{
    for (size_t i = 0; i < n*n; i++)
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

void Board::mark_cell(int index)
{
    for (int i = 0; i < n * n; i++)
    {
        if (index == i && cells[i].isMarked == false)
        {
            cells[i].isMarked = true;

            if (i - n >= 0) // top
            {
                cells[i - n].isNeighbour = true;
            }
            if (i + n < n * n) // bottom
            {
                cells[i + n].isNeighbour = true;
            }
            if (i % n != 0) // left
            {
                cells[i - 1].isNeighbour = true;
            }
            if (i % n != n - 1) // right
            {
                cells[i + 1].isNeighbour = true;
            }
        }
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


double Board::average_free_zone(int amount_of_lauches)
{

    return 0;
}

double Board::median_free_zone(int amount_of_launches)
{

    return 0;
}