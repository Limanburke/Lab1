#include <iostream>
#include "board.h"

int main() 
{
    int size = 0;
    int number_of_cells = 0;
    do
    {
    std::cout << "Enter size of board: ";
    std::cin >> size;
    if (size <= 0)
    {
        std::cerr << "Size can't be negative or zero!\n";
        continue;
    }
    std::cout << "Enter number of cells to mark: ";
    std::cin >> number_of_cells;
    if (number_of_cells < 0 || number_of_cells > size)
    {
        std::cerr << "Number of cells can't be less then 0, or be greater then size!\n";
        std::cout << "Try again\n";
    }
    } while (size <= 0 || number_of_cells < 0 || number_of_cells > size);

    std::cout << std::endl;

    Board b(size, number_of_cells);
    b.build();
    b.generate_random_cell();
    std::cout << "Free zone of first launch:\t" << b.free_zone_size() << "\n";
  
    return 0;
}