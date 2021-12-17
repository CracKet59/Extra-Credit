#include <iostream>
#include <random>
#include <algorithm>
#include <string>
#include "Utility.h"
#include "Car.h"

int main() {
    auto integers = randomIntegers();
    std::cout << "Initial: " << integers << "\n";

    // TODO: make the sequence a bitonic sequence
    int middle = integers.size() / 2;
    std::sort(integers.begin(), integers.begin() + middle);
    std::sort(integers.begin() + middle, integers.end());
    reverse(integers.begin() + middle, integers.end());
    std::cout << "Bitonic: " << integers << "\n";
}