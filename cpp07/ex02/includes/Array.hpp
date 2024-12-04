/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 17:34:19 by rmatsuba          #+#    #+#             */
/*   Updated: 2024/12/04 23:50:52 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <stdexcept>

template <typename T>
class Array {
	private:
		T *m_array;
		size_t m_size;
	public:
		Array();
		Array(unsigned int n);
		~Array();
		Array(const Array &other);
		Array &operator=(const Array &other);
		T &operator[](unsigned int index);
		const T &operator[](unsigned int index) const;
		size_t size() const;
		T &getArray(unsigned int index);
		const T &getArray(unsigned int index) const;
};

#include "../Array.tpp"
/* std::ostream &operator<<(std::ostream &out, const Array<T> &array); */

#endif

