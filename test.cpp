// CPP Program to demonstrate Big Integer data type
#include <iostream>
#include <array>
#include <vector>
#include <stack>


#include <iterator>
#include <vector>
#include "allocator/allocator.hpp"

void f()
{
    std::allocator<int> a;
    int *p = a.allocate(10);
    for (size_t i = 0; i < 10; i++)
        a.construct((p + i), i);    
    a.deallocate(p, 0);
    std::allocator<int> b(a)
    std::cout << &b << std::endl;
    std::cout << &a << std::endl;
}


int main()
{
    f();
    system("leaks alloc");
}