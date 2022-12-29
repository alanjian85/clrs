/*
 * Copyright (c) 2022 Alan Jian
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

// This sort.hpp will be directed to different header files when building
// different CMake projects. This design provides some flexibility for adding
// new algorithm and reusing the interface code.
#include "sort.hpp"

int main()
{
    using element_t = int;

    // Fetch a line from stdin
    std::cout << "Enter the array to be sorted: ";
    std::string line;
    std::getline(std::cin, line);

    // Convert the retrieved line to an array of integers
    std::istringstream stream(line);
    std::vector<element_t> vector;
    for (element_t i; stream >> i;)
    {
        vector.push_back(i);
    }

    // Sort the stored integers
    sort(vector);

    // Output the sorted values
    std::cout << "The array is sorted: ";
    for (auto i : vector)
    {
        std::cout << i << ' ';
    }
    std::cout << '\n';

    return 0;
}
