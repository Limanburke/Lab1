// Компилятор: MSVC 19.34 (Visual Studio 2022 v17.4)
// Стандарт: C++20

#include <iostream>
#include "Board.h"

using namespace std;

int main() {
    int n;
    int m;

    cout << "Enter the size of the board: ";
    cin >> n;

    cout << "Enter the amount of random cells: ";
    cin >> m;

    Board board(n, m);

    double average = board.average_free_zone();
    cout << "Average amount of free cells: " << average << endl;

    double median = board.median_free_zone();
    cout << "Median number of free cells: " << median << endl;

    return 0;
}
