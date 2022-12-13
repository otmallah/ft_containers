/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otmallah <otmallah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 18:07:19 by otmallah          #+#    #+#             */
/*   Updated: 2022/12/13 18:49:16 by otmallah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include <iostream>
#include "utils.hpp"
#include "iterator.hpp"

class iterator;

namespace   ft{
    template<class T>
    class reverse_iterator
    {
        public :
            typedef typename ft::iterator<T>                                  iterator_type;
            // typedef typename iterator_traits<iterator<T> >::iterator_category iterator_category;
            typedef typename iterator_traits<iterator<T> >::value_type        value_type;
            typedef typename iterator_traits<iterator<T> >::difference_type   difference_type;
            typedef typename iterator_traits<iterator<T> >::pointer          pointer;
            typedef typename iterator_traits<iterator<T> >::reference          reference;

        private:
            pointer _ptr;
        
        public :
            reverse_iterator() : _ptr() {}
            reverse_iterator(pointer ptr) {this->_ptr = ptr;}
            //explicit reverse_iterator(iterator_type it) { _ptr = it;}
            // template <class Iter>
            // reverse_iterator (const reverse_iterator<Iter>& rev_it) { this->_ptr = rev_it; }
            iterator_type   base() const
            {
                iterator_type it = _ptr;
                it--;
                return it;
            }
            reference operator*() const
            {
                return *_ptr;
            }
            reverse_iterator operator+ (difference_type n) const
            {
                reverse_iterator it;
                it._ptr = _ptr - n;
                return it;
            }
            reverse_iterator operator++(int)
            {
                reverse_iterator temp = *this;
                ++_ptr;
                return temp;
            }
            reverse_iterator& operator++()
            {
                _ptr--;
                return (*this);
            }
            reverse_iterator operator+= (difference_type n)
            {
                reverse_iterator it = *this;
                _ptr = (_ptr - n);
                return it;
            }
            reverse_iterator operator- (difference_type n) const
            {
                reverse_iterator temp = *this;
                temp._ptr = _ptr + n;
                return temp;
            }
            reverse_iterator& operator--()
            {
                _ptr++;
                return (*this);
            }
            reverse_iterator operator--(int) {
                reverse_iterator temp = *this;
                ++_ptr;
                return temp;
            }
            reverse_iterator& operator-= (difference_type n)
            {
                this->_ptr += n;
                return *this;
            }
            pointer operator->() const
            {
                return &(operator*());
            }
            reference operator[] (difference_type n) const
            {
                return _ptr[n];
            }
    };
}

template <class Iterator>
  bool operator== (const ft::reverse_iterator<Iterator>& lhs,
                   const ft::reverse_iterator<Iterator>& rhs)
    {
        return (lhs.base() == rhs.base());
    }

template <class Iterator>
  bool operator!= (const ft::reverse_iterator<Iterator>& lhs,
                   const ft::reverse_iterator<Iterator>& rhs)
    {
        return (lhs.base() != rhs.base());
    }

template <class Iterator>
  bool operator<  (const ft::reverse_iterator<Iterator>& lhs,
                   const ft::reverse_iterator<Iterator>& rhs)
    {
        return (lhs.base() < rhs.base());
    }

template <class Iterator>
  bool operator<= (const ft::reverse_iterator<Iterator>& lhs,
                   const ft::reverse_iterator<Iterator>& rhs)
    {
        return (lhs.base() <= rhs.base());
    }

template <class Iterator>
  bool operator>  (const ft::reverse_iterator<Iterator>& lhs,
                   const ft::reverse_iterator<Iterator>& rhs)
    {
        return (lhs.base() > rhs.base());
    }


template <class Iterator>
  bool operator>= (const ft::reverse_iterator<Iterator>& lhs,
                   const ft::reverse_iterator<Iterator>& rhs)
    {
        return (lhs.base() >= rhs.base());
    }
  

#endif