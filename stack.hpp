/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otmallah <otmallah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 17:18:03 by otmallah          #+#    #+#             */
/*   Updated: 2022/12/16 16:24:12 by otmallah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _STACK_HPP_
#define _STACK_HPP_

#include <iostream>
#include "vector.hpp"

namespace ft 
{
	template <class T, class Container = ft::vector<T> > class stack
	{
		public :
			typedef Container							container_type;
			typedef typename container_type::value_type	value_type;
			typedef typename container_type::size_type	size_type;
		
		protected :
			Container c;
		public :
			explicit stack (const container_type& ctnr = container_type())
			{
				
			}
			bool empty() const { return c.empty(); }
			size_type size() const { return c.size(); }
			value_type& top() { return c.back(); }
			const value_type& top() const { return c.back(); }
			void push(const value_type& x) { c.push_back(x); }
			void pop() { c.pop_back(); }
			container_type getC() const { return c; }
	};
	template <class U, class _Container>
 	bool 
	operator==(const ft::stack<U, _Container>& __x, const ft::stack<U, _Container>& __y)
	{
		return __x.getC() == __y.getC();
	}
	template <class T, class Container>
	bool 
	operator< (const stack<T, Container>& __x, const stack<T, Container>& __y)
	{
		return __x.getC() < __y.getC(); 
	}
	template <class T, class Container>
	bool
	operator!=(const stack<T, Container>& __x, const stack<T, Container>& __y)
	{
		return !(__x.getC() == __y.getC());
	}
	
	template <class T, class Container>
	bool
	operator>(const stack<T, Container>& __x, const stack<T, Container>& __y)
	{
		return (__x.getC() > __y.getC());
	}

	template <class T, class Container>
	bool
	operator>=(const stack<T, Container>& __x, const stack<T, Container>& __y)
	{
		return (__x.getC() >= __y.getC());
	}

	template <class T, class Container>
	bool
	operator<=(const stack<T, Container>& __x, const stack<T, Container>& __y)
	{
		return (__x.getC() <= __y.getC());
	}
}




#endif