/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 12:15:59 by rmatsuba          #+#    #+#             */
/*   Updated: 2024/10/27 20:11:03 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Animal.hpp"
#include "includes/Dog.hpp"
#include "includes/Cat.hpp"
#include "includes/WrongAnimal.hpp"
#include "includes/WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Cat *cat = new Cat();
	const Dog *dog = new Dog();

	meta->makeSound();
	cat->makeSound();
	dog->makeSound();
	cat->getBrain()->setIdea(0, "I am a cat");
	dog->getBrain()->setIdea(0, "I am a dog");
	cat->getBrain()->setIdea(1, "I am a cat2");
	dog->getBrain()->setIdea(1, "I am a dog2");
	std::cout << cat->getBrain()->getIdea(0) << std::endl;
	std::cout << dog->getBrain()->getIdea(0) << std::endl;
	std::cout << cat->getBrain()->getIdea(1) << std::endl;
	std::cout << dog->getBrain()->getIdea(1) << std::endl;
	delete meta;
	delete cat;
	delete dog;
	return 0;
}
