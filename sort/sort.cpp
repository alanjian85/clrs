#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "sort.hpp"

int main() {
    using element_t = int;

    // Fetch a line from stdin
    std::cout << "Enter the array to be sorted: ";
    std::string line;
    std::getline(std::cin, line);

    // Convert the retrieved line to an array of integers
    std::istringstream stream(line);
    std::vector<element_t> vector;
    for (element_t i; stream >> i;) {
        vector.push_back(i);
    }

    // Sort the stored integers
    sort(vector);

    // Output the sorted values
    std::cout << "The array is sorted: ";
    for (auto i : vector) {
        std::cout << i << ' ';
    }
    std::cout << '\n';

    return 0;
}
