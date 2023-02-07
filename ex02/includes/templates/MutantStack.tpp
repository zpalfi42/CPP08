#ifndef	MUTANTSTACK_TPP
# define MUTANTSTACK_TPP

# include <MutantStack.hpp>

template<typename T>
class MutantStack: public std::stack<T>
{
private:
	/* data */
public:
	MutantStack( void );
	MutantStack( const MutantStack &m );

	~MutantStack( void );

	MutantStack &operator=( const MutantStack &m );

	typedef	typename	std::stack<T>::container_type Container; //Container is the type of container used by std::stack.
	
	typedef	typename	Container::iterator	iterator; // This line create a alias 'iterator' that is stored in the container def before.
	iterator		begin( void );
	iterator		end( void );

	typedef	typename	Container::const_iterator	const_iterator;
	const_iterator	cbegin( void );
	const_iterator	cend( void );

	typedef	typename	Container::reverse_iterator	reverse_iterator;
	reverse_iterator		rbegin( void );
	reverse_iterator		rend( void );

	typedef	typename	Container::const_reverse_iterator	const_reverse_iterator;
	const_reverse_iterator	crbegin( void );
	const_reverse_iterator	crend( void );
};

# include <MutantStack.ipp>

#endif