/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otmallah <otmallah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 01:54:59 by otmallah          #+#    #+#             */
/*   Updated: 2022/12/19 17:55:57 by otmallah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector/vector.hpp"
#include <vector>
#include <stack>
#include "stack/stack.hpp"


int main()  
{
	ft::vector<int> a(5, 2);
	ft::vector<int>::iterator it = a.begin();  
	
	std::cout << *it.base() << std::endl;
	//ft::vector<int> b(a.begin(), a.end());
	// a.push_back(15);
	// a.push_back(150);
	// ft::vector<int>::const_reverse_iterator it = a.rbegin();
	// std::cout << *it << std::endl;
}