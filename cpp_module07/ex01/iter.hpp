#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template<typename T, typename F>
void iter(T* arr, const size_t len, F func)
{
    for (size_t i = 0; i < len; ++i)
        func(arr[i]);
}

template<typename T, typename F>
void iter (const T* arr, const size_t len, F func)
{
    for (size_t i = 0; i < len; ++i)
        func(arr[i]);
}

#endif