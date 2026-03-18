#ifndef SPAN_HPP
#define SPAN_HPP

class Span
{
    private:
        unsigned int _max_n;
        unsigned int _pos;
        std::vector<int> _span;

    public:
        Span();
        Span(unisgned int max_n);
        ~Span();
        Span(const Span &copy);
        Span &operator =(const Span &src);
    
        void addNumber(int n);
        int shortestSpan();
        int longestSpan();
};

class SpanFull: public std::exception
{
	public:
		virtual const char *what() const throw();
};

#endif