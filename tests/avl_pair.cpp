/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avl_pair.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otmallah <otmallah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 15:55:53 by otmallah          #+#    #+#             */
/*   Updated: 2023/01/08 21:46:59 by otmallah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <map>

#include "../utils/bidirectional_iterator.hpp"

int main()
{
    AVL_TREE<std::pair<int, int> > vec;
    vec.insert(std::make_pair(5, 6));
    vec.insert(std::make_pair(57, 60));


    ft::__map_iterator<Node<std::pair<int, int> >, std::pair<int, int> > it;
    it  = ft::__map_iterator<Node<std::pair<int, int> >, std::pair<int, int> >(vec.get());
    std::cout << it.first;
    
}
