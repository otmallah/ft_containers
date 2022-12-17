	/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otmallah <otmallah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 20:18:18 by otmallah          #+#    #+#             */
/*   Updated: 2022/12/16 16:34:22 by otmallah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include "iterator.hpp"
#include "reverse_iterator.hpp"
// #include <stdexcept>

class reverse_iterator;

namespace ft
{
	template<class T, class Alloc = std::allocator<T> > 
	class vector
	{
		public:
			typedef T                               		 value_type;
			typedef Alloc                           		 allocator_type;
			typedef size_t									 size_type;
			typedef ptrdiff_t								 diffrence_type;
			typedef	typename allocator_type::reference		 reference;
			typedef typename allocator_type::const_reference const_reference;
			typedef typename allocator_type::pointer         pointer;
			typedef typename allocator_type::const_pointer   const_pointer;
			typedef	typename ft::iterator<T>  				iterator;
			typedef typename ft::reverse_iterator<T>		reverse_iterator;
			typedef typename ft::reverse_iterator<const T>	const_reverse_iterator;
			typedef typename ft::iterator<const T>			const_iterator;
			
		private :
			T			*m_data;
			size_type	_size;
			Alloc		_alloc;
			size_type	_capacity;
		public:
			explicit vector (const allocator_type& alloc = allocator_type())
			{
				m_data = _alloc.allocate(1);
				_capacity = 0;
				_size = 0;
			}
			explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
			{
				_alloc = alloc;
				this->_size = n;
				_capacity  = _size;
				m_data = _alloc.allocate(n);
				for (int i = 0; i < n; i++)
					_alloc.construct(m_data + i , val);
			}
			// template <class InputIterator>
         	// vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type())
			// {
			// 	int i = 0;
			// 	_alloc = alloc;
			// 	InputIterator temp = first;
			// 	while (temp++ != last)
			// 		_size++;
			// 	m_data = _alloc.allocate(_size);
			// 	while (first++ != (last - 1))
			// 	{
			// 		_alloc.construct(m_data + i , *first);
			// 		i++;
			// 	}
			// 	_capacity = _size;
			// }
			vector (const vector& x)                                                                                                                                                              
			{
				m_data = _alloc.allocate(x._capacity);
				for (int i = 0; i < x.size(); i++)
				{
					_alloc.construct(&m_data[i], x.m_data[i]);
				}
				this->_size = x._size;
				this->_capacity = x._capacity;
			}
			
			~vector() {  _alloc.deallocate(m_data, _capacity); }
			vector& operator= (const vector& x)
			{
				_alloc.deallocate(m_data, _capacity);
				this->m_data = _alloc.allocate(x._capacity);
				this->_size = x._size;
				this->_capacity = x._capacity;
				return *this;
			}
			iterator begin() 						{ return iterator(m_data); }
			const_iterator begin() const			{ return const_iterator(m_data); }
			iterator end() 							{ return iterator((m_data + _size)); }
			const_iterator end() const 				{ return const_iterator(m_data + _size); }
			size_type	capacity() 					{ return _capacity; }
			size_type max_size() const 				{ return _alloc.max_size(); }
			reverse_iterator rbegin()				{ return reverse_iterator((m_data + (_size - 1))); }
			const_reverse_iterator rbegin() const 	{ return const_reverse_iterator((m_data + (_size - 1))); }
			reverse_iterator rend() 				{ return reverse_iterator((m_data - 1)); }
			reverse_iterator rend() const 			{ return const_reverse_iterator(m_data - 1); }
			reference at (size_type n)
			{
				if (n < _size)
					return m_data[n];
				throw std::out_of_range("Out of range") ;
			}
			void resize (size_type n, value_type val = value_type())
			{
				if (n < _size)
					_size = n;
				else
				{
					T* temp = _alloc.allocate(_size);
					_capacity = n;
					for (int i = 0; i < _size; i++) temp[i] = m_data[i];
					_alloc.deallocate(m_data, _size);
					m_data = _alloc.allocate(n);
					for (int i = 0; i < _size ; i++) m_data[i] = temp[i];
					_alloc.deallocate(temp, _size);
					for (int i = _size - 1; i < n; i++) m_data[i] = val;
					_size = n;
				}
			}
			void reserve (size_type n)
			{
				int a = _size;
				if (n > _capacity)
				{
					resize(n);
					_size = a;
				}
			}
			reference operator[] (size_type n) { 
				T* temp = _alloc.allocate(1);
				if (_size == 0 || n >= _size)
					temp[3] = 6;
				_alloc.deallocate(temp, 1);
				return this->m_data[n]; 
			}
			const_reference operator[] (size_type n) const {
				return this->m_data[n];
			}
			reference front() {
				return	this->m_data[0];
			}
			const_reference front() const {
				return	this->m_data[0];
			}
		    reference back() {
				return	this->m_data[this->_size - 1];
			}
		    const_reference	back() const {
				return	this->m_data[this->_size - 1];
			}
			bool empty() const {
				if (_size == 0) return false;
				return true;
			}
			// template <class InputIterator>
			// void assign (InputIterator first, InputIterator last) {
			// 	size_t dis = std::distance(first, last);
			// 	int i = 0;
			// 	if (dis < _capacity)
			// 	{
			// 		_size = dis;
			// 		while (first++ != (last - 1))
			// 		{
			// 			m_data[i] = *first;
			// 			i++;
			// 		}
			// 	}
			// 	else {
			// 		_size = _capacity = dis;
			// 		_alloc.deallocate(m_data, _capacity);
			// 		m_data = _alloc.allocate(dis);
			// 		while (first++ != (last - 1))
			// 		{
			// 			m_data[i] = *first;
			// 			i++;
			// 		}
			// 	}
			// }
			void assign (size_type n, const value_type& val) {
				if (n < _capacity)
				{
					_size = n;
					for (int i = 0; i < n; i++)
						this->m_data[i] = val;
				}
				else
				{
 					_size = _capacity = n;
					_alloc.deallocate(m_data, _capacity);
					m_data = _alloc.allocate(n);
					_alloc.construct(m_data, val);
				}
			}
			void push_back (const value_type& val)
			{
				if (_size == 0)
					_capacity = 1;
				if (_size < _capacity)
				{
					m_data[_size] = val;
					_size++;
				}
				else
				{
					_capacity *= 2;
					T* temp = _alloc.allocate(_size);
					for (int i = 0; i < _size; i++) temp[i] = m_data[i];
					_alloc.deallocate(m_data, _size);
					m_data = _alloc.allocate(_capacity);
					for (int i = 0; i < _size; i++) m_data[i] = temp[i];
					m_data[_size] = val;
					_alloc.deallocate(temp, _size);
					_size++;
				}
			}
			void pop_back()
			{
				_alloc.destroy(&m_data[_size - 1]);
				_size--;
			}
			iterator insert (iterator position, const value_type& val)
			{
				T _save;
				int counter = 0;
				iterator it = begin();
				iterator _it = end();
				_it++;
				while (it != _it)
				{
					if (&(*it) == &(*position))
					{
						push_back(val);
						_save = m_data[counter];
						m_data[counter] = m_data[_size - 1];
						m_data[_size - 1] = _save;
						int i = _size - 1;
						while ((i - 1) > counter)
						{
							_save = m_data[i];
							m_data[i] = m_data[i - 1];
							m_data[i - 1] = _save;
							i--;
						}
						return position;
					}
					counter++;
					it++;
				}
				return position;
			}
			void insert (iterator position, size_type n, const value_type& val)
			{
				int counter = 0;
				iterator it = begin();
				iterator _it = end();
				_it++;
				while (it != _it)
				{
					if (&(*it) == &(*position))
					{
						int i = -1;
						int temp = _size - 1;
						while (++i < n)
							push_back(val);
						int temp_size = _size - 1;
						while (temp_size > counter && temp >= 0)
						{
							m_data[temp_size] = m_data[temp];
							temp_size--;
							temp--;
						}
						i = 0;
						while (i < n)
						{
							m_data[counter] = val;
							counter++;
							i++;
						}	
					}
					counter++;
					it++;
				}
			}
			template <class InputIterator>
    		void insert (iterator position, InputIterator first, InputIterator last)
			{
				InputIterator _first = first;
				int n = 0;
				int counter = 0;
				iterator it = begin();
				iterator _it = end();
				_it++;
				while (it != _it)
				{
					if (&(*it) == &(*position))
					{
						int i;
						int temp = _size - 1;
						while (first != last)
						{
							push_back(*first++);
							n++;
						}
						int temp_size = _size - 1;
						while (temp_size > counter && temp >= 0)
						{
							m_data[temp_size] = m_data[temp];
							temp_size--;
							temp--;
						}
						first = _first;
						i = 0;
						while (i < n)
						{
							m_data[counter] = *first;
							counter++;
							i++;
							first++;
						}	
					}
					counter++;
					it++;
				}
			}
			iterator erase (iterator position)
			{
				iterator it = begin();
				iterator _it = end();
				int counter = 0;
				_it++;
				while (it != _it)
				{
					if (&(*it) == &(*position))
					{
						if (_size == 1)
						{
							_size--;
							return position;
						}
						while ((counter + 1) < _size)
						{
							m_data[counter] = m_data[counter + 1];
							counter++;
						}
						_size--;
						return position;
					}
					counter++;
					it++;
				}
				return position;
			}
			iterator erase (iterator first, iterator last)
			{
				int size_ = 0;
				iterator _first = first;
				iterator it = begin();
				iterator _it = end();
				int counter = 0;
				while (_first++ != last)
					size_++;
				_it++;
				while (it != _it)
				{
					if (&(*it) == &(*first))
					{
						int a = size_;
						while (size_ < _size)
						{
							m_data[counter] = m_data[size_];
							counter++;
							size_++;
						}
						_size -= a;
					}
					it++;
				}
				return first;
			}
			void swap (vector& x)
			{
				std::swap(x._size, this->_size);
				std::swap(x._capacity, _capacity);
				std::swap(x.m_data, m_data);
 			}
			void clear()
			{
				_size = 0;
				_alloc.destroy(this->m_data);
			}
			allocator_type get_allocator() const
			{
				return _alloc;
			}
			size_type size() const
			{
				return _size;
			}
	};


template <class T, class Alloc>
bool operator== (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
{
	if (lhs.size() != rhs.size())
		return false;
	for (int i = 0; i < lhs.size(); i++)
	{
		if (lhs[i] != rhs[i])
			return false;
	}
	return true;
}

template <class T, class Alloc>
bool operator!= (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
{
	if (lhs.size() != rhs.size())
		return true;
	for (int i = 0; i < lhs.size(); i++)
	{
		if (lhs[i] != rhs[i])
			return true;
	}
	return false;
}

template <class T, class Alloc>
bool operator<  (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
{
	for (int i = 0; i < rhs.size(); i++)
	{
		if (lhs[i] >= rhs[i])
			return false;
	}
	return true;
}

template <class T, class Alloc>
bool operator<= (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
{
	if (lhs == rhs || lhs < rhs)
		return true;
	return false;
}


template <class T, class Alloc>
bool operator>  (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
{
	if (lhs.size() > rhs.size())
		return true;
	for (int i = 0; i < lhs.size(); i++)
	{
		if (lhs[i] <= rhs[i])
			return false;
	}
	return true;
}

template <class T, class Alloc>
bool operator>= (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
{
	if (lhs > rhs || lhs == rhs)
		return true;
	return false;
}
}

#endif