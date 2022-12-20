/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otmallah <otmallah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 01:54:59 by otmallah          #+#    #+#             */
/*   Updated: 2022/12/20 12:54:59 by otmallah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector/vector.hpp"
#include <vector>
#include <stack>
#include "stack/stack.hpp"


int main()  
{
	std::vector<int> a;

	for (size_t i = 0; i < 10; i++)
		a.push_back(i);
	
	std::vector<int> b;
	for (size_t i = 0; i < 20; i++)
		b.push_back(8);
	

	b.assign(a.begin(), a.end());
	for (size_t i = 0; i < b.size(); i++)
		std::cout << b[i] << std::endl;


	//ft::vector<int> b(a.begin(), a.end());
	// a.push_back(15);
	// a.push_back(150);
	// ft::vector<int>::const_reverse_iterator it = a.rbegin();
	// std::cout << *it << std::endl;
}