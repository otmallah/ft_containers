/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocator.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otmallah <otmallah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 20:36:44 by otmallah          #+#    #+#             */
/*   Updated: 2022/12/26 13:36:33 by otmallah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _ALLOCATOR_HPP_
#define _ALLOCATOR_HPP_


#include <iostream>

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
        allocator() throw()
        { puts("dklnsc") ;}
        allocator( const_reference val, pointer _p )
        { puts("hana"); }
        allocator(const allocator& alloc) throw();
        template <typename _Al>
        allocator(const allocator& alloc) throw();
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
            return (value_type*) ::operator new(sizeof(value_type) * n);
        }
        void construct ( pointer p, const_reference val )
        {
            new (p) value_type(val, p);
        }
};


#endif