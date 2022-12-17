// CPP Program to demonstrate Big Integer data type
#include <iostream>
#include <array>
#include <vector>
#include <stack>


void    print(std::stack<int> a)
{
    if (a.empty())
        return;
    int x = a.top();
    //std:: cout << x << "--";    
    a.pop();
    print(a);
    std:: cout << x << " -*->\n";    
}

int main()
{
    std::stack<int> a;

    a.push(1);
    a.push(2);
    a.push(3);
    a.push(4);

    print(a);
}