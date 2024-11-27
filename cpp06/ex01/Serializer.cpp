/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 18:36:23 by rmatsuba          #+#    #+#             */
/*   Updated: 2024/11/27 19:18:07 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer() {}

Serializer::~Serializer() {}

Serializer::Serializer(const Serializer &src) {
	*this = src;
}

Serializer &Serializer::operator=(const Serializer &src) {
	(void)src;
	return (*this);
}

uintptr_t Serializer::serialize(Data *ptr) {
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data *Serializer::deserialize(uintptr_t raw) {
	return (reinterpret_cast<Data *>(raw));
}

