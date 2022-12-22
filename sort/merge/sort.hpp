#ifndef SORT_HPP
#define SORT_HPP

#include <vector>

template <typename T>
void merge(T& a, decltype(std::size(a)) p, decltype(std::size(a)) q,
           decltype(std::size(a)) r)
{
    auto nl = q - p + 1;
    auto nr = r - q;
    std::vector al(a.begin() + p, a.begin() + p + nl);
    std::vector ar(a.begin() + q + 1, a.begin() + q + 1 + nr);
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
    for (; i < nl; ++i, ++p)
        a[p] = al[i];
    for (; j < nr; ++j, ++p)
        a[p] = ar[j];
}

template <typename T>
void sort(T& a, decltype(std::size(a)) p = 0, decltype(std::ssize(a)) r = -1)
{
    if (r == -1)
        r = std::ssize(a);
}

#endif // SORT_HPP
