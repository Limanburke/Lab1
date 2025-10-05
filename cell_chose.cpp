#include "cell_chose.h"

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

std::vector<int>& Cell_chose::get_random_numbers()
{
    return random_numbers;
}