/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bidirectional_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otmallah <otmallah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 16:17:56 by otmallah          #+#    #+#             */
/*   Updated: 2023/01/08 17:32:14 by otmallah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _BIDIRECTIONAL_ITERATOR_HPP_
#define _BIDIRECTIONAL_ITERATOR_HPP_

namespace ft
{

    template <typename _TreeIterator>
    class __map_iterator
    {
        _TreeIterator _i;

        public :
            __map_iterator() {};
            __map_iterator(_TreeIterator __i) : _i(__i) {}
            _TreeIterator& operator=(const _TreeIterator& new_obj)
            {
                if (this == &new_obj)
                    return *this;
                this->_i = new_obj._i;
                return *this;
            }
            ~__map_iterator();
            __map_iterator  operator++(){}
            __map_iterator  operator++(int){}
            __map_iterator  operator--(){}
            __map_iterator  operator--(int){}
            
            
    }

}

#endif