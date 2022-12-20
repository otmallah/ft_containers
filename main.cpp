/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otmallah <otmallah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 01:54:59 by otmallah          #+#    #+#             */
/*   Updated: 2022/12/20 22:54:01 by otmallah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector/vector.hpp"
#include <vector>
#include <stack>
#include "stack/stack.hpp"


int main()  
{
	std::vector<int> vec;

	vec.push_back(15);

	std::vector<int>::iterator it;
	std::vector<int>::iterator it1;
	
	it = vec.begin();
	it1 = vec.begin();


	for (size_t i = 0; i < vec.size() ; i++)
		std::cout << vec[i] << std::endl;
}