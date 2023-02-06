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

long int		Span::shortestSpan( void )
{
	if (this->_numbers.size() < 2)
		throw (Span::noNumbers());
	std::vector<long int>	lv(this->_numbers.size());
	for (size_t i = 0; i < this->_numbers.size(); i++)
		lv[i] = this->_numbers[i];
	std::vector<long int>	diff(lv.size());
	std::adjacent_difference(lv.begin(), lv.end(), diff.begin());
	for (size_t i = 0; i < diff.size(); i++)
		if (diff[i] < 0)
			diff[i] = -diff[i];
	return(*(std::min_element(diff.begin() + 1, diff.end() - 1)));
}

long int		Span::longestSpan( void )
{
	if (this->_numbers.size() < 2)
		throw (Span::noNumbers());
	this->_numbers.begin();
	return((long int)*(std::max_element(this->_numbers.begin(), this->_numbers.end())) - (long int)*(std::min_element(this->_numbers.begin(), this->_numbers.end())));
}

unsigned int	Span::size( void )
{
	return (this->_size);
}

int				Span::getNum( int i )
{
	if (i < (int)this->_size)
		return (this->_numbers[i]);
	else
		return ( 0 );
}