/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otmallah <otmallah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 21:11:58 by otmallah          #+#    #+#             */
/*   Updated: 2023/01/03 19:54:37 by otmallah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include <map>
#include <iostream>
#include <map>

int main()
{

    std::map<std::string, int> map;

    map["one"] = 1;
    map["two"] = 2;
    map["three"] = 3;

    std::map<std::string, int>::iterator it = map.begin();

    while (it != map.end())
    {
        std::cout << "Key: " << it->first << ", Value: " << it->second << std::endl;
        ++it;
    }

    return 0;
}
