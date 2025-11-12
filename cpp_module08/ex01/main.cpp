#include "Span.hpp"

int main()
{
    // Original test with addNumber
    try {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "=== Single addNumber test ===" << std::endl;
        std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest : " << sp.longestSpan() << std::endl;
    }
    catch (std::exception& e) { std::cout << "Error: " << e.what() << std::endl; }

    // Test addNumbers
    try {
        std::vector<int> vec;
        vec.push_back(10);
        vec.push_back(1);
        vec.push_back(20);
        vec.push_back(15);
        vec.push_back(3);

        Span spRange(5);
        spRange.addNumbers(vec.begin(), vec.end());

        std::cout << "\n=== Range of iterators test ===" << std::endl;
        std::cout << "Shortest: " << spRange.shortestSpan() << std::endl;
        std::cout << "Longest : " << spRange.longestSpan() << std::endl;
    }
    catch (std::exception& e) { std::cout << "Error: " << e.what() << std::endl; }

    // 10,000 numbers
    try {
        const int size = 10000;

        std::vector<int> bigVec;
        bigVec.reserve(size);
        for (int i = 0; i < size; ++i)
            bigVec.push_back(i);

        Span bigSpan(size);
        bigSpan.addNumbers(bigVec.begin(), bigVec.end());

        std::cout << "\n=== 10,000 numbers test ===" << std::endl;
        std::cout << "Shortest: " << bigSpan.shortestSpan() << std::endl;
        std::cout << "Longest : " << bigSpan.longestSpan() << std::endl;
    }
    catch (std::exception& e) { std::cout << "Error: " << e.what() << std::endl; }

    return 0;
}
