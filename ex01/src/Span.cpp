#include <Span.hpp>

Span::Span( void ): _size(0)
{
}

Span::Span( const Span &s ): _numbers(s._numbers), _size(s._size)
{

}

Span::Span( unsigned int n ): _size(n)
{
}

Span::~Span( void )
{

}

Span	&Span::operator=( const Span &s )
{
	if (this != &s)
	{
		this->_numbers = s._numbers;
		this->_size = s._size;
	}
	return (*this);
}

void	Span::addNumber( int n )
{
	if (this->_numbers.size() == this->_size)
		throw (Span::noSpaceLeft());
	this->_numbers.push_back(n);
}

int		Span::shortestSpan( void )
{
	if (this->_numbers.size() < 2)
		throw (Span::noNumbers());
	std::vector<int>	diff(this->_numbers.size());

	std::adjacent_difference(this->_numbers.begin(), this->_numbers.end(), diff.begin());
	for (size_t i = 0; i < diff.size(); i++)
		if (diff[i] < 0)
			diff[i] = -diff[i];
	return(*(std::min_element(diff.begin() + 1, diff.end())));
}

int		Span::longestSpan( void )
{
	if (this->_numbers.size() < 2)
		throw (Span::noNumbers());
	this->_numbers.begin();
	return(*(std::max_element(this->_numbers.begin(), this->_numbers.end())) - *(std::min_element(this->_numbers.begin(), this->_numbers.end())));
}
