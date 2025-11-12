#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

class Span {
    private:
        std::vector<int> numbers;
        unsigned int N;
    public:
        Span();
        Span(unsigned int size);
        Span(const Span& src);
        Span& operator=(const Span& src);
        ~Span();

        void addNumber(int number);
        int shortestSpan() const;
        int longestSpan() const;

        template <typename Iterator>
        void addNumbers(Iterator begin, Iterator end)
        {
            for (Iterator it = begin; it != end; ++it)
                addNumber(*it);
        }
};

#endif
