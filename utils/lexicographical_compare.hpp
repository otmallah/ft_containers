/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexicographical_compare.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otmallah <otmallah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 18:04:04 by otmallah          #+#    #+#             */
/*   Updated: 2022/12/22 21:37:17 by otmallah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _LEXICOGRAPHICAL_COMPARE_HPP_
#define _LEXICOGRAPHICAL_COMPARE_HPP_

#include <iostream>

template <class InputIterator1, class InputIterator2>
bool lexicographical_compare1 (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2)
{
	while (first1!=last1)
	{
		if (first2==last2 || *first2<*first1) return false;
		else if (*first1<*first2) return true;
		++first1; ++first2;
	}
	return (first2!=last2);
}

#endif