/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otmallah <otmallah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 17:50:08 by otmallah          #+#    #+#             */
/*   Updated: 2022/12/12 16:40:10 by otmallah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template <class Iterator> struct iterator_traits {
	typedef typename Iterator::difference_type  difference_type;
	typedef typename Iterator::value_type       value_type;
	typedef typename Iterator::pointer          pointer;
	typedef typename Iterator::reference         reference;
	// typedef typename Iterator::iterator_category    iterator_category;
};

template <class T> struct iterator_traits<T*> {
	typedef ptrdiff_t  differance_type;
	typedef T			value_type;
	typedef T*			pointer;
	typedef T&			reference;
	typedef	std::random_access_iterator_tag iterator_category;
};

template <class T> struct iterator_traits<const T*> {
	typedef ptrdiff_t  differance_type;
	typedef T			value_type;
	typedef const T*			pointer;
	typedef const T&			refrence;
	typedef	std::random_access_iterator_tag iterator_category;
};

namespace ft
{
	template <class T1, class T2> struct pair
	{
		public :
			typedef	T1	first_type;	
			typedef	T2	second_type;
		
		public :
			first_type first;
			second_type second;
			pair() : first(0) {}
			template <class U, class V> pair (const pair<U, V>& pr)
			{
				this->first = pr.first;
				this->second = pr.second;
			}
			pair (const first_type& a, const second_type& b)
			{
				this->first = a;
				this->second = b;
			}
			pair& operator = (const pair& pr)
			{
				first = pr.first;
				second = pr.second;
				return *this;
			}
			void swap (pair& pr)
			{
				std::swap(first,pr.first);
				std::swap(second,pr.second);
			}
		
	};
	template <class T1, class T2>  
	ft::pair<T1,T2> make_pair (T1 x, T2 y)
	{
		return (ft::pair<T1, T2>(x, y));
	}
	template <class InputIterator1, class InputIterator2>
		bool equal ( InputIterator1 first1, InputIterator1 last1, InputIterator2 first2 )
	{
		while (first1 != last1)
		{
			if(!(*first1 == *first2))
				return false;
			++first1;
			++first2;
		}
		return true;
	}
	template <class T> struct is_integral
	{
		public :
			// typedef	value_type	T;
			
			
	};
}


// #include <typeinfo>

// int main () 
// {
// //   ft::pair <int,int> foo;
// //   ft::pair <int,int> bar;

// //   foo = make_pair (10,20);
// //   bar = make_pair (10.5,'A'); // ok: implicit conversion from pair<double,char>

// //   std::cout << "foo: " << foo.first << ", " << foo.second << '\n';
// //   std::cout << "bar: " << bar.first << ", " << bar.second << '\n';

// //   ft::pair<int,char> foo1 (10,'a');
// //   ft::pair<int,char> bar1 (90,'z');

// //   foo1.swap(bar1);
  
// //   std::cout << "foo contains: " << foo1.first;
// //   std::cout << " and " << foo1.second << '\n';

// // //   return 0;
// // 	int num[5] = {20, 65,98,57,19};
// // 	std::vector<int> num2(num, num+5);

// //   if ( ft::equal (num2.begin(), num2.end(), num) )
// //     std::cout << "The contents of both sequences are equal.\n";
// //   else
// //     std::cout << "The contents of both sequences differ.\n";
// //   char foo[]="Apple";
// //   char bar[]="apartment";

// //   std::cout << std::boolalpha;

// //   std::cout << "Comparing foo and bar lexicographically (foo<bar):\n";

// //   std::cout << "Using default comparison (operator<): ";
// //   std::cout << std::lexicographical_compare(foo,bar+9,bar,foo+5);
// //   std::cout << '\n';

// //   std::cout << "Using mycomp as comparison object: ";
// //   std::cout << std::lexicographical_compare(foo,foo+3,bar,bar+3,mycomp);
// //   std::cout << '\n';
// //   std::cout << std::boolalpha;
// //   std::cout << "is_integral:" << std::endl;
// //   std::cout << "char: " << std::is_integral<char>::value << std::endl;
// //   std::cout << "int: " << std::is_integral<int>::value << std::endl;
// //   std::cout << "float: " << std::is_integral<float>::value << std::endl;
	 
	
	
	
//   return 0;
// }
