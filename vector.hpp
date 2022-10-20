/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otmallah <otmallah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 20:18:18 by otmallah          #+#    #+#             */
/*   Updated: 2022/10/20 21:21:41 by otmallah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <utility>




namespace ft
{
	template<class T, class Alloc = std::allocator<T> > 
	class vector
	{
		public:
			typedef T                               value_type;
			typedef Alloc                           allocater_type;
			typedef class allocater_type::refrence        refrence;
			typedef class allocater_type::const_refrence const_refrence;
			typedef class allocater_type::pointer         pointer;
			typedef class allocater_type::const_pointer   const_pointer;
			typedef class allocater_type::random_access_iterator_tag iterator;
		private :
			T		*temp_vec;
			size_t	_size;
			size_t	_capacity;
		public:
			vector()
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
			size_t   size()  const;
			size_t  max_size()  const;
			void    resize(size_t n, value_type val = value_type());
			size_t  capacity()  const;
			bool    empty() const;
			void    reserve(size_t  n);
			void    shrink_to_fit();
			// ----------------- Element access --------
			refrence        operator[] (size_t n);
			const_refrence  operator[](size_t n) const;
			refrence        at(size_t n);
			const_refrence  at(size_t n) const;
			refrence        front();
			const_refrence  front() const;
			refrence        back();
			const_refrence  back() const;
			// value_type*     data() noexcept;
			// const value_type* data() const noexcept;
			// ------------ Modifiers -----------------
			// template <class InputIterator>
			// void    assign(InputIterator first, InputIterator last);
			void    assign (size_t n, const value_type& val);
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