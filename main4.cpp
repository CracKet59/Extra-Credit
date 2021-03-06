#include <iostream>
#include <random>
#include <algorithm>
#include <string>
#include "Utility.h"
#include "Car.h"

bool anyPrime(const std::vector<int>& values);

int main() {
    auto integers = randomIntegers();
    std::cout << "Integers: " << integers << "\n";
    
    std::cout << "Are there any primes? " << (anyPrime(integers) ? "yes" : "no") << "\n";
}

bool anyPrime(const std::vector<int>& values) {
    // TODO: return true if any of the values are prime numbers
    auto result = false;
    for (const auto& elem : values) {
        result = true;
        
        if (elem < 2 || (elem != 2 && elem % 2 == 0))
            result = false;
        for (int div = 3; div * div <= elem && result == true; div += 2)
            if (elem % div == 0)
                result = false;

        if(result == true)
            return result;
    }
    return result;
}