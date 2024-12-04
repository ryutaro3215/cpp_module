/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 17:34:42 by rmatsuba          #+#    #+#             */
/*   Updated: 2024/12/05 01:21:59 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
# define ARRAY_TPP

#include "Array.hpp"

template <typename T>
Array<T>::Array() : m_array(NULL), m_size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : m_array(new T[n]), m_size(n) {
}

template <typename T>
Array<T>::~Array() {
	delete[] m_array;
}

template <typename T>
Array<T>::Array(const Array &other) {
	m_array = new T[other.size()];
	for (size_t i = 0; i < other.size(); i++)
		m_array[i] = other.m_array[i];
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &other) {
	if (this == &other)
		return *this;
	delete[] m_array;
	for (size_t i = 0; i < other.size(); i++) {
		m_array[i] = other.m_array[i];
	}
	return *this;
}

template <typename T>
size_t Array<T>::size() const {
	return m_size;
}

template <typename T>
T &Array<T>::operator[](unsigned int index) {
	if (index >= size())
		throw std::out_of_range("Index out of range");
	return m_array[index];
}

template <typename T>
const T &Array<T>::operator[](unsigned int index) const {
	if (index >= size())
		throw std::out_of_range("Index out of range");
	return m_array[index];
}

template <typename T>
T &Array<T>::getArray(unsigned int index) {
	if (index >= size())
		throw std::out_of_range("Index out of range");
	return m_array[index];
}

template <typename T>
const T &Array<T>::getArray(unsigned int index) const {
	if (index >= size())
		throw std::out_of_range("Index out of range");
	return m_array[index];
}

/* template <typename T> */
/* std::ostream &operator<<(std::ostream &out, const T &array) { */
/* 	out << array.getArray(); */
/* } */

#endif
