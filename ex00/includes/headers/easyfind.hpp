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
			return ("\033[1;31mError: Not found\033[0m");
		}
};

#include <easyfind.tpp>

#endif