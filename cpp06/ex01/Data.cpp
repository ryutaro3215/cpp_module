/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 19:03:24 by rmatsuba          #+#    #+#             */
/*   Updated: 2024/11/27 19:18:43 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data() : m_number(0), m_name("Test") {}

Data::~Data() {}

Data::Data(const Data &src) {
	*this = src;
}

Data &Data::operator=(const Data &src) {
	if (this != &src) {
		this->m_number = src.m_number;
		this->m_name = src.m_name;
	}
	return (*this);
}
