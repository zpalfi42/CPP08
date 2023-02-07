#include <MutantStack.hpp>

void	compareStacks( void )
{
	MutantStack<int>	myStack;
	std::stack<int>		stdStack;

	std::cout << "\033[1;35m---------- COMPARING STD::STACK TO MUTANTSTACK ----------\033[0m" << std::endl << std::endl;

	std::cout << "\033[1;34m-> Checking empty() function...:";
	if (stdStack.empty() == myStack.empty())
		std::cout << "\033[1;32m SUCCESS \033[0m ";
	else
		std::cout << "\033[1;31m FAIL \033[0m ";
	std::cout << "( " << stdStack.empty() << " = " << myStack.empty() << " )" << std::endl << std::endl;

	std::cout << "\033[1;34m-> Checking size() function...:";
	if (stdStack.size() == myStack.size())
		std::cout << "\033[1;32m SUCCESS \033[0m ";
	else
		std::cout << "\033[1;31m FAIL \033[0m ";
	std::cout << "( " << stdStack.size() << " = " << myStack.size() << " )" << std::endl << std::endl;

	stdStack.push(42);
	myStack.push(42);

	std::cout << "\033[1;34m-> Checking top() && push() functions...:";
	if (stdStack.top() == myStack.top())
		std::cout << "\033[1;32m SUCCESS \033[0m ";
	else
		std::cout << "\033[1;31m FAIL \033[0m ";
	std::cout << "( " << stdStack.top() << " = " << myStack.top() << " )" << std::endl << std::endl;

	MutantStack<int>	myStackSwap;
	std::stack<int>		stdStackSwap;

	myStackSwap.push(1);
	stdStackSwap.push(1);

	myStack.swap(myStackSwap);
	stdStack.swap(stdStackSwap);

	std::cout << "\033[1;34m-> Checking swap() function...:";
	if (stdStack.top() == myStack.top())
		std::cout << "\033[1;32m SUCCESS \033[0m ";
	else
		std::cout << "\033[1;31m FAIL \033[0m ";
	std::cout << "( " << stdStack.top() << " = " << myStack.top() << " )" << std::endl << std::endl;

	stdStack.pop();
	myStack.pop();

	std::cout << "\033[1;34m-> Checking pop() function...:";
	if (stdStack.empty() == myStack.empty())
		std::cout << "\033[1;32m SUCCESS \033[0m ";
	else
		std::cout << "\033[1;31m FAIL \033[0m ";
	std::cout << "( " << stdStack.empty() << " = " << myStack.empty() << " )" << std::endl << std::endl;

	std::cout << std::endl;
}

