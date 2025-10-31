#include "iter.hpp"

// Functions
void printInt(const int& x) { std::cout << x << " "; }

template <typename T>
void printAny(const T& x) { std::cout << x << " "; }

void increment(int& x) { x++; }

// Tests
int main()
{
    {
        std::cout << "===== INT ARRAY =====" << std::endl;
        int arr[] = {1, 2, 3, 4, 5};

        std::cout << "Original: ";
        iter(arr, 5, printInt);
        std::cout << std::endl;

        std::cout << "Incrementing..." << std::endl;
        iter(arr, 5, increment);

        std::cout << "After: ";
        iter(arr, 5, printAny<int>);
        std::cout << std::endl << std::endl;
    }

    {
        std::cout << "===== STRING ARRAY =====" << std::endl;
        std::string words[] = {"Hello", "World", "!"};

        iter(words, 3, printAny<std::string>);
        std::cout << std::endl << std::endl;
    }

    {
        std::cout << "===== CONST ARRAY =====" << std::endl;
        const double values[] = {3.14, 2.71, 1.61};

        iter(values, 3, printAny<double>);
        std::cout << std::endl;
    }

    return 0;
}

