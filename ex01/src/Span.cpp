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
    if (copy == *this)
        return *this;
    this->_max_n = src._max_n;
    this->_pos = src._pos;
    return (*this);
}

void Span::addNumber(int n)
{
    if (this->_pos >= this->_max_n)
    {
        throw(Span::SpanFull());
    }
    this->_span.push_back(n);
    this->_pos++;
}

int Span::shortestSpan(void)
{
    std::vector<int> spanCopy(this->_span);
    std::sort(spanCopy.begin(), spanCopy.end());

    int res = INT_MAX;
	std::vector<int>::iterator i = spanCopy.begin();
	std::vector<int>::iterator i_next = spanCopy.begin() + 1;
	while (i_next != spanCopy.end())
	{
		if ((unsigned int)(*i_next - *i) < res)
			res = *i_next - *i;
		++i;
		++i_next;
	}
    return (res);
}
