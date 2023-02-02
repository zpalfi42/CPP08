#include <Span.hpp>
#include <vector>
#include <list>
#include <unistd.h>

int main( void )
{
    std::cout << "Example using span with a VECTOR..." << std::endl;
    std::vector<int>    vec;    
    srand(time(NULL));
    for (int i = 0; i < 10000; i++)
    {
        vec.push_back(rand() % 9999);
    }

    Span    span(10000);
    span.fillNumbers<std::vector <int> >(vec.begin(), vec.end());
    std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
    std::cout << "Longest span: " << span.longestSpan() << std::endl;

    sleep(2);
    std::cout << std::endl;
    std::cout << "Example using span with a LIST..." << std::endl;
    std::list<int>  lst;
    for (int i = 0; i < 10000; i++)
    {
        lst.push_back(rand() % 9999);
    }

    Span    span2(10000);
    span2.fillNumbers<std::list <int> >(lst.begin(), lst.end());
    std::cout << "Shortest span: " << span2.shortestSpan() << std::endl;
    std::cout << "Longest span: " << span2.longestSpan() << std::endl << std::endl;
    try
    {
        std::cout << "Trying to add a number when _numbers is Full: "; 
        span2.addNumber(1);
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
    
    Span    span3(1);
    span3.addNumber(1);
    try
    {
        std::cout << "Trying to perform a action using a class with no more than 1 number: ";
        span3.shortestSpan();
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
    
    try
    {
        std::cout << "Trying to perform a action using a class with no more than 1 number: ";
        span3.longestSpan();
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
}