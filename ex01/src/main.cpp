#include <Span.hpp>
#include <vector>
#include <list>
#include <unistd.h>
#include <limits.h>

int main( void )
{
    srand(time(NULL));

    std::cout << "Example using span with a VECTOR..." << std::endl;
    std::vector<int>    vec;
    Span    spanVec(10000);
    for (int i = 0; i < 10000; i++)
        vec.push_back(rand() % 9999);
    spanVec.fillNumbers<std::vector <int> >(vec.begin(), vec.end());

    std::cout << "Shortest span: " << spanVec.shortestSpan() << std::endl;
    std::cout << "Longest span: " << spanVec.longestSpan() << std::endl << std::endl;

    sleep(1);
    std::cout << "Example using span with a LIST..." << std::endl;
    std::list<int>  lst;
    Span    spanLst(10000);
    for (int i = 0; i < 10000; i++)
        lst.push_back(rand() % 9999);
    spanLst.fillNumbers<std::list <int> >(lst.begin(), lst.end());

    std::cout << "Shortest span: " << spanLst.shortestSpan() << std::endl;
    std::cout << "Longest span: " << spanLst.longestSpan() << std::endl << std::endl;

    std::cout << "Trying to add a number when _numbers is Full: ";

    std::vector<int> fullVec;
    Span        fullSpan(10000);
    for (int i = 0; i < 10000; i++)
        fullVec.push_back(rand() % 9999);
    fullSpan.fillNumbers<std::vector <int> >(fullVec.begin(), fullVec.end());

    try
    {
        fullSpan.addNumber(1);
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }

    std::cout << "Trying to perform a action using a class with no more than 1 number: ";
    
    Span    noNumSpan(0);
    try
    {
        noNumSpan.shortestSpan();
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
    
    std::cout << "Trying to perform a action using a class with no more than 1 number: ";

    try
    {
        noNumSpan.longestSpan();
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n' << std::endl;
    }

    std::cout << "Working with INT_MAX and INT_MIN:" << std::endl;

    Span    maxSpan(2);
    maxSpan.addNumber(INT_MAX);
    maxSpan.addNumber(INT_MIN);

    std::cout << "Shortest span: " << maxSpan.shortestSpan() << std::endl;
    std::cout << "Longest span: " << maxSpan.longestSpan() << std::endl;

    std::cout << "Testing copy constructor and = operator..." << std::endl;

    Span    generalSpan(10);

    for (int i = 0; i < 10; i++)
        generalSpan.addNumber(i);
    
    Span    copySpan(generalSpan);

    if (generalSpan.size() != copySpan.size())
        std::cout << "FAIL" << std::endl;
    else
        std::cout << "Sizes are the same!" << std::endl;

}