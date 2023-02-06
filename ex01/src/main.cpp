#include <Span.hpp>
#include <vector>
#include <list>
#include <unistd.h>
#include <limits.h>

void    testComparation( Span &a, Span &b)
{
    std::cout << "Testing SIZES...: ";
    if (a.size() != b.size())
        std::cout << "\033[1;31mFAIL\033[0m" << std::endl;
    else
        std::cout << "\033[1;32mSizes are the same!\033[0m" << std::endl;

    std::cout << "Testing NUMBERS...: ";
    bool aux = true;
    for (size_t i = 0; i < a.size(); i++)
    {
        if (a.getNum(i) != a.getNum(i))
        {
            std::cout << "\033[1;31mFAIL\033[0m" << std::endl;
            aux = false;
        }
    }
    if (aux)
        std::cout << "\033[1;32mNumbers are the same!\033[0m" << std::endl;
}

int main( void )
{
    srand(time(NULL));

    std::cout << "\033[1;34mExample using span with a VECTOR...\033[0m" << std::endl;
    std::vector<int>    vec;
    Span    spanVec(10000);
    for (int i = 0; i < 10000; i++)
        vec.push_back(rand() % 9999);
    spanVec.fillNumbers<std::vector <int> >(vec.begin(), vec.end());

    std::cout << "Shortest span: " << spanVec.shortestSpan() << std::endl;
    std::cout << "Longest span: " << spanVec.longestSpan() << std::endl << std::endl;

    sleep(1); // This sleep is for changing the rand() returns.
    std::cout << "\033[1;34mExample using span with a LIST...\033[0m" << std::endl;
    std::list<int>  lst;
    Span    spanLst(10000);
    for (int i = 0; i < 10000; i++)
        lst.push_back(rand() % 9999);
    spanLst.fillNumbers<std::list <int> >(lst.begin(), lst.end());

    std::cout << "Shortest span: " << spanLst.shortestSpan() << std::endl;
    std::cout << "Longest span: " << spanLst.longestSpan() << std::endl << std::endl;

    std::cout << "\033[1;34mTrying to FILL a number when _numbers is Full: \033[0m" << std::endl;
    Span        fullSpan(10000);
    fullSpan.fillNumbers<std::vector <int> >(vec.begin(), vec.end());
    try
    {
        fullSpan.fillNumbers<std::vector <int> >(vec.begin(), vec.end());
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }

    std::cout << "\033[1;34mTrying to ADD a number when _numbers is Full: \033[0m" << std::endl;
    try
    {
        fullSpan.addNumber(1);
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }

    std::cout << std::endl << "\033[1;34mTrying to perform a action using a class with no numbers: \033[0m" << std::endl;
    Span    noNumSpan(0);
    try
    {
        noNumSpan.shortestSpan();
        std::cout << "\033[1;31mFAILED\033[0m" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }

    std::cout << "\033[1;34mTrying to perform a action using a class with no numbers: \033[0m" << std::endl;
    try
    {
        noNumSpan.longestSpan();
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n' << std::endl;
    }

    std::cout << "\033[1;34mTrying to perform a action using a class with no more than 1 number: \033[0m" << std::endl;
    Span    oneNumSpan(1);
    oneNumSpan.addNumber(1);
    try
    {
        oneNumSpan.shortestSpan();
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }

    std::cout << "\033[1;34mTrying to perform a action using a class with no more than 1 number: \033[0m" << std::endl;
    try
    {
        oneNumSpan.longestSpan();
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n' << std::endl;
    }

    std::cout << "\033[1;34mWorking with INT_MAX and INT_MIN:\033[0m" << std::endl;
    Span    maxSpan(2);
    maxSpan.addNumber(INT_MAX);
    maxSpan.addNumber(INT_MIN);
    std::cout << "Shortest span: " << maxSpan.shortestSpan() << std::endl;
    std::cout << "Longest span: " << maxSpan.longestSpan() << std::endl << std::endl;

    std::cout << "\033[1;34mTesting copy constructor...\033[0m" << std::endl;
    Span    generalSpan(10000);
    generalSpan.fillNumbers<std::vector <int> >(vec.begin(), vec.end());
    Span    copySpan(generalSpan);
    testComparation(generalSpan, copySpan);

    std::cout << std::endl << "\033[1;34mTesting = operator...\033[0m" << std::endl;
    Span    generalSpan2(10000);
    Span    copySpan2;
    generalSpan2.fillNumbers<std::vector <int> >(vec.begin(), vec.end());
    copySpan2 = generalSpan2;
    testComparation(generalSpan2, copySpan2);
}