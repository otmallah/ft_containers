/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otmallah <otmallah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 01:54:59 by otmallah          #+#    #+#             */
/*   Updated: 2023/01/08 19:49:42 by otmallah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector/vector.hpp"
#include <vector>
#include <stack>
#include "stack/stack.hpp"
#include <sys/time.h>
#include <vector>
#include <map>
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

#include "./tests/AVL.hpp"

int main(void)
{
	AVL_TREE<std::pair<int, int> > a;
	a.insert(std::make_pair(5, 9));
	a.insert(std::make_pair(50, 90));

	ft::vector<AVL_TREE<std::pair<int, int> > > vec;
	
	vec.push_back(a);
	vec[0].printInorder();
}