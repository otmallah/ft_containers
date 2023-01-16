/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otmallah <otmallah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 21:11:31 by otmallah          #+#    #+#             */
/*   Updated: 2023/01/16 20:25:26 by otmallah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector/vector.hpp"
#include "stack/stack.hpp"
#include "map/map.hpp"
#include <vector>
#include <map>

int     main()
{
    std::map<int, std::string>::iterator it, it1;

    ft::map<int, std::string> my_m;
    ft::map<int, std::string>::iterator my_it, my_it1, tmp;

    for (int i = 0; i < 1e2; ++i)
    {
        my_m.insert(ft::make_pair(i, "value"));
    }

    my_it1 = my_m.begin();
    my_it1++;
    //my_m.erase(my_m.begin(), my_m.end());
    my_m.erase(100);
    system("leaks a.out");
    
}