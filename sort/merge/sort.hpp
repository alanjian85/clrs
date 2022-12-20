#ifndef SORT_HPP
#define SORT_HPP

template <typename T>
void sort(T& a, typename T::size_type p = 0, decltype(std::ssize(a)) r = -1)
{
    if (r == -1)
        r = a.ssize();
}

#endif // SORT_HPP
