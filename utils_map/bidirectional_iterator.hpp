/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bidirectional_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otmallah <otmallah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 16:17:56 by otmallah          #+#    #+#             */
/*   Updated: 2023/01/15 23:07:36 by otmallah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _BIDIRECTIONAL_ITERATOR_HPP_
#define _BIDIRECTIONAL_ITERATOR_HPP_

#include <iostream>

#include "../vector/vector.hpp"

namespace ft
{

    template <class _TreeIterator, class T, class _key>
    class __map_iterator
    {
        
        public :
            typedef T       value_type;
			typedef T*      pointer;
			typedef T&      reference;
			typedef size_t              size_type;
			typedef ptrdiff_t           difference_type;
            typedef std::bidirectional_iterator_tag iterator_category;  
        
        private :
            _TreeIterator * __iter;

        
        public :
            operator __map_iterator< const _TreeIterator, const T, _key>() const 
            {
                return __map_iterator< const _TreeIterator, const T, _key>(__iter);
            }
            __map_iterator() : current(0) {};
            __map_iterator(_TreeIterator *_i) : __iter(_i)
            {
                this->current = 0;
                add(__iter);
                vec.push_back(NULL);
            }
            __map_iterator(_TreeIterator *_i, _TreeIterator * _temp) : __iter(_i)
            {
                this->current = 0;
                add(__iter);
                if (!_temp)
                    current = vec.size();
                vec.push_back(NULL);
            }
            __map_iterator(_TreeIterator *_i, const _key& key, int a) : __iter(_i)
            {
                this->current = 0;
                a = 0;
                add(__iter);
                vec.push_back(NULL);
                find(key);
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
            pointer operator->() const
            {
                return &vec[current]->key;
            }
            __map_iterator&  operator--(){
                --current;
                return *this;
            }
            __map_iterator  operator--(int){
                __map_iterator temp;
                temp.current = current--;
                return temp;
            }
            
            bool operator==(const __map_iterator& rhs)
            {
                return this->vec[current] == rhs.vec[rhs.current] ;
            }
            bool operator!=(const __map_iterator& rhs)
            {
                return !(*this == rhs);
            }
        
        private :
            std::vector<_TreeIterator *> vec;
            size_t  current ;
            void    add(_TreeIterator *root)
            {
                if (!root)
                    return;
                add(root->left_child);
                vec.push_back(root);
                add(root->right_child);
            }
            void    find(const _key& key)
            {
                while(current < vec.size())
                {
                    if (vec[current]->key.first == key)
                        break;
                    current++;
                }
            }
            
    };

}

#endif