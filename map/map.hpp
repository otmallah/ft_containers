/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otmallah <otmallah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 14:10:01 by otmallah          #+#    #+#             */
/*   Updated: 2023/01/07 21:34:57 by otmallah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _MAP_HPP_
#define _MAP_HPP_


namespace ft
{
    template <class key, class T, class compare = less<ket>, class Allocator = allocator<pair<const key, T> > >
    class map
    {
        typedef key                         key_type;
        typedef T                           mapped_type;
        typedef std::pair<const key, T>     value_type;
        typedef compare                     key_compare;
        typedef Allocator                   allocator_type;
        typedef typename    Allocator::reference reference;
        typedef typename    Allocator::const_reference const_reference;
        typedef typename    Allocator::pointer          pointer;
        typedef typename    Allocator::const_pointer    const_pointer;
      
    }
}



#endif