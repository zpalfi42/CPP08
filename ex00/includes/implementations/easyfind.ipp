#ifndef	EASYFIND_IPP
# define EASYFIND_IPP

#include <easyfind.tpp>

template <typename T>
int	easyfind(T const container, int n)
{
	if (std::find(container.begin(), container.end(), n) == container.end())
		throw (outOfRange());
	std::cout << "Found " << n << std::endl;
	return (n);
}

#endif