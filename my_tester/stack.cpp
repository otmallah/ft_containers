/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otmallah <otmallah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 19:07:44 by otmallah          #+#    #+#             */
/*   Updated: 2023/01/15 20:26:58 by otmallah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../stack/stack.hpp"
#include <stack>
#include <unistd.h>


int main()
{
    std::cout << "-------------------------------------------" << std::endl;
    std::cout << "-------------- stack tester --------------" << std::endl;
    std::cout << "-------------------------------------------" << std::endl;
    


    {
        std::stack<int> stack;
        ft::stack<int> ft_stack;
        
        std::cout << std::endl;
        std::cout << "----------- Stack constructer ------";
        if (stack.empty() == ft_stack.empty())
            std::cout << "\033[1;32mOK\033[0m\n" ;
        else
            std::cout << "KO" << std::endl;
        sleep(1);
        stack.push(15);
        ft_stack.push(15);
        std::cout << "----------- push method ------------" ;
        if (stack.size() == ft_stack.size())
            std::cout << "\033[1;32mOK\033[0m\n" ;
        else
            std::cout << "KO" << std::endl;
        sleep(1);
        std::cout << "----------- top method ---------------" ;
        if (stack.top() == ft_stack.top())
            std::cout << "\033[1;32mOK\033[0m\n" ;
        else
            std::cout << "KO" << std::endl;
        std::cout << "----------- size method --------------";
        if (stack.size() == ft_stack.size())
            std::cout << "\033[1;32mOK\033[0m\n" ;
        else
            std::cout << "KO" << std::endl;
        std::cout << "----------- empty method ------------";
        if (stack.empty() == ft_stack.empty())
            std::cout << "\033[1;32mOK\033[0m\n" ;
        else
            std::cout << "KO" << std::endl;
        
        stack.pop();
        ft_stack.pop();
        std::cout << "------------ pop method -------------";
        if (stack.size() == ft_stack.size())
            std::cout << "\033[1;32mOK\033[0m\n" ;
        else
            std::cout << "KO" << std::endl;
    }
}