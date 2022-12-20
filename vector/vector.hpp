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
#include "../utils/utils.hpp"

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
			typedef typename ft::iterator<const T>			const_iterator;
			typedef typename ft::reverse_iterator<ft::iterator<T> >		reverse_iterator;
			typedef typename ft::reverse_iterator<ft::iterator<const T> >	const_reverse_iterator;
			
		private :
			T			*m_data;
			size_type	_size;
			Alloc		_alloc;
			size_type	_capacity;
		public:
			operator const_iterator() { return const_iterator(m_data); }
			explicit vector (const allocator_type& alloc = allocator_type())
			{
				m_data = NULL;
				_alloc = alloc;
				_capacity = 0;
				_size = 0;
			}
			explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
			{
				_alloc = alloc;
				this->_size = n;
				_capacity  = _size;
				m_data = _alloc.allocate(n);
				for (size_t i = 0; i < n; i++)
					_alloc.construct(m_data + i , val);
			}
			template <class InputIterator>
         	vector (InputIterator first, typename std::enable_if<std::__is_input_iterator<InputIterator>::value &&
			! std::is_integral<InputIterator>::value , InputIterator>::type last , const allocator_type& alloc = allocator_type())
			{
				size_type i = 0;
				_alloc = alloc;
				size_type dis = *(last - 1) - *first + 1;
				_capacity = _size = dis;
				m_data = _alloc.allocate(_size);
				while (first != (last))
				{
					_alloc.construct(m_data + i , *first);
					i++;
					first++;
				}
			}
			vector (const vector& x)                                                                                                                                                              
			{
				*this = x;
			}
			~vector() {  
				if (_size > 0)
				{
					_alloc.deallocate(m_data, _capacity);
					clear();
				}
				_size = 0;
				_capacity = 0;
			}
			vector& operator= (const vector& x)
			{
				m_data = _alloc.allocate(x._capacity);
				for (size_t i = 0; i < x.size(); i++)
					_alloc.construct(&m_data[i], x.m_data[i]);
				this->_size = x._size;
				this->_capacity = x._capacity;
				this->_alloc = x.get_allocator();
				return *this;
			}
			iterator begin() 								{ return iterator(m_data); }
			const_iterator begin() const					{ return const_iterator(m_data); }
			iterator end() 									{ return iterator((m_data + _size)); }
			const_iterator end() const 						{ return const_iterator(m_data + _size); }
			size_type	capacity() 							{ return _capacity; }
			size_type max_size() const 						{ return _alloc.max_size(); }
			reverse_iterator rbegin()						{ return reverse_iterator(iterator(m_data + (_size - 1))); }
			const_reverse_iterator rbegin() const 			{ return const_reverse_iterator(const_iterator(m_data + (_size - 1))); }
			reverse_iterator rend() 						{ return reverse_iterator(iterator(m_data - 1)); }
			const_reverse_iterator rend() const 					{ return const_reverse_iterator(const_iterator(m_data - 1)); }
			reference front() 								{ return m_data; }
			const_reference front() const 					{ return m_data; }
		    reference back() 								{ return this->m_data[this->_size - 1]; }
		    const_reference	back() const 					{ return this->m_data[this->_size - 1]; }
			reference at (size_type n)
			{
				if (n < _size)
					return m_data[n];
				throw std::out_of_range("Out of range") ;
			}
			const_reference at (size_type n) const 
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
					for (size_t i = 0; i < _size; i++) temp[i] = m_data[i];
					_alloc.deallocate(m_data, _size);
					m_data = _alloc.allocate(n);
					for (size_t i = 0; i < _size ; i++) m_data[i] = temp[i];
					_alloc.deallocate(temp, _size);
					for (size_t i = _size; i < n; i++) m_data[i] = val;
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
			const_reference operator[] (size_type n) const	
			{
				T* temp = _alloc.allocate(1);
				if (_size == 0 || n >= _size)
					temp[3] = 6;
				_alloc.deallocate(temp, 1);
				return (m_data[n]);
			}
			reference operator[] (size_type n) { 
				T* temp = _alloc.allocate(1);
				if (_size == 0 || n >= _size)
					temp[3] = 6;
				_alloc.deallocate(temp, 1);
				return this->m_data[n]; 
			}
			bool empty() const {
				if (_size == 0) return false;
				return true;
			}
			template <class InputIterator>
			void assign (InputIterator first, typename std::enable_if<std::__is_input_iterator<InputIterator>::value
			&& ! std::is_integral<InputIterator>::value , InputIterator>::type last) {
				size_type dis = (*(last - 1) - *first) + 1;			
				size_t i = 0;
				if (dis < _capacity)
				{
					_size = dis;
					while (first++ != (last - 1))
					{
						m_data[i] = *first;
						i++;
					}
				}
				else {
					_size = _capacity = dis;
					_alloc.deallocate(m_data, _capacity);
					m_data = _alloc.allocate(dis);
					while (first++ != (last - 1))
					{
						m_data[i] = *first;
						i++;
					}
				}
			}
			void assign (size_type n, const value_type& val) {
				if (n < _capacity)
				{
					_size = n;
					for (size_t i = 0; i < n; i++)
						this->m_data[i] = val;
				}
				else
				{
 					_size = _capacity = n;
					_alloc.deallocate(m_data, _capacity);
					m_data = _alloc.allocate(n);
					for (size_t i = 0; i < _size; i++)
						_alloc.construct(m_data + i, val);
				}
			}
			void push_back (const value_type& val)
			{
				if (_size == 0)
				{
					m_data  = _alloc.allocate(1);
					_alloc.construct(m_data, val);
					_size = 1 ;
					_capacity = 1;
				}
				else if (_size < _capacity)
				{
					_alloc.construct(&m_data[_size], val);
					_size++;
				}
				else
				{
					_capacity *= 2;
					T* temp = _alloc.allocate(_size);
					for (size_t i = 0; i < _size; i++) _alloc.construct((temp + i), m_data[i]);
					_alloc.deallocate(m_data, _size);
					m_data = _alloc.allocate(_capacity);
					for (size_t i = 0; i < _size; i++) _alloc.construct((m_data + i), temp[i]);
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
						return begin();
					}
					counter++;
					it++;
				}
				return begin();
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
						size_type i = -1;
						size_type temp = _size - 1;
						while (++i < n)
							push_back(val);
						int temp_size = _size - 1;
						while (temp_size > counter)
						{
							m_data[temp_size] = m_data[temp];
							if (temp == 0)
								break;
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
    		void insert (iterator position, InputIterator first, 
			typename std::enable_if<std::__is_input_iterator<InputIterator>::value 
			&& !std::is_integral<InputIterator>::value, InputIterator>::type last)
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
							push_back(*first);
							first++;
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
				size_type counter = 0;
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
				size_type size_ = 0;
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
			void clear() 							{_size = 0 ;  _alloc.destroy(this->m_data); }
			allocator_type get_allocator() const	{ return this->_alloc; }
			size_type size() const					{ return this->_size; }
	};


template <class T, class Alloc>
bool operator== (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
{
	if (lhs.size() != rhs.size())
		return false;
	for (size_t i = 0; i < lhs.size(); i++)
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
	for (size_t i = 0; i < lhs.size(); i++)
	{
		if (lhs[i] != rhs[i])
			return true;
	}
	return false;
}

template <class T, class Alloc>
bool operator<  (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
{
	for (size_t i = 0; i < rhs.size(); i++)
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
	for (size_t i = 0; i < lhs.size(); i++)
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

template <class T, class Allocator>
void swap(vector<T,Allocator>& x, vector<T,Allocator>& y)
{
	std::swap(x, y);
}

}

#endif