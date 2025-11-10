#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>

class Span {
    private:
        std::vector<int> numbers;
        unsigned int N;
    public:
        Span();
        Span(unsigned int N);
        Span(const Span& src);
        Span& operator=(const Span& src);
        ~Span();

        void addNumber(int number);
        int shortestSpan();
        int longestSpan();
};

#endif
