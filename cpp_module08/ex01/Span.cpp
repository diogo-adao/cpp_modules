#include "Span.hpp"

Span::Span() : N(0) {}

Span::Span(unsigned int size) : N(size) { numbers.reserve(N); }
       
Span::Span(const Span& src) : numbers(src.numbers), N(src.N) {}

Span& Span::operator=(const Span& src)
{
    if (this != &src)
    {
        numbers = src.numbers;
        N = src.N;
    }

    return *this;
}

Span::~Span() {}

void Span::addNumber(int number)
{
    if (numbers.size() >= N)
        throw std::runtime_error("Too many numbers");
    
    numbers.push_back(number);
}

int Span::shortestSpan() const
{
    if (numbers.size() < 2)
        throw std::runtime_error("Not enough numbers");

    std::vector<int> sorted = numbers;
    sort(sorted.begin(), sorted.end());

    int shortest = std::numeric_limits<int>::max();

    for (std::vector<int>::const_iterator it = sorted.begin(); it + 1 != sorted.end(); ++it)
    {
        int diff = *(it + 1) - *it;
        if (diff < shortest)
            shortest = diff;
    }

    return shortest;
}

int Span::longestSpan() const
{
    if (numbers.size() < 2)
        throw std::runtime_error("Not enough numbers");

    std::vector<int>::const_iterator minIt = min_element(numbers.begin(), numbers.end());
    std::vector<int>::const_iterator maxIt = max_element(numbers.begin(), numbers.end());

    return *maxIt - *minIt;
}
