/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 12:15:59 by rmatsuba          #+#    #+#             */
/*   Updated: 2024/10/01 19:13:12 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Animal.hpp"
#include "includes/Dog.hpp"
#include "includes/Cat.hpp"
#include "includes/WrongAnimal.hpp"
#include "includes/WrongCat.hpp"

int main() {

	Dog dog = Dog();
	Cat cat = Cat();

	for (int i = 0; i < 100; i++) {
		dog.getBrain()->setIdea(i, "I'm a " + std::to_string(i) + " dog");
		std::cout << dog.getBrain()->getIdea(i) << std::endl;
	}
	std::cout << dog.getBrain()->getIdea(100) << std::endl;
	// cat.getBrain()->setIdea(0, "I'm a cat");
	// std::cout << cat.getBrain()->getIdea(0) << std::endl;
	return (0);
}
