/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otmallah <otmallah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 01:54:59 by otmallah          #+#    #+#             */
/*   Updated: 2022/10/20 21:45:11 by otmallah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <vector>
#include "iterator.hpp"

int main()  
{
    std::vector<int> a;
    // std::vector<int>::iterator:: a;
    a.push_back(4);
    a.push_back(4);
    a.push_back(4);
    a.resize(2);
    std::cout << a.capacity() << std::endl;
    std::cout << a.at(0) << std::endl;
    std::cout << a.at(1) << std::endl;
    // std::cout << a.at(2) << std::endl;
} 


/*
        Fixed& operator=(const Fixed& fix);
        Fixed operator+(const Fixed& fix);
        Fixed operator*(const Fixed& fix);
        Fixed operator-(const Fixed& fix) ;
        Fixed operator/(const Fixed& fix) ;
        bool operator==(const Fixed& fix1);
        bool operator!=(const Fixed& fix1);
        bool operator<(const Fixed& fix1) const;
        bool operator>(const Fixed& fix1) const ;
        bool operator>=(const Fixed& fix1);
        bool operator<=(const Fixed& fix1);
        Fixed operator++();
        Fixed operator++(int);
        Fixed operator--();
        Fixed operator--(int);
        
*/