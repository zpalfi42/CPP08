#ifndef	SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <exception>
# include <vector>
# include <algorithm>
# include <numeric>

class Span
{
private:
	std::vector<int>	_numbers;
	unsigned int		_size;
public:
	Span( void );
	Span( const Span &s );
	Span( unsigned int n );

	~Span();

	Span	&operator=( const Span &s );

	template < typename Container >
	void	fillNumbers(const typename Container::iterator &begin, const typename Container::iterator &end);

	void	addNumber(int n);
	int		shortestSpan();
	int		longestSpan();

	class noSpaceLeft: public std::exception
	{
		public:
			virtual const char	*what() const throw()
			{
				return("Error: Array already full");
			}
	};

	class noNumbers: public std::exception
	{
		public:
			virtual const char	*what() const throw()
			{
				return ("Error: Array has no sufficient numbers");
			}
	};
};

#include <Span.tpp>

#endif