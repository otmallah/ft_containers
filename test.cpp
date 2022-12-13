// CPP Program to demonstrate Big Integer data type
#include <iostream>
#include <array>
#include <vector>


template<typename T> void print(T a)
{
    std::cout << a << " template" << std::endl;
}

void print(int x)
{
    std::cout << x << " is an integer" << std::endl;
}

void print(double x)
{
    std::cout << x << " is a floating-point number" << std::endl;
}

// void print(float x)
// {
//     std::cout << x << " is a floating-point number" << std::endl;
// }

int main()
{
    print(42.12f);     // outputs "42 is an integer"
    //print(3.1415); // outputs "3.1415 is a floating-point number"
    return 0;
}
