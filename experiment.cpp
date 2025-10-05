#include "experiment.h"
#include <algorithm>

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