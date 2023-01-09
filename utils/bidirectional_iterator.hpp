/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bidirectional_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otmallah <otmallah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 16:17:56 by otmallah          #+#    #+#             */
/*   Updated: 2023/01/09 16:37:13 by otmallah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _BIDIRECTIONAL_ITERATOR_HPP_
#define _BIDIRECTIONAL_ITERATOR_HPP_

#include <iostream>
#include "../vector/vector.hpp"

namespace ft
{

    template <typename _TreeIterator, typename T>
    class __map_iterator
    {
        
        public :
            typedef T       value_type;
			typedef T*      pointer;
			typedef T&      reference;
			typedef size_t              size_type;
			typedef ptrdiff_t           difference_type;
            typedef std::bidirectional_iterator_tag iterator_category;  

        public :
            __map_iterator() : current(0) {};
            __map_iterator(_TreeIterator *_i) 
            {
                add(_i);
                vec.push_back(NULL);
            }
            _TreeIterator& operator=(const _TreeIterator& new_obj)
            {
                if (this == &new_obj)
                    return *this;
                this->_i = new_obj._i;
                return *this;
            }
            ~__map_iterator() {};
            reference operator*() const
            {
                return vec[current]->key;
            }
            __map_iterator&  operator++(){
                ++current;
                return *this;
            }
            __map_iterator  operator++(int){
                __map_iterator temp = *this;
                current++;
                return temp;
            }
            pointer operator->() { return &vec[current]->key; }
            __map_iterator&  operator--(){
                --current;
                return *this;
            }
            __map_iterator  operator--(int){
                __map_iterator temp = *this;
                current--;
                return temp;
            }
            
            bool operator==(const __map_iterator& rhs)
            {
                return this->vec[current] == rhs->vec[current];
            }
            bool operator!=(const __map_iterator& rhs)
            {
                return !(*this == rhs);
            }
        
        private :
            ft::vector<_TreeIterator *> vec;
            size_t  current ;
            void    add(_TreeIterator *root)
            {
                if (!root)
                    return ;
                add(root->left_child);
                vec.push_back(root);
                add(root->right_child);
            }
    };

}

#endif