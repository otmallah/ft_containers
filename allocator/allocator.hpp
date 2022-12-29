/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocator.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otmallah <otmallah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 20:36:44 by otmallah          #+#    #+#             */
/*   Updated: 2022/12/28 14:31:14 by otmallah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _ALLOCATOR_HPP_
#define _ALLOCATOR_HPP_

#include <iostream>


namespace ft
{
    template <class T> class allocator
    {
        public :
            typedef T   value_type;
            typedef T*   pointer;
            typedef T&   reference;
            typedef const T*   const_pointer;
            typedef const T&   const_reference;
            typedef size_t      size_type;
            typedef ptrdiff_t   difference_type;
            template <class Type> struct rebind { typedef allocator<Type> other;};
        
        public :
            allocator() throw() {}
            allocator(const allocator&) throw() {} 
            template <typename _Al>
            allocator(const allocator&) throw() {}
            pointer address ( reference __x ) const
            {
                return std::addressof(__x);
            }
            const_pointer address ( const_reference __x ) const 
            {
                return std::addressof(__x);
            }
            pointer allocate (size_type n)
            {
                if ( n > max_size())
                    throw std::length_error("allocator<T>::allocate(size_t n)"
                                            " 'n' exceeds maximum supported size");
                return (value_type*) ::operator new(sizeof(value_type) * n);
            }
            void construct ( pointer p, const_reference val )
            {
                new (p) value_type(val);
            }
            size_type max_size() const throw()
            {
                return ( size_type(~0) / sizeof(value_type));
            }
            void destroy (pointer p)
            {
                p->~value_type();
            }
            void deallocate (pointer p, size_type n)
            {
                (void)n;
                delete p;
            }
    };
}
#endif