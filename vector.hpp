/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otmallah <otmallah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 20:18:18 by otmallah          #+#    #+#             */
/*   Updated: 2022/10/21 14:50:49 by otmallah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
// #include <stdexcept>

namespace ft
{
	template<class T, class Alloc = std::allocator<T> > 
	class vector
	{
		public:
			typedef T                               value_type;
			typedef Alloc                           allocater_type;
			typedef size_t							size_type;
			typedef ptrdiff_t						diffrence_type;
			typedef class allocater_type::refrence        refrence;
			typedef class allocater_type::const_refrence const_refrence;
			typedef class allocater_type::pointer         pointer;
			typedef class allocater_type::const_pointer   const_pointer;
			typedef class allocater_type::random_access_iterator_tag iterator;
			typedef class allocater_type::random_access_iterator_tag reverse_iterator;
			
		private :
			T		*temp_vec;
			size_type	_size;
			size_type	_capacity;
		public:
			vector() : _size(0), _capacity(0)
			{
				// explicit vector (const allocator_type& alloc = allocator_type());
				// explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type());
				// template <class InputIterator> 
				// vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());
				// vector (const vector& x);
			}
			~vector(){}
			vector& operator=(const vector& x);
			// -------------- Capacity -------------
			size_type   size()  const
			{
				
			}
			size_type  max_size()  const;
			void    resize(size_type n, value_type val = value_type());
			size_type	  capacity()  const;
			bool    empty() const;
			void    reserve(size_type  n);
			void    shrink_to_fit();
			// ----------------- Element access --------
			refrence        operator[] (size_type n);
			const_refrence  operator[](size_type n) const;
			refrence        at(size_type n);
			const_refrence  at(size_type n) const;
			refrence        front();
			const_refrence  front() const;
			refrence        back();
			const_refrence  back() const;
			// value_type*     data() noexcept;
			// const value_type* data() const noexcept;
			// ------------ Modifiers -----------------
			// template <class InputIterator>
			// void    assign(InputIterator first, InputIterator last);
			void    assign (size_type n, const value_type& val);
			void    push_back(const value_type& val);    
			void    pop_back();
			// iterator	erase (iterator position);
			// iterator	erase (iterator first, iterator last);
			void		swap(vector& x);
			void		clear();
			allocater_type	get_allocator() const;
	};
}


#endif