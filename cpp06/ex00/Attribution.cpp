/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Attribution.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:16:13 by rmatsuba          #+#    #+#             */
/*   Updated: 2024/11/26 11:15:22 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/Attribution.hpp"

Attribution::Attribution() {};

Attribution::~Attribution() {};

Attribution::Attribution(Attr attr) : m_attr(attr) {};

Attr Attribution::getAttrKind() const {
	return m_attr;
}

Attribution::Attribution(const Attribution &other) {
	*this = other;
}

Attribution &Attribution::operator=(const Attribution &other) {
	if (this == &other)
		return *this;
	m_attr = other.m_attr;
	return *this;
}


