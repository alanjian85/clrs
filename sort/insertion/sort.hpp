#ifndef INSERTION_HPP
#define INSERTION_HPP

// insertion sort
template <typename T>
void sort(T& a) {
    // Get the array's signed size before starting the sorting process. Because
    // the variable j derived from it on line 12 may become less than zero, n
    // must be signed in order to avoid arithmetic underflow.
    auto n = std::ssize(a);
    for (decltype(n) i = 1; i < n; ++i) {
        auto key = a[i];
        // Check if there is any element in the sorted sub-array is greater
        // than the current key. And insert the key to an appropriate position. 
        auto j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            --j;
        }
        a[j + 1] = key;
    }
    // After the termination, the loop invariant is still true
}

#endif // INSERTION_HPP
