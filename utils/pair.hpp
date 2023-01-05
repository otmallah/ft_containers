/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otmallah <otmallah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 18:00:15 by otmallah          #+#    #+#             */
/*   Updated: 2023/01/05 12:02:33 by otmallah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _PAIR_HPP_
#define _PAIR_HPP_

#include <iostream>

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
template <class T1, class T2> struct pair<const T1, T2>
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
			// this->first = pr.first;
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

#endif