#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <iostream>
#include <algorithm>

class NotFoundException: public std::exception
{
	public:
			virtual const char *what() const throw()
			{
				return ("Value not found");
			}
};

template <typename T>
typename T::iterator easyfind(T data, int n)
{
    typename T::iterator i;
    i = find(data.begin(), data.end(), n);
    if (i == data.end())
        throw (NotFoundException());
    return (i);
}

#endif