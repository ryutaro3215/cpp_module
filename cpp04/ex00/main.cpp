/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 12:15:59 by rmatsuba          #+#    #+#             */
/*   Updated: 2024/10/27 19:49:57 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Animal.hpp"
#include "includes/Dog.hpp"
#include "includes/Cat.hpp"
#include "includes/WrongAnimal.hpp"
#include "includes/WrongCat.hpp"

int main()
{
	std::cout << "======This is Animal test.======" << std::endl;
	{
		Animal animal;
		Dog dog;
		Cat cat;

		animal.makeSound();
		dog.makeSound();
		cat.makeSound();
		std::cout << "================================" << std::endl;
	}
 
	{
		const Animal *animal = new Animal();
		const Animal *dog = new Dog();
		const Animal *cat = new Cat();

		animal->makeSound();
		dog->makeSound();
		cat->makeSound();

		delete animal;
		delete dog;
		delete cat;
		std::cout << "================================" << std::endl;
	}

	{
		const WrongAnimal *meta = new WrongAnimal();
		const WrongAnimal *j = new WrongCat();
		std::cout << j->getType() << " " << std::endl;
		j->makeSound();
		meta->makeSound();
	
		delete meta;
		delete j;
		std::cout << "================================" << std::endl;
	}
}
