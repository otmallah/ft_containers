/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avl_pair.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otmallah <otmallah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 15:55:53 by otmallah          #+#    #+#             */
/*   Updated: 2023/01/12 02:19:28 by otmallah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <map>

#include "../map/map.hpp"

int main ()
{
    ft::map<int, int> test;
    test.insert(std::make_pair(5, 2));
    std::map<int, int> test1;
    test1.insert(std::make_pair(5, 2));


    if (test == test1)
        puts("hana");
}