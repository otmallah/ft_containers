/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otmallah <otmallah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 00:31:15 by otmallah          #+#    #+#             */
/*   Updated: 2023/01/15 23:21:27 by otmallah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

namespace ft
    {

     
        
    template <class T> struct is_integral
    {
        static const bool type = false;
    };
    
    template < > struct is_integral <bool>
    {
        static const bool type = true;
    };
    template < > struct is_integral <char>
    {
        static const bool type = true;
    };
    template < > struct is_integral <char16_t>
    {
        static const bool type = true;
    };
    template < > struct is_integral <char32_t>
    {
        static const bool type = true;
    };
    template < > struct is_integral <wchar_t>
    {
        static const bool type = true;
    };
    template < > struct is_integral <signed char>
    {
        static const bool type = true;
    };
    template < > struct is_integral <short int>
    {
        static const bool type = true;
    };
    template < > struct is_integral <int>
    {
        static const bool type = true;
    };
    template < > struct is_integral <long int>
    {
        static const bool type = true;
    };
    template < > struct is_integral <long long int>
    {
        static const bool type = true;
    };
    template < > struct is_integral <unsigned char>
    {
        static const bool type = true;
    };
    template < > struct is_integral <unsigned short int>
    {
        static const bool type = true;
    };
    template < > struct is_integral <unsigned int>
    {
        static const bool type = true;
    };
    template < > struct is_integral <unsigned long int>
    {
        static const bool type = true;
    };
    template < > struct is_integral <unsigned long long int>
    {
        static const bool type = true;
    };
}