#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>

template<typename T>
int easyfind(const T &arr, int n)
{
    for (typename T::const_iterator it = arr.begin(); it != arr.end(); ++it)
    {
        if (*it == n)
            return *it;
    }

    throw std::runtime_error("Value not found");
}

#endif

