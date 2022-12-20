#ifndef INSERTION_HPP
#define INSERTION_HPP

template <typename T>
void sort(T& a) {
    auto n = std::ssize(a);
    for (decltype(n) i = 1; i < n; ++i) {
        auto key = a[i];
        auto j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            --j;
        }
        a[j + 1] = key;
    }
}

#endif // INSERTION_HPP
