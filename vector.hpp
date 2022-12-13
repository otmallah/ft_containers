/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otmallah <otmallah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 20:18:18 by otmallah          #+#    #+#             */
/*   Updated: 2022/12/13 14:42:00 by otmallah         ###   ########.fr       */
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
			// typedef class allocater_type::const_pointer   const_pointer;
			typedef	typename ft::iterator<T>  				iterator;
			typedef typename ft::reverse_iterator<T>		reverse_iterator;
			typedef typename ft::iterator<const T>			const_iterator;
			
		private :
			T			*temp_vec;
			size_type	_size;
			Alloc		_alloc;
			size_type	_capacity;
		public:
			explicit vector (const allocator_type& alloc = allocator_type())
			{
				temp_vec = _alloc.allocate(1);
				_capacity = 0;
				_size = 0;
			}
			explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
			{
				_alloc = alloc;
				this->_size = n;
				_capacity  = _size;
				temp_vec = _alloc.allocate(n);
				for (int i = 0; i < n; i++)
					_alloc.construct(temp_vec + i , val);
			}
			// template <class InputIterator>
         	// vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type())
			// {
			// 	int i = 0;
			// 	_alloc = alloc;
			// 	InputIterator temp = first;
			// 	while (temp++ != last)
			// 		_size++;
			// 	temp_vec = _alloc.allocate(_size);
			// 	while (first++ != (last - 1))
			// 	{
			// 		_alloc.construct(temp_vec + i , *first);
			// 		i++;
			// 	}
			// 	_capacity = _size;
			// }
			vector (const vector& x)                                                                                                                                                              
			{
				temp_vec = x.temp_vec;
				_size = x._size;
				_capacity = x._capacity;
			}
			~vector() { _alloc.deallocate(temp_vec, _capacity); }
			vector& operator= (const vector& x)
			{
				this->_size = x._size;
				this->_capacity = x._capacity;
				this->temp_vec = x.temp_vec;
				return *this;
			}
			iterator begin()
			{
				return iterator(&temp_vec[0]);
			}
			iterator end()
			{
				return iterator(&temp_vec[_size]);
			}
			size_type	capacity()
			{
				return _capacity;
			}
			reference at (size_type n)
			{
				if (n < _size)
					return temp_vec[n];
				throw std::out_of_range("Out of range") ;
			}
			size_type max_size() const
			{
				return _alloc.max_size();
			}
			reverse_iterator rbegin()
			{
				return reverse_iterator(&temp_vec[_size - 1]);
			}
			reverse_iterator rend()
			{
				return reverse_iterator(&temp_vec[-1]);
			}
			void resize (size_type n, value_type val = value_type())
			{
				if (n < _size)
					_size = n;
				else
				{
					T* temp = _alloc.allocate(_size);
					_capacity = n;
					for (int i = 0; i < _size; i++) temp[i] = temp_vec[i];
					_alloc.deallocate(temp_vec, _size);
					temp_vec = _alloc.allocate(n);
					for (int i = 0; i < _size ; i++) temp_vec[i] = temp[i];
					_alloc.deallocate(temp, _size);
					for (int i = _size - 1; i < n; i++) temp_vec[i] = val;
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
				return this->temp_vec[n]; 
			}
			const_reference operator[] (size_type n) const {
				return this->temp_vec[n];
			}
			reference front() {
				return	this->temp_vec[0];
			}
			const_reference front() const {
				return	this->temp_vec[0];
			}
		    reference back() {
				return	this->temp_vec[this->_size - 1];
			}
		    const_reference	back() const {
				return	this->temp_vec[this->_size - 1];
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
			// 			temp_vec[i] = *first;
			// 			i++;
			// 		}
			// 	}
			// 	else {
			// 		_size = _capacity = dis;
			// 		_alloc.deallocate(temp_vec, _capacity);
			// 		temp_vec = _alloc.allocate(dis);
			// 		while (first++ != (last - 1))
			// 		{
			// 			temp_vec[i] = *first;
			// 			i++;
			// 		}
			// 	}
			// }
			void assign (size_type n, const value_type& val) {
				if (n < _capacity)
				{
					_size = n;
					for (int i = 0; i < n; i++)
						this->temp_vec[i] = val;
				}
				else
				{
 					_size = _capacity = n;
					_alloc.deallocate(temp_vec, _capacity);
					temp_vec = _alloc.allocate(n);
					_alloc.construct(temp_vec, val);
				}
			}
			void push_back (const value_type& val)
			{
				if (_size == 0)
					_capacity = 1;
				if (_size < _capacity)
				{
					temp_vec[_size] = val;
					_size++;
				}
				else
				{
					_capacity *= 2;
					T* temp = _alloc.allocate(_size);
					for (int i = 0; i < _size; i++) temp[i] = temp_vec[i];
					_alloc.deallocate(temp_vec, _size);
					temp_vec = _alloc.allocate(_capacity);
					for (int i = 0; i < _size; i++) temp_vec[i] = temp[i];
					temp_vec[_size] = val;
					_alloc.deallocate(temp, _size);
					_size++;
				}
			}
			void pop_back()
			{
				_alloc.destroy(&temp_vec[_size - 1]);
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
						_save = temp_vec[counter];
						temp_vec[counter] = temp_vec[_size - 1];
						temp_vec[_size - 1] = _save;
						int i = _size - 1;
						while ((i - 1) > counter)
						{
							_save = temp_vec[i];
							temp_vec[i] = temp_vec[i - 1];
							temp_vec[i - 1] = _save;
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
							temp_vec[temp_size] = temp_vec[temp];
							temp_size--;
							temp--;
						}
						i = 0;
						while (i < n)
						{
							temp_vec[counter] = val;
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
							temp_vec[temp_size] = temp_vec[temp];
							temp_size--;
							temp--;
						}
						first = _first;
						i = 0;
						while (i < n)
						{
							temp_vec[counter] = *first;
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
							temp_vec[counter] = temp_vec[counter + 1];
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
							temp_vec[counter] = temp_vec[size_];
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
				size_type temp_size;
				size_type temp_capacity;
				// swapp size 
				temp_size = x._size;
				x._size = this->_size;
				this->_size = temp_size;
				// swap capacity
				temp_capacity = x._capacity;
				x._capacity = this->_capacity;
				this->_capacity = temp_capacity;
				// swap tab of vector
				T* temp = x.temp_vec;
				x.temp_vec = this->temp_vec;
				this->temp_vec = temp;
 			}
			void clear()
			{
				_size = 0;
				_alloc.destroy(this->temp_vec);
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
}


#endif