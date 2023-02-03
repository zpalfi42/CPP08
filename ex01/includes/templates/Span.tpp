#ifndef	SPAN_TPP
# define SPAN_TPP

# include <Span.hpp>

template < typename Container >
void	Span::fillNumbers(const typename Container::iterator &begin, const typename Container::iterator &end )
{
	for (typename Container::iterator i = begin; i != end; i++)
	{
		this->addNumber(*i);
	}
}

#endif