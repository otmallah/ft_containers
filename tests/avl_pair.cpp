/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avl_pair.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otmallah <otmallah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 15:55:53 by otmallah          #+#    #+#             */
/*   Updated: 2023/01/08 17:29:45 by otmallah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <map>

int main()
{
    std::map<int, int> a;
    a[2] = 51;
    a[1] = 510;
    a[3] = 5;
    a[6] = 501;
    a[9] = 511;
    std::map<int, int>::iterator it = a.begin();
    std::map<int, int>::iterator it1 = a.begin();
    it++;
    std::cout << *it << std::endl;

}
