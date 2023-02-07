#ifndef	MUTANTSTACK_IPP
# define MUTANTSTACK_IPP

# include <MutantStack.tpp>

template<typename T>
MutantStack<T>::MutantStack( void ): std::stack<T>()
{
}

template<typename T>
MutantStack<T>::~MutantStack( void )
{
}

template<typename T>
MutantStack<T>::MutantStack( const MutantStack &m ): std::stack<T> (m)
{
}

template<typename T>
MutantStack<T>	&MutantStack<T>::operator=( const MutantStack &m )
{
	if (this != &m)
	{
		this->c = m.c;
	}
	return (*this);
}

// typename is specified for letting the compiler know that 'MutantStack<T>::iterator' is a type and not a static member or a function.
template<typename T>
typename MutantStack<T>::iterator	MutantStack<T>::begin( void )
{
	return (this->c.begin());
}

template<typename T>
typename MutantStack<T>::iterator	MutantStack<T>::end( void )
{
	return (this->c.end());
}

template<typename T>
typename MutantStack<T>::const_iterator	MutantStack<T>::cbegin( void )
{
	return (this->c.cbegin());
}

template<typename T>
typename MutantStack<T>::const_iterator	MutantStack<T>::cend( void )
{
	return (this->c.cend());
}

template<typename T>
typename MutantStack<T>::reverse_iterator	MutantStack<T>::rbegin( void )
{
	return (this->c.rbegin());
}

template<typename T>
typename MutantStack<T>::reverse_iterator	MutantStack<T>::rend( void )
{
	return (this->c.rend());
}

template<typename T>
typename MutantStack<T>::const_reverse_iterator	MutantStack<T>::crbegin( void )
{
	return (this->c.crbegin());
}

template<typename T>
typename MutantStack<T>::const_reverse_iterator	MutantStack<T>::crend( void )
{
	return (this->c.crend());
}



#endif