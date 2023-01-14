/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avl_pair.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otmallah <otmallah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 15:55:53 by otmallah          #+#    #+#             */
/*   Updated: 2023/01/15 00:04:01 by otmallah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <map>


#include <map>

#include <vector>
#include <iostream>
#include <iterator>
#include <utility>
#include <ctime>
#include <iomanip>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>
#include <random>

#define TIME_FAC 4 // the ft::map methods can be slower up to std::map methods * TIME_FAC (MAX 20)

#include "../map/map.hpp"

template <typename Iter1, typename Iter2>
bool compareMaps(Iter1 first1, Iter1 last1, Iter2 first2, Iter2 last2)
{
    for (; (first1 != last1) && (first2 != last2); ++first1, ++first2)
        if (first1->first != first2->first || first1->second != first2->second)
            return false;
    return true;
}

time_t get_time(void)
{
    struct timeval time_now;

    gettimeofday(&time_now, NULL);
    time_t msecs_time = (time_now.tv_sec * 1e3) + (time_now.tv_usec / 1e3);
    return (msecs_time);
}


#define EQUAL(x) ((x) ? (std::cout << "\033[1;32mAC\033[0m\n") : (std::cout << "\033[1;31mWA\033[0m\n"))

int main ()
{
    
// bool cond;
{
            time_t start, end, diff;
            /*------------------ std::maps ---------------------*/
            std::map<int, std::string> m1;
            ft::map<int, std::string> ft_m1;

            for (size_t i = 0; i < 1e3; i++)
            {
                m1.insert(std::make_pair(i, "string2"));
                ft_m1.insert(std::make_pair(i, "string2"));
            }
            start = get_time();
            m1[1e6] = "string";
            end = get_time();
            diff = end - start;
            diff = (diff) ? (diff * TIME_FAC) : TIME_FAC;
            /*-----------------------------------------------------*/
            /*------------------ ft::maps ---------------------*/
            ualarm(diff * 1e3, 0);
            ft_m1[1e6] = "string";
            ualarm(0, 0);
            /*----------------------------------------------------*/
            /*------------------ std::maps ---------------------*/
            start = get_time();
            m1[1e6 - 100] = "string";
            end = get_time();
            diff = end - start;
            diff = (diff) ? (diff * TIME_FAC) : TIME_FAC;
            /*-----------------------------------------------------*/
            /*------------------ ft::maps ---------------------*/
            ualarm(diff * 1e3, 0);
            ft_m1[1e6 - 100] = "string";
            ualarm(0, 0);
            /*----------------------------------------------------*/
            /*------------------ std::maps ---------------------*/
            start = get_time();
            m1[1e6 - 100] = m1[1e5];
            end = get_time();
            diff = end - start;
            diff = (diff) ? (diff * TIME_FAC) : TIME_FAC;
            /*-----------------------------------------------------*/
            // /*------------------ ft::maps ---------------------*/
            ualarm(diff * 1e3, 0);
            ft_m1[1e6 - 100] = ft_m1[1e5];
            ualarm(0, 0);
            /*----------------------------------------------------*/
        }
        std::map<char, std::string> m;
        ft::map<char, std::string> ft_m;

        m['a'] = "an element";
        m['b'] = "another element";
       /// m['c'] = m['b'];
        //m['a'] = "test";

        ft_m['a'] = "an element";

        
        ft_m['b'] = "another element";

        
        //ft_m['c'] = ft_m['b'];
        //ft_m['a'] = "test";
    
        std::cout << ft_m['b'] << std::endl;
    
    //     ft::map<char, std::string>::iterator it = ft_m.begin();


    //     while (it != ft_m.end())
    //     {
    //         std::cout << it->second << std::endl;
    //         it++;
    //     }


    // std::map<char, std::string>::iterator it1 = m.begin();


    //     while (it1 != m.end())
    //     {
    //         std::cout << it1->second << std::endl;
    //         it1++;
    //     }




        EQUAL(m['a'] == ft_m['a'] && m['b'] == ft_m['b'] && m['c'] == ft_m['c'] && m.size() == ft_m.size());
    
}
