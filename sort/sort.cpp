#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "sort.hpp"

int main() {
    using element_t = int;

    std::cout << "Enter the array to be sorted: ";
    std::string line;
    std::getline(std::cin, line);

    std::istringstream stream(line);
    std::vector<element_t> vector;
    for (element_t i; stream >> i;) {
        vector.push_back(i);
    }

    sort(vector);

    std::cout << "The array is sorted: ";
    for (auto i : vector) {
        std::cout << i << ' ';
    }
    std::cout << '\n';

    return 0;
}
