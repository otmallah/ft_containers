/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otmallah <otmallah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 21:11:31 by otmallah          #+#    #+#             */
/*   Updated: 2023/01/16 13:17:55 by otmallah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector/vector.hpp"
#include "stack/stack.hpp"
#include "map/map.hpp"
#include <vector>

int     main()
{
    ft::vector<int> vec(5, 20);

    int i = 0;
    for (ft::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
        std::cout << "values = " << vec.at(i) << std::endl;
    vec.assign(5, 5);
    vec.insert(vec.begin() + 1, vec.begin(), vec.end());
}