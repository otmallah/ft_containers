/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otmallah <otmallah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 15:53:56 by otmallah          #+#    #+#             */
/*   Updated: 2023/01/15 20:33:47 by otmallah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vector/vector.hpp"
#include <vector>
#include <unistd.h>
#include <iostream>

int main()
{
    std::cout << "-------------------------------------------" << std::endl;
    std::cout << "-------------- vector tester --------------" << std::endl;
    std::cout << "-------------------------------------------" << std::endl;
    
    std::cout << std::endl;

    {
        std::vector<int> vec(5, 10);
        std::vector<int>::iterator it;
        ft::vector<int> ft_vec(5, 10);
        ft::vector<int>::iterator ft_it;

        std::cout << " -------- size method             ----------- > " ;
        if (vec.size() == ft_vec.size())
            std::cout << "\033[1;32mOK\033[0m\n" ;
        else
            std::cout << "KO" << std::endl;
        sleep(1);
        std::cout << " -------- capacity method         ----------- > " ;
        if (vec.capacity() == ft_vec.capacity())
            std::cout << "\033[1;32mOK\033[0m\n" ;
        else
            std::cout << "KO" << std::endl;
        sleep(1);
        std::cout << " -------- empty method            ----------- > " ;
        if (vec.empty() == ft_vec.empty())
            std::cout << "\033[1;32mOK\033[0m\n"  ;
        else
            std::cout << "KO" << std::endl;
        sleep(1);
        it = vec.begin();
        ft_it = ft_vec.begin();
        
        std::cout << " -------- itertor                 ----------- > " ;
        if (*it == *ft_it)
            std::cout << "\033[1;32mOK\033[0m\n"  ;
        else
            std::cout << "KO" << std::endl;
        sleep(1);
        
        std::cout << " -------- begin() end()           ----------- > " ;
        if (*vec.begin() == *ft_vec.begin())
            std::cout << "\033[1;32mOK\033[0m\n" ;
        else
            std::cout << "KO" << std::endl;
        sleep(1);

        std::vector<int>::reverse_iterator rev_it = vec.rbegin();
        ft::vector<int>::reverse_iterator ft_rev_it = ft_vec.rbegin();
    
        std::cout << " -------- reverse_iterator        ----------- > " ;
        if (*ft_rev_it == *rev_it)
            std::cout << "\033[1;32mOK\033[0m\n"  ;
        else
            std::cout << "KO" << std::endl;
        sleep(1);
        
        std::cout << " -------- rbegin() rend()         ----------- > " ;
        if (*vec.rbegin() == *ft_vec.rbegin())
            std::cout << "\033[1;32mOK\033[0m\n" ;
        else
            std::cout << "KO" << std::endl;
        sleep(1);
        std::cout << " -------- max size                ----------- > " ;
        if (vec.max_size() == ft_vec.max_size())
            std::cout << "\033[1;32mOK\033[0m\n"  ;
        else
            std::cout << "KO" << std::endl;
        sleep(1);
       
        std::cout << " -------- front                   ----------- > " ;
        if (vec.front() == ft_vec.front())
            std::cout << "\033[1;32mOK\033[0m\n" ;
        else
            std::cout << "KO" << std::endl;
        sleep(1);
        std::cout << " -------- back                    ----------- > " ;
        if (vec.back() == ft_vec.back())
            std::cout << "\033[1;32mOK\033[0m\n";
        else
            std::cout << "KO" << std::endl;
        sleep(1);
        
        vec.assign(5, 20);
        ft_vec.assign(5, 20);

        std::cout << " -------- assing                  ----------- > " ;
        if (vec.size() == ft_vec.size())
            std::cout << "\033[1;32mOK\033[0m\n"  ;
        else
            std::cout << "KO" << std::endl;
        sleep(1);
        vec.push_back(15);
        ft_vec.push_back(15);
        std::cout << " -------- push_back               ----------- > " ;
        if (vec.size() == ft_vec.size())
            std::cout << "\033[1;32mOK\033[0m\n" ;
        else
            std::cout << "KO" << std::endl;
        sleep(1);

        vec.pop_back();
        ft_vec.pop_back();
        std::cout << " -------- pop_back                ----------- > " ;
        if (vec.size() == ft_vec.size())
            std::cout << "\033[1;32mOK\033[0m\n";
        else
            std::cout << "KO" << std::endl;
        sleep(1);
        
        it = vec.begin();
        ft_it = ft_vec.begin();

        vec.insert(it, 15);
        ft_vec.insert(ft_it, 15);
        std::cout << " -------- insert                  ----------- > " ;
        if (vec[0] == ft_vec[0])
            std::cout << "\033[1;32mOK\033[0m\n";
        else
            std::cout << "KO" << std::endl;
        sleep(1);
    
        it = vec.begin();
        ft_it = ft_vec.begin();

        vec.erase(it);
        ft_vec.erase(ft_it);
        std::cout << " -------- erase                   ----------- > " ;
        if (vec[0] == ft_vec[0])
            std::cout << "\033[1;32mOK\033[0m\n";
        else
            std::cout << "KO" << std::endl;
        sleep(1);
        
        vec.clear();
        ft_vec.clear();
        std::cout << " -------- clear                   ----------- > " ;
        if (vec.size() == ft_vec.size())
            std::cout << "\033[1;32mOK\033[0m\n" ;
        else
            std::cout << "KO" << std::endl;

    }

    
}