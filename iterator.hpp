/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otmallah <otmallah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 16:50:33 by otmallah          #+#    #+#             */
/*   Updated: 2022/10/21 18:00:17 by otmallah         ###   ########.fr       */
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
			typedef T&          refrence;
			typedef size_t      size_type;
			typedef ptrdiff_t   diffrence_type;
		
		private :
			pointer _ptr;
	
		public :
			iterator() : _ptr()
			{}
			iterator(const iterator& obj)
			{
				this->_ptr = obj._ptr;
			}
			iterator& operator=(const iterator& new_obj)
			{
				this->_ptr = new_obj._ptr;
				return *this;
			}
			~iterator(){}
			template <class Iterator>
			bool operator == ( const iterator<Iterator>& x)
			{
				if ( this->_ptr == x._ptr )
					return true;
				return false;
			}
			template <class Iterator>
			bool operator < ( const iterator<Iterator>& x)
			{
				if ( this->_ptr < x._ptr )
					return true;
				return false;
			}
			template <class Iterator>
			bool operator != ( const iterator<Iterator>& x)
			{
				if ( this->_ptr != x._ptr )
					return true;
				return false;
			}
			template <class Iterator>
			bool operator > ( const iterator<Iterator>& x)
			{
				if ( this->_ptr > x._ptr )
					return true;
				return false;
			}
			// template <class Iterator>
			// bool operator >= ( const iterator<Iterator>& x)
			// {
			// 	if ( this->_ptr >= x._ptr )
			// 		return true;
			// 	return false;
			// }
			// template <class Iterator>
			// bool operator <= ( const iterator<Iterator>& x)
			// {
			// 	if ( this->_ptr == x._ptr )
			// 		return true;
			// 	return false;
			// }
			// template <class Iterator>
			// bool operator == ( const iterator<Iterator>& x)
			// {
			// 	if ( this->_ptr == x._ptr )
			// 		return true;
			// 	return false;
			// }
			// template <class Iterator>
			// typename iterator<Iterator>::difference_type operator-(
			// const iterator<Iterator>& x)
			// {
			// 	return(this->_ptr - x._ptr);
			// }
			// template <class Iterator>
			// iterator<Iterator> operator+(
			// typename iterator<Iterator>::difference_type n, const iterator<Iterator>& x)
			// {
			// 	// return (n + x)
			// }
	};
}



#endif