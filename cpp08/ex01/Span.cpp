/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 14:53:08 by rmatsuba          #+#    #+#             */
/*   Updated: 2024/12/06 17:43:52 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <limits>
#include <stdexcept>
#include <vector>
#include <iostream>
#include <algorithm>

Span::Span() : m_max_size(0), m_array(new std::vector<int>(0)) {}

Span::Span(unsigned int n) : m_max_size(n), m_array(new std::vector<int>(0)) {}

Span::~Span() {
	delete m_array;
}

Span::Span(const Span &copy) {
	m_max_size = copy.m_max_size;
	m_array = new std::vector<int>(*copy.m_array);
}

Span &Span::operator=(const Span &copy) {
	if (this == &copy)
		return *this;
	m_max_size = copy.m_max_size;
	delete m_array;
	m_array = new std::vector<int>(*copy.m_array);
	return *this;
}

void Span::addNumber(int num) {
	if (m_max_size == m_array->size())
		throw std::runtime_error("Array is full.");
	m_array->push_back(num);
}

void Span::addMultipleNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
	if (m_max_size < m_array->size() + std::distance(begin, end))
		throw std::runtime_error("Array is full.");
	m_array->insert(m_array->end(), begin, end);
}

unsigned int Span::shortestSpan() {
	if (m_array->size() <= 1)
		throw std::runtime_error("Array is too short.");
	std::vector<int> sorted = this->getArray();
	std::sort(sorted.begin(), sorted.end());
	unsigned int min = std::numeric_limits<unsigned int>::max();
	for (size_t i = 0; i < sorted.size() - 1; i++) {
		unsigned int diff = sorted[i + 1] - sorted[i];
		if (diff < min)
			min = diff;
	}
	return min;
}

unsigned int Span::longestSpan() {
	if (m_array->size() <= 1)
		throw std::runtime_error("Array is too short.");
	std::vector<int> sorted = this->getArray();
	std::sort(sorted.begin(), sorted.end());
	unsigned int diff = sorted[sorted.size() - 1] - sorted[0];
	return diff;
}

std::vector<int>& Span::getArray() const {
	return *m_array;
}
