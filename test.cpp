// CPP Program to demonstrate Big Integer data type
#include <iostream>
#include <array>
#include <vector>
#include <stack>


#include <iterator>
#include <vector>
#include "allocator/allocator.hpp"


int main()
{
    allocator<int> alloc;

    int *p = alloc.allocate(5);
    alloc.construct(p, 5);
    // p[5] = 5;
    // std::cout << alloc.address(*p) << std::endl;;
    // std::cout << &*p << std::endl;
    // // alloc.construct(p, 45);
    // // float *f = alloc2.allocate(6);
    // // alloc2.construct(f, 8.2);

    // // std::cout << *p << std::endl;
    // // std::cout << *f << std::endl;

}