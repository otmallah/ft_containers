/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avl_pair.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otmallah <otmallah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 15:55:53 by otmallah          #+#    #+#             */
/*   Updated: 2023/01/09 23:14:39 by otmallah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <map>

#include "../utils/bidirectional_iterator.hpp"
#include "AVL.hpp"

#include "../map/map.hpp"

int main()
{   
    ft::map<int, int> map;
    map.insert(std::make_pair(5, 9));
    map.insert(std::make_pair(15, 20));
    map.insert(std::make_pair(9, 8));
    ft::map<int, int>::iterator it = map.begin();
    std::cout << it->first << std::endl;
    it++;
    std::cout << it->first << std::endl;
    it++;
    std::cout << it->first << std::endl;

    std::cout << "size = " << map.size() << std::endl;
    

 
}
