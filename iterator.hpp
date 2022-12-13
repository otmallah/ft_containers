/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otmallah <otmallah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 16:50:33 by otmallah          #+#    #+#             */
/*   Updated: 2022/12/12 16:40:07 by otmallah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <iostream>

namespace   ft
{
	template<class T> class iterator
	{
		public :
			typedef T           value_type;
			typedef T*          pointer;
			typedef T&          reference;
			typedef size_t      size_type;
			typedef ptrdiff_t   difference_type;
		
		private :
			pointer _ptr;
		public :
			iterator() : _ptr()
			{}
			iterator(pointer ptr) {_ptr = ptr;}
			iterator(const iterator& obj)
			{
				this->_ptr = obj._ptr;
			}
			iterator& operator=(const iterator& new_obj)
			{
				this->_ptr = new_obj._ptr ; 
				return *this;
			}
			~iterator(){}
			bool operator == ( const iterator& x)
			{
				return ( this->_ptr == x._ptr );
			}
			bool operator < ( const iterator& x)
			{
				return ( this->_ptr < x._ptr );
			}
			bool operator != ( const iterator& x)
			{
				return ( this->_ptr != x._ptr );
			}
			bool operator > ( const iterator& x)
			{
				return ( this->_ptr > x._ptr );
			}
			bool operator >= ( const iterator& x)
			{
				return ( this->_ptr >= x._ptr );
			}
			bool operator <= ( const iterator& x)
			{
				return ( this->_ptr <= x._ptr );
			}
			reference	operator * ()
			{
				return *_ptr;
			}
			iterator	operator ++()
			{
				iterator iter;
				iter._ptr = ++_ptr;
				return iter;
			}
			iterator	operator ++(int)
			{
				iterator iter;
				iter._ptr = _ptr++;
				return iter;
			}
			iterator	operator +=(difference_type n)
			{
				iterator iter;
				this->_ptr += n;
				iter._ptr = this->_ptr;
				return (iter);
			}
			iterator	operator -=(difference_type n)
			{
				iterator iter;
				this->_ptr -= n;
				iter._ptr = this->_ptr;
				return (iter);
			}
			iterator	operator --(int)
			{
				iterator iter;
				_ptr--;
				iter._ptr = _ptr;
				return iter;
			}
			iterator	operator --()
			{
				iterator iter;
				iter._ptr = --_ptr;
				return iter;
			}
	};
}



#endif