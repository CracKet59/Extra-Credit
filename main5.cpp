#include <iostream>
#include <random>
#include <algorithm>
#include <string>
#include "Utility.h"
#include "Car.h"

template <typename T>
class Tag {
public:
    Tag(bool isTagged, T value) : _tagged{ isTagged }, _value{ value } {}

    bool isTagged() const { return _tagged; }
    T item() const { return _value; }

private:
    bool _tagged;
    T _value;
};

template <typename T>
std::ostream& operator<<(std::ostream& out, const Tag<T>& tag) {
    out << "TAG: tagged(" << (tag.isTagged() ? "true" : "false") << "), item(" << tag.item() << ")";
    return out;
}

bool IsTrue (Tag<Car> elem) {
    return elem.isTagged();
}

int main() {
    auto cars = randomCars();
    std::cout << "Cars: " << cars << "\n";

    std::vector<Tag<Car>> taggedCars;
    // TODO: populate 'taggedCars' with elements of type Tag<Car> where the tag is set to true
    //  only if the price < 10,000 or if the vin starts with a letter in A...F
    for (auto& elem : cars) {
        bool is_tagged = 0;
        if (elem.price() < 10000)
        is_tagged = 1;
        else
            for(char c = 'A'; c <= 'F'; c++)
                if(elem.vin()[0] == c)
                    is_tagged = 1;
        Tag<Car> new_element(is_tagged, elem);
        taggedCars.push_back(new_element);
    }
    
    // TODO: arrange `taggedCars` so that the elements tagged `true` are at the beginning
    //  and `false` elements are at the ened
    partition(taggedCars.begin(), taggedCars.end(), IsTrue);
    std::cout << "Tagged Cars: " << taggedCars << "\n";
}