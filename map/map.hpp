/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otmallah <otmallah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 14:10:01 by otmallah          #+#    #+#             */
/*   Updated: 2023/01/10 19:12:35 by otmallah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _MAP_HPP_
#define _MAP_HPP_

#include "../utils/utils.hpp"

namespace ft
{
    template <class key, class T, class compare = std::less<key>, class Allocator = allocator<pair<const key, T> > >
    class map
    {
        public :
        
            typedef key                         key_type;
            typedef T                           mapped_type;
            typedef std::pair< key, T>     value_type;
            typedef compare                     key_compare;
            typedef Allocator                   allocator_type;
            typedef size_t                      size_type;
            typedef ptrdiff_t                   difference_type;
            typedef ft::__map_iterator<Node<value_type>, value_type>    iterator; 
            typedef typename    Allocator::reference reference;
            typedef typename    Allocator::const_reference const_reference;
            typedef typename    Allocator::pointer          pointer;
            typedef typename    Allocator::const_pointer    const_pointer;
        
        public :
            
            // constructer
            explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _size(0)
            {
                _alloc = alloc;
            }
            template <class InputIterator> 
            map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
            {
                _alloc = alloc;
                while (first != last)
                {
                    root.insert(*first);
                    first++;
                }
            }
            map (const map& x)
            {
                *this = x;
            }
            ~map() {}
            map& operator= (const map& x)
            {
                root.~AVL_TREE();
                root.insert(x.begin(), x.end());
                _size = x._size;
                _alloc = x._alloc;
                return *this;
            }
            iterator begin() const
            {
                return iterator(root.get());
            }
            iterator end() const
            {
                return iterator(NULL);
            }
            bool empty() const
            {
                if (_size == 0) return true ; return false;
            }
            size_type size() const
            {
                return root.size();    
            }
            std::pair<iterator,bool> insert (const value_type& val)
            {
                return root.insert(val);
            }
            iterator insert (iterator position, const value_type& val)
            {
                (void)position;
                std::pair<iterator, bool> temp = insert(val);
                return temp.first;
            }
            template <class InputIterator>
            void insert (InputIterator first, InputIterator last)
            {
                while (first != last)
                {
                    root.insert(*first);
                    first++;
                }
            }
            // iterator find (const key_type& k)
            // {
            //     return root.find
            // }
        private :
            AVL_TREE<value_type>  root;
            size_type              _size;
            Allocator               _alloc;
                
    };
}



#endif
