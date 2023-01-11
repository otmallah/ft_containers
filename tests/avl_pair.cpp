/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avl_pair.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otmallah <otmallah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 15:55:53 by otmallah          #+#    #+#             */
/*   Updated: 2023/01/11 17:48:12 by otmallah         ###   ########.fr       */
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
 ft::map<char,int> foo,bar;


    foo.insert(std::make_pair('x', 100));
    foo.insert(std::make_pair('y', 200));


    bar.insert(std::make_pair('a', 11));
    bar.insert(std::make_pair('b', 22));
    bar.insert(std::make_pair('c', 33));
    foo.swap(bar);

    std::cout << foo.size() << std::endl;
    std::cout << bar.size() << std::endl;
  std::cout << "foo contains:\n";
  for (ft::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
  {
    //puts("hana");
    std::cout << it->first << " => " << it->second << '\n';
  }

  std::cout << "bar contains:\n";
  for (ft::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

}