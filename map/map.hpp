/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otmallah <otmallah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 14:10:01 by otmallah          #+#    #+#             */
/*   Updated: 2023/01/13 20:17:24 by otmallah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _MAP_HPP_
#define _MAP_HPP_

#include "../utils_map/bidirectional_iterator.hpp"
#include "../utils/reverse_iterator.hpp"
#include "../tests/AVL.hpp"

namespace ft
{
    template <class key, class T, class compare = std::less<key>, class Allocator = std::allocator<std::pair<const key, T> > >
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
            typedef ft::__map_iterator<Node<value_type>, value_type, key_type>    iterator;
            typedef ft::__map_iterator<const Node<value_type>, const value_type, key_type>    const_iterator; 
            typedef ft::reverse_iterator<iterator>    reverse_iterator;
            typedef ft::reverse_iterator<const_iterator>    const_reverse_iterator;
            typedef typename    Allocator::reference reference;
            typedef typename    Allocator::const_reference const_reference;
            typedef typename    Allocator::pointer          pointer;
            typedef typename    Allocator::const_pointer    const_pointer;
        
        public :
        
            key_compare _key_comp;
        
            class value_compare
            : public std::binary_function<value_type,value_type,bool> {
            friend class map;
                protected:
                    compare comp;
                    value_compare(compare c) : comp(c) {}
                public:
                    bool operator()(const value_type& x, const value_type& y) const {
                    return comp(x.first, y.first);
                }
            };

            // constructer
            explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _size(0)
            {
                (void)comp;
                _alloc = alloc;
            }
            template <class InputIterator> 
            map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
            {
                (void)comp;
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
            key_compare key_comp() const
            {
                return _key_comp;
            }
            value_compare value_comp() const
            {
                return value_compare(key_comp());
            }
            map& operator= (const map& x)
            {
                root.~AVL_TREE();
                for (const_iterator it = x.begin(); it != x.end(); it++)
                    this->insert(*it);
                _size = x._size;
                _alloc = x._alloc;
                return *this;
            }
            iterator begin() 
            {
                return iterator(root.get());
            }
            const_iterator begin() const
            {
                return const_iterator(root.get());
            }
            reverse_iterator rbegin()
            {
                return reverse_iterator(end());
            }
            const_reverse_iterator rbegin() const
            {
                return const_reverse_iterator(end());
            }
            reverse_iterator rend()
            {
                return reverse_iterator(begin());
            }
            const_reverse_iterator rend() const
            {
                return reverse_iterator(root.get());
            }
            iterator end()
            {
                return iterator(root.get(), NULL);
            }
            const_iterator end() const
            {
                return const_iterator(root.get(), NULL);
            }
            bool empty() const
            {
                if (_size == 0) return true ; return false;
            }
            size_type size() const
            {
                return root.size();    
            }
            mapped_type& operator[] (const key_type& k)
            {
                return (*((this->insert(std::make_pair(k,mapped_type()))).first)).second;

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
            void insert (InputIterator first, typename std::enable_if<std::__is_input_iterator<InputIterator>::value 
			&& !std::is_integral<InputIterator>::value, InputIterator>::type last)
            {
                while (first != last)
                {
                    root.insert(*first);
                    first++;
                }
            }
            iterator find (const key_type& k)
            {
                return root.find(k);
            }
            const_iterator find (const key_type& k) const
            {
                return root.find(k);
            }
            void erase (iterator position)
            {
                root.erase(position);
            }
            void erase (iterator first, iterator last)
            {
                while (first != last)
                {
                    root.erase(first);
                    first++;
                }                
            }
            size_type erase (const key_type& k)
            {
                return root.erase(k);
            }
            void swap (map& x)
            {
                std::swap(*this, x);
            }
            void clear()
            {
                root.clear(root.get());
            }
            size_type count (const key_type& k) const
            {
                return root.count(k);
            }
            iterator lower_bound (const key_type& k)
            {
                return root.lower_bound(k);
            }
            const_iterator lower_bound (const key_type& k) const
            {
                return root.lower_bound(k);
            }
            iterator upper_bound (const key_type& k)
            {
                return root.upper_bound(k);
            }
            const_iterator upper_bound (const key_type& k) const
            {
                return root.upper_bound(k);
            }
            std::pair<const_iterator,const_iterator> equal_range (const key_type& k) const
            {
                return std::make_pair(lower_bound(k), upper_bound(k));
            }
            std::pair<iterator,iterator> equal_range (const key_type& k)
            {
                return std::make_pair(lower_bound(k), upper_bound(k));
            }
            allocator_type get_allocator() const
            {
                return this->_alloc;
            }
        private :
            AVL_TREE<value_type, key_type, compare >  root;
            size_type              _size;
            Allocator               _alloc;
                
    };
}

template <class Key, class T, class Compare, class Alloc>
bool operator== ( const ft::map<Key,T,Compare,Alloc>& _x,
                const ft::map<Key,T,Compare,Alloc>& _y )
{
    if (_x.size() != _y.size())
        return false;
    return std::equal(_x.begin(), _x.end(), _y.begin());
}

template <class Key, class T, class Compare, class Alloc>
  bool operator!= ( const ft::map<Key,T,Compare,Alloc>& _x,
                    const ft::map<Key,T,Compare,Alloc>& _y )
{
    return !(_x == _y);
}

template <class Key, class T, class Compare, class Alloc>
  bool operator<  ( const ft::map<Key,T,Compare,Alloc>& _x,
                    const ft::map<Key,T,Compare,Alloc>& _y )
{
	return std::lexicographical_compare(_x.begin(), _x.end(), _y.begin(), _y.end());
}

template <class Key, class T, class Compare, class Alloc>
  bool operator<= ( const ft::map<Key,T,Compare,Alloc>& _x,
                    const ft::map<Key,T,Compare,Alloc>& _y )
{
    return !(_x < _y);
}

template <class Key, class T, class Compare, class Alloc>
  bool operator>  ( const ft::map<Key,T,Compare,Alloc>& _x,
                    const ft::map<Key,T,Compare,Alloc>& _y )
{
    return _x < _y;
}

template <class Key, class T, class Compare, class Alloc>
  bool operator>= ( const ft::map<Key,T,Compare,Alloc>& _x,
                    const ft::map<Key,T,Compare,Alloc>& _y )
{
    return !(_x < _y);
}

#endif
