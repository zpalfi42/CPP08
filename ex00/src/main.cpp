#include <easyfind.tpp>
#include <vector>
#include <list>

int main(int, char**)
{
    std::vector<int>    v;

    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    ::easyfind(v, 3);
    try
    {
        ::easyfind(v, 42);
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
    
    std::list<int>  l;
    for (int i = 0; i < 10; i++)
    {
        l.push_back(i);
    }
    ::easyfind(l, 5);
    try
    {
        ::easyfind(l, 42);
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
    
}