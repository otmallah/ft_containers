/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otmallah <otmallah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 01:54:59 by otmallah          #+#    #+#             */
/*   Updated: 2022/12/17 19:59:49 by otmallah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <vector>
#include <stack>
#include "stack.hpp"


int main()  
{
	ft::vector<int>  a(2,5);
	ft::vector<int>::const_iterator it = a.end();
	it--;
	std::cout << *it ;
	//std::cout << &it.base() << std::endl;
	
	return 0;
}