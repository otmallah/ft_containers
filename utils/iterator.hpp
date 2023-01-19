/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otmallah <otmallah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 16:50:33 by otmallah          #+#    #+#             */
/*   Updated: 2023/01/17 18:18:06 by otmallah         ###   ########.fr       */
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
			typedef std::random_access_iterator_tag iterator_category;
		
		private :
			pointer _ptr;
		public :
			operator iterator<const T>() const {return iterator<const T>(_ptr); }
			iterator() : _ptr()
			{}
			iterator(pointer ptr) : _ptr(ptr) {}
			iterator(const iterator& obj) : _ptr(obj._ptr)
			{}
			pointer   base() const
            {
                return _ptr;
			}
			iterator& operator=(const iterator& new_obj)
			{
				this->_ptr = new_obj._ptr ; 
				return *this;
			}
			~iterator(){}

			reference	operator * () const
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
				iterator iter(*this);
				--(*this);
				return iter;
			}
			iterator&	operator --()
			{
				--_ptr;
				return *this;
			}
			iterator	operator- (difference_type n) const
			{
				iterator temp = *this;
				temp._ptr = _ptr - n;
				return temp;
			}
			difference_type	operator- (const iterator& _it) const
			{
				return (*this).base() - _it.base() ;
			}
			iterator	operator+ (difference_type n) const
			{
				iterator temp = *this;
				temp._ptr = _ptr + n;
				return temp;
			}
			reference operator[] (difference_type n) const
            {
                return _ptr[n];
            }
			pointer operator->() const
            {
                return &(operator*());
            }
			template <class _Iter1, class _Iter2>
			friend bool
			operator!=(const ft::iterator<_Iter1>& __x, const ft::iterator<_Iter2>& __y) 
			{
				return __x._ptr != __y._ptr;
			}
			template <class _Iter1, class _Iter2>
			friend bool
			operator>=(const ft::iterator<_Iter1>& __x, const ft::iterator<_Iter2>& __y) 
			{
				return __x._ptr >= __y._ptr;
			}
			template <class _Iter1, class _Iter2>
			friend bool
			operator>(const ft::iterator<_Iter1>& __x, const ft::iterator<_Iter2>& __y) 
			{
				return __x._ptr > __y._ptr;
			}
			template <class _Iter1, class _Iter2>
			friend bool
			operator<(const ft::iterator<_Iter1>& __x, const ft::iterator<_Iter2>& __y) 
			{
				return __x._ptr < __y._ptr;
			}
			template <class _Iter1, class _Iter2>
			friend bool
			operator ==(const ft::iterator<_Iter1>& __x, const ft::iterator<_Iter2>& __y) 
			{
				return __x._ptr == __y._ptr;
			}
			template <class _Iter1, class _Iter2>
			friend bool
			operator <=(const ft::iterator<_Iter1>& __x, const ft::iterator<_Iter2>& __y) 
			{
				return __x._ptr <= __y._ptr;
			}
	};


template<class _Iter>
iterator<_Iter> operator + (typename ft::iterator<_Iter>::difference_type  __n, ft::iterator<_Iter> _x )
{
	return _x + __n;
}


}

#endif