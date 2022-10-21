/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otmallah <otmallah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 17:50:08 by otmallah          #+#    #+#             */
/*   Updated: 2022/10/21 22:09:09 by otmallah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template <class Iterator> struct iterator_traits {
	typedef typename Iterator::differance_type  differance_type;
	typedef typename Iterator::value_type       value_type;
	typedef typename Iterator::pointer          pointer;
	typedef typename Iterator::refrence         refrence;
	typedef typename Iterator::iterator_category    iterator_category;
};

template <class T> struct iterator_traits<T*> {
	typedef ptrdiff_t  differance_type;
	typedef T			value_type;
	typedef T*			pointer;
	typedef T&			refrence;
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
		
	};
}

template <class T1, class T2>  
ft::pair<T1,T2> make_pair (T1 x, T2 y)
{
	return (ft::pair<T1, T2>(x, y));
}

int main () 
{
  ft::pair <int,int> foo;
  ft::pair <int,int> bar;

  foo = make_pair (10,20);
  bar = make_pair (10.5,'A'); // ok: implicit conversion from pair<double,char>

  std::cout << "foo: " << foo.first << ", " << foo.second << '\n';
  std::cout << "bar: " << bar.first << ", " << bar.second << '\n';

  return 0;
}