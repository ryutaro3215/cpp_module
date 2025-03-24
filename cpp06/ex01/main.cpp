/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 18:33:39 by rmatsuba          #+#    #+#             */
/*   Updated: 2025/02/12 12:32:36 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"

int main(void) {
	Data *data = new Data();
	uintptr_t raw;

	std::cout << "Data address: " << data << std::endl;
	raw = Serializer::serialize(data);
	std::cout << "serialized number: " << raw << std::endl;
	Data *deserialized = Serializer::deserialize(raw);
	std::cout << "deserialize address: " << deserialized 
		<< std::endl;
	Data *deserialized2 = Serializer::deserialize(raw);
	std::cout << "deserialize address: " << deserialized2 
		<< std::endl;
	uintptr_t raw2 = Serializer::serialize(deserialized);
	std::cout << "serialized number: " << raw2 << std::endl;
	delete data;
}
