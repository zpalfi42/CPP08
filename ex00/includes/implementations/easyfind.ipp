#ifndef	EASYFIND_IPP
# define EASYFIND_IPP

#include <easyfind.tpp>

template <typename T>
int	easyfind(T const container, int n)
{
	if (std::find(container.begin(), container.end(), n) == container.end())
		throw (outOfRange());
	std::cout << "\033[1;32mFound " << n << "\033[0m" << std::endl;
	return (n);
}

#endif