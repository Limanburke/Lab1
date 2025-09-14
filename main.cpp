// Compiler: MSVC 19.34 (Visual Studio 2022 v17.4)
// Standard : C++20

#include <iostream>
#include "board.h"

int user_input()
{
    int number = 0;
    std::cin >> number;
    if (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        throw std::invalid_argument("Input error");
    }
    return number;
}

    int main() 
    {
        int n = 0;
        int m = 0;
        int num_experiment = 0;
        do
        {
            try
            {
                std::cout << "Enter the size of the board: ";
                n = user_input();
                if (n <= 0)
                    throw std::out_of_range("size of board can't be less or equal zero!");

                std::cout << "Enter the amount of random cells: ";
                m = user_input();
                if (m < 0 || m > n * n)
                    throw std::out_of_range("Amount of random cell can't be less then zero or be greater/equal size");

                std::cout << "Enter number of experiments to run: ";
                num_experiment = user_input();
                if (num_experiment <= 0)
                    throw std::out_of_range("number of experiments to run must be positive!");

            }
            catch (std::out_of_range e)
            {
                std::cout << e.what() << '\n';
                n = 0;
                m = 0;
            }
            catch (std::invalid_argument i)
            {
                std::cout << i.what() << '\n';
                n = 0;
                m = 0;
            }
        } while (n <= 0 || m < 0 || m > n * n || num_experiment <= 0);

    Board board(n, m);
    board.generate_random_numbers(num_experiment);
    double average = board.average_free_zone(num_experiment);
    std::cout << "Average amount of free cells: " << average << std::endl;
    double median = board.median_free_zone(num_experiment);
    std::cout << "Median number of free cells: " << median << std::endl;

    return 0;
}