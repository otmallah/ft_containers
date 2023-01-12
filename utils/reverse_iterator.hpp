/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otmallah <otmallah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 18:07:19 by otmallah          #+#    #+#             */
/*   Updated: 2023/01/12 21:59:16 by otmallah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include <iostream>
#include "utils.hpp"
#include "iterator.hpp"

class iterator;

namespace   ft{
    template<class Iterator>
    class reverse_iterator
    {
        public :
            typedef  Iterator                                  iterator_type;
            typedef typename iterator_traits<Iterator>::iterator_category iterator_category;
            typedef typename iterator_traits<Iterator>::value_type        value_type;
            typedef typename iterator_traits<Iterator>::difference_type   difference_type;
            typedef typename iterator_traits<Iterator>::pointer          pointer;
            typedef typename iterator_traits<Iterator>::reference          reference;

        protected:
            Iterator __ptr;
        
        public :
            operator reverse_iterator<Iterator>() const {return reverse_iterator<Iterator>(__ptr); }
            reverse_iterator() : __ptr() {}
            reverse_iterator(pointer ptr) {this->__ptr = ptr;}
            explicit reverse_iterator(iterator_type it) { __ptr = it ;}
            template <class Iter>
            reverse_iterator (const reverse_iterator<Iter>& rev_it) {
                __ptr = rev_it.base() ; }
            iterator_type   base() const
            {
                return __ptr;
            }
            reference operator*() const
            {
                Iterator temp = __ptr;
                return *--temp;
            }
            reverse_iterator operator+ (difference_type n) const
            {
                return reverse_iterator(__ptr - n);
            }
            reverse_iterator operator++(int)
            {
                reverse_iterator temp = *this;
                --__ptr;
                return temp;
            }
            reverse_iterator& operator++()
            {
                --__ptr;
                return (*this);
            }
            reverse_iterator& operator+= (difference_type n)
            {
                __ptr -= n;
                return *this;
            }
            reverse_iterator operator- ( difference_type n)  
            {
                return reverse_iterator(__ptr + n);
            }
            reverse_iterator& operator--()
            {
                ++__ptr;
                return (*this);
            }
            reverse_iterator operator--(int) {
                reverse_iterator temp = *this;
                ++__ptr;
                return temp;
            }
            reverse_iterator& operator-= (difference_type n)
            {
                this->__ptr += n;
                return *this;
            }
            difference_type operator - (const reverse_iterator& __x) 
            {
                return (__x.base() - (*this).base());
            }
            pointer operator->() const
            {
                return &(operator*());
            }
            reference operator[] (difference_type n) const
            {
                return __ptr[-n-1];
            }
    };
}

template<class _Iter>
ft::reverse_iterator<_Iter> operator + (typename ft::reverse_iterator<_Iter>::difference_type  __n, ft::reverse_iterator<_Iter> _x )
{
	return ft::reverse_iterator<_Iter>(_x.base() - __n);
}

template <class Iterator, class Iterator1>
  bool operator== (const ft::reverse_iterator<Iterator>& lhs,
                   const ft::reverse_iterator<Iterator1>& rhs)
    {
        return (lhs.base() == rhs.base());
    }

template <class Iterator, class Iterator1>
  bool operator!= (const ft::reverse_iterator<Iterator>& lhs,
                   const ft::reverse_iterator<Iterator1>& rhs)
    {
        return (lhs.base() != rhs.base());
    }

template <class Iterator, class Iterator1>
  bool operator<  (const ft::reverse_iterator<Iterator>& lhs,
                   const ft::reverse_iterator<Iterator1>& rhs)
    {
        return (lhs.base() > rhs.base());
    }

template <class Iterator, class Iterator1>
  bool operator<= (const ft::reverse_iterator<Iterator>& lhs,
                   const ft::reverse_iterator<Iterator1>& rhs)
    {
        return (lhs.base() >= rhs.base());
    }

template <class Iterator, class Iterator1>
  bool operator>  (const ft::reverse_iterator<Iterator>& lhs,
                   const ft::reverse_iterator<Iterator1>& rhs)
    {
        return (lhs.base() < rhs.base());
    }


template <class Iterator, class Iterator1>
  bool operator>= (const ft::reverse_iterator<Iterator>& lhs,
                   const ft::reverse_iterator<Iterator1>& rhs)
    {
        return (lhs.base() <= rhs.base());
    }
  

#endif