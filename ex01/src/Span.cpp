#include "../includes/Span.hpp"

Span::Span() 
{
    this->_pos = 0;
}

Span::Span(unsigned int max_n): _max_n(max_n) 
{
    this->_pos = 0;
}

Span::~Span() {}

Span::Span(const Span &copy)
{
    this->_max_n = copy._max_n;
    this->_pos = copy._pos;
}

void Span::addNumber(int n)
{
    if (this->_span.size() >= this->_max_n)
    {
        throw(Span::SpanFull());
    }
    this->_span.push_back(n);
    this->_pos++;
}

void Span::addNumber(std::vector<int>::iterator start, std::vector<int>::iterator end)
{
    if (this->_span.size() >= this->_max_n)
    {
        throw(Span::SpanFull());
    }
    this->_span.insert(this->_span.end(), start, end);
}

int Span::shortestSpan(void)
{
    if (this->_span.size() <= 1)
    {
        throw(Span::SpanTooSmall());
    }
    std::vector<int> spanCopy(this->_span);
    std::sort(spanCopy.begin(), spanCopy.end());

    int res = INT_MAX;
	std::vector<int>::iterator i = spanCopy.begin();
	std::vector<int>::iterator i_next = spanCopy.begin() + 1;
	while (i_next != spanCopy.end())
	{
		if ((*i_next - *i) < res)
			res = *i_next - *i;
		++i;
		++i_next;
	}
    return (res);
}

int Span::longestSpan(void)
{
    if (this->_span.size() <= 1)
    {
        throw(Span::SpanTooSmall());
    }
    std::vector<int> spanCopy(this->_span);
    std::sort(spanCopy.rbegin(), spanCopy.rend());
    int start = *spanCopy.begin();
    std::sort(spanCopy.begin(), spanCopy.end());
	int end = *spanCopy.begin();
    return ((start - end));
}

const char *Span::SpanFull::what(void) const throw()
{
    return ("The span is full");
};

const char *Span::SpanTooSmall::what(void) const throw()
{
    return ("Not enough element in the span");
};