/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otmallah <otmallah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 17:18:03 by otmallah          #+#    #+#             */
/*   Updated: 2022/12/19 17:57:08 by otmallah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _STACK_HPP_
#define _STACK_HPP_

#include <iostream>
#include "../vector/vector.hpp"

namespace ft 
{
	template <class T, class Container = ft::vector<T> > class stack
	{
		public :
			typedef Container							container_type;
			typedef typename container_type::value_type	value_type;
			typedef typename container_type::size_type	size_type;
		
		public :
			~stack() {}
			explicit stack (const container_type& ctnr = container_type()) : c(ctnr) {}
			bool empty() const { return c.empty(); }
			size_type size() const { return c.size(); }
			value_type& top() { return c.back(); }
			const value_type& top() const { return c.back(); }
			void push(const value_type& x) { c.push_back(x); }
			void pop() { c.pop_back(); }
		protected :
			Container c;
		template <class U, class _Container>
		friend bool 
		operator==(const ft::stack<U, _Container>& __x, const ft::stack<U, _Container>& __y)
		{
			return __x.c == __y.c;
		}
		template <class U, class _Container>
		friend bool 
		operator< (const stack<T, _Container>& __x, const stack<U, _Container>& __y)
		{
			return __x.c < __y.c; 
		}
		template <class U, class _Container>
		friend bool
		operator!=(const stack<U, _Container>& __x, const stack<U, _Container>& __y)
		{
			return !(__x.c == __y.c);
		}
		template <class U, class _Container>
		friend bool
		operator>(const stack<U, _Container>& __x, const stack<U, _Container>& __y)
		{
			return (__x.c > __y.c);
		}
		template <class U, class _Container>
		friend bool
		operator>=(const stack<U, _Container>& __x, const stack<U, _Container>& __y)
		{
			return (__x.c >= __y.c);
		}
		template <class U, class _Container>
		friend bool
		operator<=(const stack<U, _Container>& __x, const stack<U, _Container>& __y)
		{
			return (__x.c <= __y.c);
		}
	};
}




#endif