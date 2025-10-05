#pragma once
#include <vector>
struct Experiment {
    static double average_free_zone(const std::vector<double>& result);
    static double median_free_zone(std::vector<double> result);
};