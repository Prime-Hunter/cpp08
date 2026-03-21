#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template <class T>

class MutantStack: public std::stack<T>
{
    public:
        typedef std::stack<T> _stack;
        typedef typename _stack::container_type _container;
        typedef typename _container::iterator _iterator;

        MutantStack() {}

        ~MutantStack() {}

        MutantStack(const MutantStack &copy) {(void) copy;}

        MutantStack &operator =(const MutantStack &src)
        {
            if (*this != src)
                *this = src;
            return (*this);
        }

        _iterator begin()
        {
            return (_stack::c.begin());
        }

        _iterator end()
        {
            return (_stack::c.begin());
        }
};

#endif