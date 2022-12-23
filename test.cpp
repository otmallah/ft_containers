// CPP Program to demonstrate Big Integer data type
#include <iostream>
#include <array>
#include <vector>
#include <stack>


#include <iterator>
#include <vector>


int main()
{
    std :: vector <int> vec1;
    std :: vector <int> vec2;
  
    for (size_t i = 0; i < 5; i++)
    {
      vec1.push_back(i);
      vec2.push_back(7);
    }
    
    // Print elements
    std :: cout << "Vector1 contains :";
    for(int i = 0; i < vec1.size(); i++)
        std :: cout << " " << vec1[i];
    std :: cout << "\n";
      
    // Print elements
    std :: cout << "Vector2 contains :";
    for(unsigned int i = 0; i < vec2.size(); i++)
        std :: cout << " " << vec2[i];
    std :: cout << "\n\n";
      
    // std :: move function
    // move first 4 element from vec1 to starting position of vec2
    std :: move (vec1.begin(), vec1.begin() + 3, vec2.begin() + 1);
      
    // Print elements
    std :: cout << "Vector2 contains after std::move function:";
    for(unsigned int i = 0; i < vec2.size(); i++)
        std :: cout << " " << vec2[i];
    std :: cout << "\n";    
}
