// CPP Program to demonstrate Big Integer data type
#include <iostream>
#include <array>
#include <vector>
#include <stack>


#include <iterator>
#include <vector>

// void    print(int a)
// {
//     std::cout << " int a" << std::endl;
// }

// void    print(size_t n, const size_t& val)
// {
//     puts("hanan");
//     for (size_t i = 0; i < n; i++)
//         std::cout << val << std::endl;
// }

// template <typename Inputiterator>
// bool    print(Inputiterator first, typename std::enable_if<std::__is_input_iterator<Inputiterator>::value
//                                 && !std::is_integral<Inputiterator>::value, Inputiterator>::type last)
// {
//     puts("hana");
//     while (first++ != last - 1)
//         std::cout << *first << std::endl;
//     return true;
// }

class a 
{
    private :
        int _num;
    public :
        a() { std::cout << " test a\n";}
    class b 
    {
        private :
            int __num;
        public :
            b() { std::cout << " test b\n"}
    }
}


int main()
{
    std::vector<int> a;
    
    for (size_t i = 0; i < 10; i++)
        a.push_back(i);
    
    print(3, 10);
}
