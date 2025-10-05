#include "cell_selection.h"

Cell_selection::Cell_selection(int size) :
    gen(std::random_device{}()),
    dist(0, size* size - 1)
{
}

int Cell_selection:: operator() ()
{
    return dist(gen);
}

void Cell_selection::generate_random_numbers(int marks, int num_experiment)
{
    random_numbers.reserve(num_experiment * marks);

    for (int i = 0; i < num_experiment * marks; i++)
        random_numbers.push_back((*this)());
}

std::vector<int>& Cell_selection::get_random_numbers()
{
    return random_numbers;
}
