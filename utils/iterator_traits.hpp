/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otmallah <otmallah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 17:59:21 by otmallah          #+#    #+#             */
/*   Updated: 2022/12/19 17:59:59 by otmallah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _ITERATOR_TRAITS_
#define _ITERATOR_TRAITS_

template <class Iterator> struct iterator_traits {
	typedef typename Iterator::difference_type  difference_type;
	typedef typename Iterator::value_type       value_type;
	typedef typename Iterator::pointer          pointer;
	typedef typename Iterator::reference         reference;
	typedef typename Iterator::iterator_category    iterator_category;
};

template <class T> struct iterator_traits<T*> {
	typedef ptrdiff_t  differance_type;
	typedef T			value_type;
	typedef T*			pointer;
	typedef T&			reference;
	typedef	std::random_access_iterator_tag iterator_category;
};

template <class T> struct iterator_traits<const T*> {
	typedef ptrdiff_t  differance_type;
	typedef T			value_type;
	typedef const T*			pointer;
	typedef const T&			refrence;
	typedef	std::random_access_iterator_tag iterator_category;
};

#endif