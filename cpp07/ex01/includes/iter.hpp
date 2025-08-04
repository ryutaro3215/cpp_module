/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:48:48 by rmatsuba          #+#    #+#             */
/*   Updated: 2024/12/04 17:03:05 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <cstddef>
#include <iostream>

template <typename T, typename F>
void iter(T *array, size_t length, F func) {
	for (size_t i = 0; i < length; i++) {
		func(array[i]);
	}
}

template <typename T>
void print(T const &x) {
	std::cout << x << std::endl;
}

#endif
