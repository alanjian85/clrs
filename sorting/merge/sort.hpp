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

#ifndef SORT_HPP
#define SORT_HPP

#include <vector>

template <typename T>
void merge(T& a, decltype(std::size(a)) p, decltype(std::size(a)) q,
           decltype(std::size(a)) r)
{
    // Compute the length of the interval [p, q] and [q + 1, r], and copy them
    // into a local dynamically-allocated array
    auto nl = q - p + 1;
    auto nr = r - q;
    std::vector al(a.begin() + p, a.begin() + p + nl);
    std::vector ar(a.begin() + q + 1, a.begin() + q + 1 + nr);
    // Pick the smaller value on the top of the two arrays and use queue
    // head pointers i and j
    decltype(al.size()) i = 0, j = 0;
    while (i < nl && j < nr)
    {
        if (al[i] <= ar[j])
        {
            a[p] = al[i];
            ++i;
        }
        else
        {
            a[p] = ar[j];
            ++j;
        }
        ++p;
    }
    // Move the remaining elements in two arrays into the original array, if
    // any
    for (; i < nl; ++i, ++p)
        a[p] = al[i];
    for (; j < nr; ++j, ++p)
        a[p] = ar[j];
}

// The argument r's default value is set to 1. When the sandbox calls it with a
// single argument A, p and r are filled in as 0 and -1, respectively. And once
// the first two line of the procedure have been executed, r will be replaced
// by the index of the last element in the array, indicating the range of the
// entire array [0, N].
template <typename T>
void sort(T& a, decltype(std::size(a)) p = 0, decltype(std::ssize(a)) r = -1)
{
    if (r == -1)
        r = std::ssize(a) - 1;
    // If p = r, there is no need to sort, because an array with only one
    // element is always sorted
    // If p > r, it means the arguments don't form a valid range, so the
    // procedure should return immediately
    if (p >= r)
        return;
    // q is the sum of p and r shifted one bit to the right(divided by two),
    // indicating that it is an average or a median of p and r. This is the
    // "divide" stage of merge sort.
    auto q = (p + r) >> 1;
    // Conquer the left portion and the right portion of the interval,
    // separately
    sort(a, p, q);
    sort(a, q + 1, r);
    // Combine the results
    merge(a, p, q, r);
}

#endif // SORT_HPP
