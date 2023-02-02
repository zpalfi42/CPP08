#ifndef	EASYFIND_HPP
#define EASYFIND_HPP

# include <iostream>
# include <exception>
# include <algorithm>

class outOfRange: public std::exception
{
	public:
		virtual const char	*what() const throw()
		{
			return ("Error: Not found");
		}
};

#include <easyfind.tpp>

#endif