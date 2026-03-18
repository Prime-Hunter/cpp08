#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include "limits.h"

class Span
{
    private:
        unsigned int _max_n;
        unsigned int _pos;
        std::vector<int> _span;

    public:
        Span();
        Span(unsigned int max_n);
        ~Span();
        Span(const Span &copy);
        Span &operator =(const Span &src);
    
        void addNumber(int n);
        void addNumber(std::vector<int>::iterator start, std::vector<int>::iterator end);
        int shortestSpan();
        int longestSpan();

        class SpanFull: public std::exception
        {
            public:
                virtual const char *what() const throw();
        };

        class SpanTooSmall: public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
};
#endif