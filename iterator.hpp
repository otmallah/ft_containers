/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otmallah <otmallah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 16:50:33 by otmallah          #+#    #+#             */
/*   Updated: 2022/10/20 22:15:45 by otmallah         ###   ########.fr       */
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
            typedef T   value_type;
            typedef T&  refrence;
            typedef T*  pointer;
        
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
            ~iterator()
            {}
            bool operator == (const iterator&)
            {
                if ()
            }
            bool operator != (const iterator&);
            bool operator < (const iterator&);
            bool operator > (const iterator&);
            bool operator <= (const iterator&);
            bool operator >= (const iterator&);
            iterator operator ++ ();
            iterator operator ++ (int);
            iterator operator -- ();
            iterator operator -- (int);
            
    };
}



#endif