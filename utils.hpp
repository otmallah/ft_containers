/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otmallah <otmallah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 17:50:08 by otmallah          #+#    #+#             */
/*   Updated: 2022/12/15 11:26:50 by otmallah         ###   ########.fr       */
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
	template <class InputIterator1, class InputIterator2>
 	 bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
                                InputIterator2 first2, InputIterator2 last2)
	{
		while (first1!=last1)
		{
			if (first2==last2 || *first2<*first1) return false;
			else if (*first1<*first2) return true;
			++first1; ++first2;
		}
		return (first2!=last2);
	}
	template<bool B, class T = void>
	struct enable_if {};
	
	template<class T>
	struct enable_if<true, T> { typedef T type; };
}
