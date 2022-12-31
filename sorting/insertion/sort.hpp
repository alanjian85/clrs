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

#ifndef INSERTION_HPP
#define INSERTION_HPP

// Insertion sort
template <typename T>
void sort(T& a)
{
    // Get the array's signed size before starting the sorting process. Because
    // the variable j derived from it on line 12 may become less than zero, n
    // must be signed in order to avoid arithmetic underflow.
    auto n = std::ssize(a);
    for (decltype(n) i = 1; i < n; ++i)
    {
        auto key = a[i];
        // Check if there is any element in the sorted sub-array is greater
        // than the current key. And insert the key to an appropriate position.
        auto j = i - 1;
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            --j;
        }
        a[j + 1] = key;
    }
    // After the termination, the loop invariant is still true
}

#endif // INSERTION_HPP
