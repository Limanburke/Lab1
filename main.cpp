#include <iostream>
#include "board.h"

// Compiler: MSVC 19.34 (Visual Studio 2022 v17.4)
// Standard : C++20

int user_input()
{
    int number = 0;
    std::cin >> number;

    if (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        throw std::invalid_argument("\nInvalid input: please enter an integer.\n");
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

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
            if (n < 1)
                throw std::out_of_range("\nSize of board can't be less then one!\n");

            std::cout << "Enter the amount of random cells: ";
            m = user_input();
            if (m < 0 || m > n * n)
                throw std::out_of_range("\nAmount of random cell can't be less then zero or be greater then size of the board!\n");
            std::cout << "Enter number of experiments to run: ";
            num_experiment = user_input();
            if (num_experiment <= 0)
                throw std::out_of_range("\nNumber of experiments to run must be positive!\n");
        }

        catch (std::out_of_range& e)
        {
            std::cout << e.what() << '\n';
            n = 0;
            m = 0;
        }

        catch (std::invalid_argument& i)

        {
            std::cout << i.what() << '\n';
            n = 0;
            m = 0;
        }
    } while (n < 1 || m < 0 || m > n * n || num_experiment <= 0);

    Board board(n, m);

    Experiment::generate_random_numbers(board, num_experiment);

    std::cout << "\nResult:\n";

    auto result = board.run_experiments(num_experiment);

    double average = Experiment::average_free_zone(board, result);
    std::cout << "Average amount of free cells: " << average << std::endl;

    double median = Experiment::median_free_zone(board, result);

    std::cout << "Median number of free cells: " << median << std::endl;

    return 0;
}