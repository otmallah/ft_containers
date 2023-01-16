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
#include "../utils/is_integral.hpp"
#include "../allocator/allocator.hpp"

class reverse_iterator;

namespace ft
{
	template<class T, class Alloc = ft::allocator<T> > 
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
			typedef typename ft::reverse_iterator<iterator>		reverse_iterator;
			typedef typename ft::reverse_iterator<const_iterator>	const_reverse_iterator;
			
		private :
			T			*m_data;
			size_type	_size;
			Alloc		_alloc;
			size_type   leaks;
			size_type	_capacity;
		public:
			operator const_iterator() { return const_iterator(m_data); }
			explicit vector (const allocator_type& alloc = allocator_type())
			{
				_alloc = alloc;
				_capacity = 0;
				_size = 0;
				leaks = 1;
				m_data = _alloc.allocate(1);
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
         	vector (InputIterator first, typename ft::enable_if<std::__is_input_iterator<InputIterator>::value
			&& std::__is_bidirectional_iterator<InputIterator>::value
			, InputIterator>::type last , const allocator_type& alloc = allocator_type())
			{
				size_type i = 0;
				_alloc = alloc;
				int dis = 0;	
				dis =  std::distance(first, last);
				if (dis < 0)
					dis = std::distance(first, last);
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
				clear();
				_alloc.deallocate(m_data, _capacity);
				_size = 0;
				_capacity = 0;
			}
			vector& operator= (const vector& x)
			{
				if (leaks == 1)
					_alloc.deallocate(m_data, 1);
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
			size_type	capacity() const					{ return _capacity; }
			size_type max_size() const 						{ return _alloc.max_size(); }
			reverse_iterator rbegin()						{ return reverse_iterator(iterator(&m_data[_size])); }
			const_reverse_iterator rbegin() const 			{ return const_reverse_iterator(const_iterator(&m_data[_size])); }
			reverse_iterator rend() 						{ return reverse_iterator(iterator(m_data)); }
			const_reverse_iterator rend() const 					{ return const_reverse_iterator(const_iterator(&m_data[0])); }
			reference front() 								{ return m_data[0]; }
			const_reference front() const 					{ return m_data[0]; }
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
					T* temp = m_data;
					if (n > _capacity)
					{
						m_data = _alloc.allocate(n);
						_capacity = n;
						for (size_t i = 0; i < _size ; i++) 
							_alloc.construct(&m_data[i], temp[i]);
						_alloc.deallocate(temp, _size);
					}
					for (size_t i = _size; i < n; i++)
						_alloc.construct(&m_data[i], val);
					_size = n;
				}
			}
			void reserve (size_type n)
			{
				if (n > _capacity)
				{
					T* temp = m_data;
					m_data = _alloc.allocate(n);
					_capacity = n;
					for (size_t i = 0; i < _size ; i++) 
						_alloc.construct(&m_data[i], temp[i]);
					_alloc.deallocate(temp, _size);
				}
			}
			const_reference operator[] (size_type n) const	
			{
				return (m_data[n]);
			}
			reference operator[] (size_type n) { 
				return this->m_data[n]; 
			}
			bool empty() const {
				if (_size == 0) return true;
				return false;
			}
			template <class InputIterator>
			void assign (InputIterator first, typename ft::enable_if<std::__is_input_iterator<InputIterator>::value
			&& ! ft::is_integral<InputIterator>::type && std::__is_bidirectional_iterator<InputIterator>::value
			, InputIterator>::type last) {
				size_t dis = std::distance(first, last);
				int i = 0;
				if (dis < _capacity)
				{
					_size = dis;
					while (first != (last))
					{
						m_data[i] = *first;
						first++;
						i++;
					}
				}
				else {
					clear();
					_alloc.deallocate(m_data, _capacity);
					_size = _capacity = dis;
					m_data = _alloc.allocate(_capacity);
					while (first != (last))
					{
						m_data[i] = *first;
						first++;
						i++;
					}
				}
			}
			void assign (size_type n, const value_type& val) {
				if (n < _capacity)
				{
					_size = n;
					for (size_t i = 0; i < n; i++)
						_alloc.construct(m_data + i, val);
				}
				else
				{
					clear();
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
					T* temp = m_data;
					_capacity *= 2;
					m_data = _alloc.allocate(_capacity);
					for (size_t i = 0; i < _size; i++) 
						_alloc.construct(&m_data[i], temp[i]);
					_alloc.construct(&m_data[_size], val);
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
				iterator _it = end() + 1;
				while (it != _it)
				{
					if (&(*it) == &(*position))
					{
						push_back(val);
						_save = m_data[counter];
						m_data[counter] = back();
						back() = _save;
						int i = _size - 1;
						while ((i - 1) > counter)
						{
							_save = m_data[i];
							m_data[i] = m_data[i - 1];
							m_data[i - 1] = _save;
							i--;
						}
						it = &m_data[counter];
						return it;
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
				iterator _it = end() + 1;
				while (it != _it)
				{
					if (&(*it) == &(*position))
					{
						int __temp = -1;
						size_type i = 0;
						int temp = 0;
						if (_size > 0)
							temp = _size - 1;
						if (n > _capacity || _size == 0)
							__temp = _capacity;
						while (i++ < n)
							push_back(val);
						if (__temp != -1)
							_capacity = __temp + n;
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
			typename ft::enable_if<std::__is_input_iterator<InputIterator>::value 
			&& !ft::is_integral<InputIterator>::type, InputIterator>::type last)
			{
				InputIterator _first = first;
				int counter = 0;
				iterator it = begin();
				iterator _it = end() + 1;
				while (it != _it)
				{
					if (&(*it) == &(*position))
					{
						int __temp = -1;
						size_type i = 0;
						vector<T> vec(first, last);
						size_type temp = 0;
						if (_size > 0)
							temp = _size - 1;
						if (vec.size() > _capacity || _size == 0)
							__temp = _capacity;
						while (i < vec.size())
						{
							push_back(vec[i]);
							i++;
						}
						if (__temp != -1)
							_capacity = __temp + vec.size();
						int temp_size = _size - 1;
						while (temp_size > counter && temp >= 0)
						{
							m_data[temp_size] = m_data[temp];
							if (temp == 0)
								break;
							temp_size--;
							temp--;
						}
						first = _first;
						i = 0;
						while (i < vec.size())
						{
							m_data[counter] = vec[i];
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
				iterator _it = end() + 1;
				size_type counter = 0;
				while (it != _it) 
				{
					if (&(*it) == &(*position))
					{
						_alloc.destroy(&m_data[counter]);
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
				size_type dis = 0;
				iterator it = begin();
				iterator _it = end() + 1;
				int counter = 0;
				dis = std::distance(first, last);
				while (it != _it)
				{
					if (&(*it) == &(*first))
					{
						int oldSize = this->_size;
						this->_size -= dis;
						int rightPtr = counter + dis; 
						while (rightPtr < oldSize)
							std::swap(m_data[counter++], m_data[rightPtr++]);
						return first;
					}
					counter++;
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
				for (size_t i = 0 ; i < _size ; i++)
					_alloc.destroy(&this->m_data[i]);
				_size = 0;
			}
			allocator_type get_allocator() const	{ return this->_alloc; }
			size_type size() const					{ return this->_size; }
	};


template <class T, class Alloc>
bool operator== (const ft::vector<T,Alloc>& __x, const ft::vector<T,Alloc>& __y)
{
	if (__x.size() != __y.size())
		return false;
	return ft::equal(__x.begin(), __x.end(), __y.begin());
}

template <class T, class Alloc>
bool operator!= (const ft::vector<T,Alloc>& __x, const ft::vector<T,Alloc>& __y)
{
	return !(__x == __y);
}

template <class T, class Alloc>
bool operator<  (const ft::vector<T,Alloc>& __x, const ft::vector<T,Alloc>& __y)
{
	return ft::lexicographical_compare(__x.begin(), __x.end(), __y.begin(), __y.end());
}

template <class T, class Alloc>
bool operator<= (const ft::vector<T,Alloc>& __x, const ft::vector<T,Alloc>& __y)
{
	return !(__y < __x);
}


template <class T, class Alloc>
bool operator>  (const ft::vector<T,Alloc>& __x, const ft::vector<T,Alloc>& __y)
{
	return __y < __x;
}

template <class T, class Alloc>
bool operator>= (const ft::vector<T,Alloc>& __x, const ft::vector<T,Alloc>& __y)
{
	return !(__x < __y);
}

template <class T, class Allocator>
void swap(vector<T,Allocator>& __x, vector<T,Allocator>& __y)
{
	__x.swap(__y);
}

}

#endif