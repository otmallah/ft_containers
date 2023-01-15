/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otmallah <otmallah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 18:00:15 by otmallah          #+#    #+#             */
/*   Updated: 2023/01/15 21:00:25 by otmallah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _PAIR_HPP_
#define _PAIR_HPP_

#include <iostream>
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
			pair() : first(),second() {}
			template <class U, class V>  pair (const pair<U, V>& pr):first(pr.first),second(pr.second)
			{
				
			}
			pair (const first_type& a, const second_type& b):first(a),second(b)
			{
			
			}
			pair& operator = (pair const& pr)
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
  bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{ return lhs.first==rhs.first && lhs.second==rhs.second; }

template <class T1, class T2>
  bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{ return !(lhs==rhs); }

template <class T1, class T2>
  bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{ return lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second); }

template <class T1, class T2>
  bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{ return !(rhs<lhs); }

template <class T1, class T2>
  bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{ return rhs<lhs; }

template <class T1, class T2>
  bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{ return !(lhs<rhs); }

}
#endif