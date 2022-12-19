/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equal.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otmallah <otmallah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 18:01:07 by otmallah          #+#    #+#             */
/*   Updated: 2022/12/19 18:01:51 by otmallah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _EQUAL_HPP_
#define _EQUAL_HPP_

#include <iostream>

template <class InputIterator1, class InputIterator2>
	bool equal ( InputIterator1 first1, InputIterator1 last1, InputIterator2 first2 )
{
	while (first1 != last1)
	{
		if(!(*first1 == *first2))
			return false;
		++first1;
		++first2;
	}
	return true;
}

#endif