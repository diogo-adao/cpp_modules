#include "easyfind.hpp"
#include <vector>
#include <list>

int main()
{
    // Vector
    try {
        std::vector<int> numbers;
        numbers.push_back(1);
        numbers.push_back(2);
        numbers.push_back(3);
        numbers.push_back(4);
        numbers.push_back(5);

        int n = easyfind(numbers, 5);

        std::cout << "Value found: " << n << std::endl;
    }
    catch (std::exception& e) { std::cout << e.what() << std::endl; }

    // List
    try {
        std::list<int> numbers;
        numbers.push_back(1);
        numbers.push_back(2);
        numbers.push_back(3);
        numbers.push_back(4);
        numbers.push_back(5);

        int n = easyfind(numbers, 6);

        std::cout << "Value found: " << n << std::endl;
    }
    catch (std::exception& e) { std::cout << e.what() << std::endl; }

    return (0);
}
