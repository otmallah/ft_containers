/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avl_pair.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otmallah <otmallah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 15:55:53 by otmallah          #+#    #+#             */
/*   Updated: 2023/01/14 21:10:17 by otmallah         ###   ########.fr       */
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
        {
            // time_t start, end, diff;

            // /* ------------------ a > b ------------------ */
            // std::map<int, std::string> m1, m2;
            // ft::map<int, std::string> ft_m1, ft_m2;
            // for (size_t i = 0; i < 1e1; i++)
            // {
            //     m1.insert(std::make_pair(i, "string2"));
            //     ft_m1.insert(std::make_pair(i, "string2"));
            // }

            // start = get_time();
            // m1.swap(m2);
            // end = get_time();
            // diff = end - start;
            // diff = (diff) ? (diff * TIME_FAC) : TIME_FAC;
            // /*-----------------------------------------------------*/
            // ualarm(diff * 1e3, 0);
            // ft_m1.swap(ft_m2);
            // ualarm(0, 0);
            // /*----------------------------------------------------*/

            // /* ------------------ a and b are not empty ------------------ */
            // for (size_t i = 0; i < 1e1; i++)
            // {
            //     m2.insert(std::make_pair(i, "string2"));
            //     ft_m2.insert(std::make_pair(i, "string2"));
            // }

            // start = get_time();
            // m1.swap(m2);
            // end = get_time();
            // diff = end - start;
            // diff = (diff) ? (diff * TIME_FAC) : TIME_FAC;
            // /*-----------------------------------------------------*/
            // ualarm(diff * 1e3, 0);
            // ft_m1.swap(ft_m2);
            // ualarm(0, 0);
            // /*----------------------------------------------------*/

            // /* ------------------ a == b ------------------ */
            // m1 = m2 = std::map<int, std::string>();
            // ft_m1 = ft_m2 = ft::map<int, std::string>();
            // start = get_time();
            // m2.swap(m1);
            // end = get_time();
            // diff = end - start;
            // diff = (diff) ? (diff * TIME_FAC) : TIME_FAC;
            // /*-----------------------------------------------------*/
            // /*------------------ ft::maps ---------------------*/
            // ualarm(diff * 1e3, 0);
            // ft_m2.swap(ft_m1);
            // ualarm(0, 0);
            /*----------------------------------------------------*/
        }
        bool cond = false;
        std::map<char, int> foo, bar;
        ft::map<char, int> ft_foo, ft_bar;

        foo['x'] = 100;
        foo['y'] = 200;

        ft_foo['x'] = 100;
        ft_foo['y'] = 200;

        cond = foo.size() == ft_foo.size() && bar.size() == ft_bar.size();

        bar['a'] = 11;
        bar['b'] = 22;
        bar['c'] = 33;

        ft_bar['a'] = 11;
        ft_bar['b'] = 22;
        ft_bar['c'] = 33;

        cond = cond && foo.size() == ft_foo.size() && bar.size() == ft_bar.size() && compareMaps(foo.begin(), foo.end(), ft_foo.begin(), ft_foo.end()) && compareMaps(bar.begin(), bar.end(), ft_bar.begin(), ft_bar.end());

        foo.swap(bar);
        ft_foo.swap(ft_bar);

        cond = cond && foo.size() == ft_foo.size() && bar.size() == ft_bar.size() && compareMaps(foo.begin(), foo.end(), ft_foo.begin(), ft_foo.end()) && compareMaps(bar.begin(), bar.end(), ft_bar.begin(), ft_bar.end());

        std::map<std::string, std::string, std::greater<std::string> > m1, m2;
        ft::map<std::string, std::string, std::greater<std::string> > ft_m1, ft_m2;

        m1["γ"] = "gamma";
        m1["β"] = "beta";
        m1["α"] = "alpha";
        m1["γ"] = "gamma";

        m2["ε"] = "eplsilon";
        m2["δ"] = "delta";
        m2["ε"] = "epsilon";

        ft_m1["γ"] = "gamma";
        ft_m1["β"] = "beta";
        ft_m1["α"] = "alpha";
        ft_m1["γ"] = "gamma";

        ft_m2["ε"] = "eplsilon";
        ft_m2["δ"] = "delta";
        ft_m2["ε"] = "epsilon";

        const std::pair<std::string, std::string> &ref = *(m1.begin());
        const std::map<std::string, std::string, std::greater<std::string> >::iterator iter = std::next(m1.begin());
        const std::pair<std::string, std::string> &ft_ref = *(ft_m1.begin());
        const ft::map<std::string, std::string, std::greater<std::string> >::iterator ft_iter = std::next(ft_m1.begin());

        // std::cout << "──────── before swap ────────\n"
        //           << "m1: " << m1 << "m2: " << m2 << "ref: " << ref
        //           << "\niter: " << *iter << '\n';

        cond = cond && ref.first == ft_ref.first && ref.second == ft_ref.second && iter->second == ft_iter->second && iter->first == ft_iter->first && m1.size() == ft_m1.size() && m2.size() && ft_m2.size();

        m1.swap(m2);
        ft_m1.swap(ft_m2);

        // _---------------_ << ──────── after swap ──────── >> _---------------_

        cond = cond && ref.first == ft_ref.first && ref.second == ft_ref.second && iter->second == ft_iter->second && iter->first == ft_iter->first && m1.size() == ft_m1.size() && m2.size() && ft_m2.size();

        EQUAL(cond);
}
