#include <iostream>
#include <random>
#include <algorithm>
#include <string>
#include "Utility.h"
#include "Car.h"

int main() {
    auto cars = randomCars();
    std::cout << "Cars: " << cars << "\n";

    // TODO: print the average price and price range
    double price_average = 0, price_range = 0, max_price = -1, min_price = -1;
    int size = cars.size();
    for (const auto& elem : cars) {
        price_average = price_average + (elem.price() / size);
        if (max_price == -1) {
            max_price = elem.price();
            min_price = elem.price();
        }
        else if (elem.price() > max_price)
            max_price = elem.price();
        else if (elem.price() < min_price)
            min_price = elem.price();
    }
    
    std::cout << "The average price is: $" << price_average << "\n";

    std::cout << "The range is: $" << max_price - min_price << "\n";
}