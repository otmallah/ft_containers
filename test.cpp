

#include <iostream>
#include <utility>

int     get(int&  a)
{
    return a;
}

int main()
{
    std::pair<int, std::string> test;

    test = std::make_pair(20, "ksdncdklscs");
    std::cout << test.first << std::endl;
    std::cout << test.second << std::endl;
}