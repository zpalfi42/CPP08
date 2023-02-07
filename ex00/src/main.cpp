#include <easyfind.tpp>
#include <vector>
#include <list>

int main(int, char**)
{
    {
        std::cout << "\033[1;35mSTD::VECTOR\033[0m" << std::endl;
        std::vector<int>    v;

        for (int i = 0; i < 10; i++)
            v.push_back(i);
        std::cout << "\033[1;34mTrying to easyfind number 3: \033[0m" << std::endl;
        ::easyfind(v, 3);
        std::cout << "\033[1;34mTrying to easyfind number 42: \033[0m" << std::endl;
        try
        {
            ::easyfind(v, 42);
        }
        catch(const std::exception& e)
        {
            std::cout << e.what() << '\n';
        }
    }
    
    std::cout << std::endl;

    {
        std::cout << "\033[1;35mSTD::LIST\033[0m" << std::endl;
        std::list<int>  l;
        for (int i = 0; i < 10; i++)
            l.push_back(i);
        std::cout << "\033[1;34mTrying to easyfind number 3: \033[0m" << std::endl;
        ::easyfind(l, 3);
        std::cout << "\033[1;34mTrying to easyfind number 42: \033[0m" << std::endl;
        try
        {
            ::easyfind(l, 42);
        }
        catch(const std::exception& e)
        {
            std::cout << e.what() << '\n';
        }
    }

    std::cout << std::endl;

    {
        std::cout << "\033[1;35mSTD::DEQUE\033[0m" << std::endl;
        std::list<int>  l;
        for (int i = 0; i < 10; i++)
            l.push_back(i);
        std::cout << "\033[1;34mTrying to easyfind number 3: \033[0m" << std::endl;
        ::easyfind(l, 3);
        std::cout << "\033[1;34mTrying to easyfind number 42: \033[0m" << std::endl;
        try
        {
            ::easyfind(l, 42);
        }
        catch(const std::exception& e)
        {
            std::cout << e.what() << '\n';
        }
    }
}