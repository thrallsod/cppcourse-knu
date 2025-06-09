#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <random>
#include "Complex.hpp"

template<typename T>
void compute(int len, T initial, T step) {
    // allocate vectors
    std::vector<T> v(len + 1), diffs(len);

    // fill and randomize v
    std::generate(v.begin(), v.end(), [n = 0, initial, step]() mutable {
        return initial + step * n++;
    });

    std::shuffle(v.begin(), v.end(), std::default_random_engine{});

    // compute differences
    std::adjacent_difference(v.begin(), v.end(), diffs.begin());
    diffs.erase(diffs.begin()); // remove the first element (initial copy)

    // compute standard deviation of all differences
    const T sum = std::accumulate(diffs.begin(), diffs.end(), T{});
    const T sumsq = std::accumulate(diffs.begin(), diffs.end(), T{}, [](T acc, T x) {
        return acc + x * x;
    });

    const T mean = sum / static_cast<double>(len);
    const T variance = sumsq / static_cast<double>(len) - mean * mean;

    std::cout << "Range = [" << initial << ", " << initial + step * len << "]\n"
              << "Mean = " << mean << '\n'
              << "Variance = " << variance << '\n';
}

int main() {
    compute(1000, 0.0, 7.0);
    compute(1000, Complex{0, 0}, Complex{7, 0});
}