void	compareContainers( void )
{
	std::cout << "\033[1;35m---------- COMPARING MUTANTSTACK ITERATORS TO OTHER CONTAINER ITERATORS ----------\033[0m" << std::endl << std::endl;

	{
		std::cout << "\033[1;34mMUTANTSTACK:\033[0m" << std::endl;
		MutantStack<int>	mStack;

		mStack.push(42);
		mStack.push(37);

		std::cout << mStack.top() << std::endl;

		mStack.pop();

		std::cout << mStack.size() << std::endl;

		mStack.push(20);
		mStack.push(60);
		mStack.push(0);
		mStack.push(77);

		MutantStack<int>::iterator	it	= mStack.begin();
		MutantStack<int>::iterator	end = mStack.end();

		++it;
		--it;
		std::cout << "Normal iterator: ";
		while (it != end)
		{
			std::cout << *it << " ";
			++it;
		}
		std::cout << std::endl;

		MutantStack<int>::const_iterator	cit	= mStack.cbegin();
		MutantStack<int>::const_iterator	cend = mStack.cend();

		++cit;
		--cit;
		std::cout << "Const iterator: ";
		while (cit != cend)
		{
			std::cout << *cit << " ";
			++cit;
		}
		std::cout << std::endl;

		MutantStack<int>::reverse_iterator	rit	= mStack.rbegin();
		MutantStack<int>::reverse_iterator	rend = mStack.rend();

		++rit;
		--rit;
		std::cout << "Reverse iterator: ";
		while (rit != rend)
		{
			std::cout << *rit << " ";
			++rit;
		}
		std::cout << std::endl;

		MutantStack<int>::const_reverse_iterator	crit	= mStack.crbegin();
		MutantStack<int>::const_reverse_iterator	crend = mStack.crend();

		++crit;
		--crit;
		std::cout << "Const reverse iterator: ";
		while (crit != crend)
		{
			std::cout << *crit << " ";
			++crit;
		}
		std::cout << std::endl << std::endl;
	}

	{
		std::cout << "\033[1;34mSTD::VECTOR\033[0m" << std::endl;
		std::vector<int>	v;

		v.push_back(42);
		v.push_back(37);

		std::cout << v.back() << std::endl;

		v.pop_back();

		std::cout << v.size() << std::endl;

		v.push_back(20);
		v.push_back(60);
		v.push_back(0);
		v.push_back(77);

		std::vector<int>::iterator	it	= v.begin();
		std::vector<int>::iterator	end = v.end();

		++it;
		--it;
		std::cout << "Normal iterator: ";
		while (it != end)
		{
			std::cout << *it << " ";
			++it;
		}
		std::cout << std::endl;

		std::vector<int>::const_iterator	cit	= v.cbegin();
		std::vector<int>::const_iterator	cend = v.cend();

		++cit;
		--cit;
		std::cout << "Const iterator: ";
		while (cit != cend)
		{
			std::cout << *cit << " ";
			++cit;
		}
		std::cout << std::endl;

		std::vector<int>::reverse_iterator	rit	= v.rbegin();
		std::vector<int>::reverse_iterator	rend = v.rend();

		++rit;
		--rit;
		std::cout << "Reverse iterator: ";
		while (rit != rend)
		{
			std::cout << *rit << " ";
			++rit;
		}
		std::cout << std::endl;

		std::vector<int>::const_reverse_iterator	crit	= v.crbegin();
		std::vector<int>::const_reverse_iterator	crend = v.crend();

		++crit;
		--crit;
		std::cout << "Const reverse iterator: ";
		while (crit != crend)
		{
			std::cout << *crit << " ";
			++crit;
		}
		std::cout << std::endl << std::endl;
	}

	{
		std::cout << "\033[1;34mSTD::LIST\033[0m" << std::endl;
		std::list<int>	v;

		v.push_back(42);
		v.push_back(37);

		std::cout << v.back() << std::endl;

		v.pop_back();

		std::cout << v.size() << std::endl;

		v.push_back(20);
		v.push_back(60);
		v.push_back(0);
		v.push_back(77);

		std::list<int>::iterator	it	= v.begin();
		std::list<int>::iterator	end = v.end();

		++it;
		--it;
		std::cout << "Normal iterator: ";
		while (it != end)
		{
			std::cout << *it << " ";
			++it;
		}
		std::cout << std::endl;

		std::list<int>::const_iterator	cit	= v.cbegin();
		std::list<int>::const_iterator	cend = v.cend();

		++cit;
		--cit;
		std::cout << "Const iterator: ";
		while (cit != cend)
		{
			std::cout << *cit << " ";
			++cit;
		}
		std::cout << std::endl;

		std::list<int>::reverse_iterator	rit	= v.rbegin();
		std::list<int>::reverse_iterator	rend = v.rend();

		++rit;
		--rit;
		std::cout << "Reverse iterator: ";
		while (rit != rend)
		{
			std::cout << *rit << " ";
			++rit;
		}
		std::cout << std::endl;

		std::list<int>::const_reverse_iterator	crit	= v.crbegin();
		std::list<int>::const_reverse_iterator	crend = v.crend();

		++crit;
		--crit;
		std::cout << "Const reverse iterator: ";
		while (crit != crend)
		{
			std::cout << *crit << " ";
			++crit;
		}
		std::cout << std::endl << std::endl;
	}

	{
		std::cout << "\033[1;34mSTD::DEQUE\033[0m" << std::endl;
		std::deque<int>	v;

		v.push_back(42);
		v.push_back(37);

		std::cout << v.back() << std::endl;

		v.pop_back();

		std::cout << v.size() << std::endl;

		v.push_back(20);
		v.push_back(60);
		v.push_back(0);
		v.push_back(77);

		std::deque<int>::iterator	it	= v.begin();
		std::deque<int>::iterator	end = v.end();

		++it;
		--it;
		std::cout << "Normal iterator: ";
		while (it != end)
		{
			std::cout << *it << " ";
			++it;
		}
		std::cout << std::endl;

		std::deque<int>::const_iterator	cit	= v.cbegin();
		std::deque<int>::const_iterator	cend = v.cend();

		++cit;
		--cit;
		std::cout << "Const iterator: ";
		while (cit != cend)
		{
			std::cout << *cit << " ";
			++cit;
		}
		std::cout << std::endl;

		std::deque<int>::reverse_iterator	rit	= v.rbegin();
		std::deque<int>::reverse_iterator	rend = v.rend();

		++rit;
		--rit;
		std::cout << "Reverse iterator: ";
		while (rit != rend)
		{
			std::cout << *rit << " ";
			++rit;
		}
		std::cout << std::endl;

		std::deque<int>::const_reverse_iterator	crit	= v.crbegin();
		std::deque<int>::const_reverse_iterator	crend = v.crend();

		++crit;
		--crit;
		std::cout << "Const reverse iterator: ";
		while (crit != crend)
		{
			std::cout << *crit << " ";
			++crit;
		}
		std::cout << std::endl << std::endl;
	}
}

int main( void )
{
	compareStacks();
	compareContainers();
}