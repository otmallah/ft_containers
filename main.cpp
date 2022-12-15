/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otmallah <otmallah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 01:54:59 by otmallah          #+#    #+#             */
/*   Updated: 2022/12/15 16:33:47 by otmallah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <vector>
#include "iterator.hpp"

bool mycomp (char c1, char c2)
{ return std::tolower(c1)<std::tolower(c2); }

int main()  
{
	std::vector<int> a(5, 6);
	
	std::vector<const int>::const_iterator it = a.begin();
	//*it = 5;
	std::cout << *it << std::endl;

// a case-insensitive comparison function:
	return 0;
	// it = a.rbegin();
	// it1 = a.rbegin();
	// it1++;
	// if (it < it1)
	// 	std::cout << "yes" << std::endl;
	// exit(0);
	
	
	// //std::cout << *it.base() << std::endl;

	// //exit(0);
	// //  if (it < (it + 1))
	// //  	puts("xjnc ");
	// for (int i = 0; i < a.size(); i++)
	// 	std::cout << a[i] << std::endl;

	return 0;
//   ft::vector<int> myvector;

//   // set some values (from 1 to 10)
//   for (int i=1; i<=10; i++) myvector.push_back(i);

//   // erase the 6th element
//   it = myvector.begin();
//   it += 5;
//   myvector.erase (it);

//   // erase the first 3 elements:
//   it1 = myvector.begin();
//   it1 += 3;
//   myvector.erase (myvector.begin(),it1);

//   std::cout << "myvector contains:";
//   for (unsigned i=0; i<myvector.size(); ++i)
//     std::cout << ' ' << myvector[i];
//   std::cout << '\n';

  return 0;

	//b.push_back(10000000);
	// a.push_back(1);
	// a.push_back(2);
	// a.push_back(3);
	// a.push_back(4);
	// a.push_back(5);
	// a.push_back(6);
	// a.push_back(7);
	// a.push_back(8);
	// a.push_back(9);
	// a.push_back(10);
	// a.push_back(11);
	// a.push_back(12);

	// it = a.begin();
	// it1 = a.begin();
	//std::cout << a.capacity() << std::endl;
	//std::cout << *it << std::endl;
	//std::cout << a.size() << std::endl;
	//it += 1;
	// b.insert(it,a.begin(), a.end());
	//std::cout << "capacity " << a.size() << std::endl;
	// it1 += 2;
	// a.erase(it, it1);
	//std::cout << a[1] << std::endl;
	//std::cout << "capacity " << a.capacity() << std::endl;
	//std::cout << "capacity " << a.size() << std::endl;

	for (size_t i = 0; i < a.size(); i++)
		std::cout << a[i] << std::endl;
	return 0;
}