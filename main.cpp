/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otmallah <otmallah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 01:54:59 by otmallah          #+#    #+#             */
/*   Updated: 2022/12/30 16:33:37 by otmallah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector/vector.hpp"
#include <vector>
#include <stack>
#include "stack/stack.hpp"
#include <sys/time.h>
#include <vector>
#include <iostream>
#include <iterator>
#include <ctime>
#include <iomanip>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>
#include <list>

#include "./containers_test/srcs/base.hpp"
#include "./containers_test/srcs/vector/common.hpp"


#include <unistd.h>
#include <sys/time.h>
#include "containers_test/srcs/base.hpp"
#define TESTED_TYPE int

void	f()
{
	ft::allocator<int> a;
	int *p = a.allocate(5);
	a.deallocate(p, 5);
}

int main(void)
{

	int num = ~0;
	std::cout << int(~0)  << std::endl;
	std::cout << std::numeric_limits<int>::max() << std::endl;

}