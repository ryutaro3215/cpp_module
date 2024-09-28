/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 12:15:59 by rmatsuba          #+#    #+#             */
/*   Updated: 2024/09/28 21:58:13 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Animal.hpp"
#include "includes/Dog.hpp"
#include "includes/Cat.hpp"
#include "includes/WrongAnimal.hpp"
#include "includes/WrongCat.hpp"

int main() {
  {
	std::cout << "==========================TEST 0==========================" << std::endl;
	const Animal *animals[] = {
		new Dog(),
		new Dog(),
		new Dog(),
		new Dog(),
		new Cat(),
		new Cat(),
		new Cat(),
		new Cat(),
	};
	for (int i = 0; i < 8; ++i) {
	  std::cout << "Type: " << animals[i]->getType() << std::endl;
	  animals[i]->makeSound();
	  delete animals[i];
	}
  }
  {
	std::cout << "==========================TEST 1==========================" << std::endl;
	const Animal *animals[] = {
		new Animal(),
		new Dog(),
		new Cat()
	};
	for (int i = 0; i < 3; ++i) {
	  std::cout << "Type: " << animals[i]->getType() << std::endl;
	  animals[i]->makeSound();
	  delete animals[i];
	}
  }
  {
	std::cout << "==========================TEST 2==========================" << std::endl;
	const WrongAnimal *animals[] = {
		new WrongAnimal(),
		new WrongCat()
	};
	for (int i = 0; i < 2; ++i) {
	  std::cout << "Type: " << animals[i]->getType() << std::endl;
	  animals[i]->makeSound();
	  delete animals[i];
	}
	std::cout << "--------------------------DERIVED--------------------------" << std::endl;
	WrongCat *cat = new WrongCat;
	std::cout << "Type: " << cat->getType() << std::endl;
	cat->makeSound();
	delete cat;
  }
  {
	std::cout << std::endl;
	std::cout << "==========================SPECIAL MEMBER FUNCS==========================" << std::endl;
	{
	  std::cout << "--------------------------ANIMAL--------------------------" << std::endl;
	  Animal animal1;
	  Animal animal2(animal1);
	  animal1 = animal2;
	}
	{
	  std::cout << "--------------------------DOG--------------------------" << std::endl;
	  Dog dog1;
	  Dog dog2(dog1);
	  dog1 = dog2;
	}
	{
	  std::cout << "--------------------------CAT--------------------------" << std::endl;
	  Cat cat1;
	  Cat cat2(cat1);
	  cat1 = cat2;
	}
	{
	  std::cout << "--------------------------WRONG ANIMAL--------------------------" << std::endl;
	  WrongAnimal wrong_animal1;
	  WrongAnimal wrong_animal2(wrong_animal1);
	  wrong_animal1 = wrong_animal2;
	}
	{
	  std::cout << "--------------------------WRONG ANIMAL--------------------------" << std::endl;
	  WrongCat wrong_cat1;
	  WrongCat wrong_cat2(wrong_cat1);
	  wrong_cat1 = wrong_cat2;
	}
  }
  {
	std::cout << "==========================COPY==========================" << std::endl;
	{
	  std::cout << "--------------------------DOG--------------------------" << std::endl;
	  Dog *dog1 = new Dog();
	  dog1->getBrain()->setIdea(0, "HUNGRY!");
	  Dog *dog2 = new Dog(*dog1);
	  Dog dog3;
	  dog3 = *dog2;
	  try {
		std::cout << "Dog " << dog1->getBrain()->getIdea(0) << std::endl;
		std::cout << "Dog " << dog2->getBrain()->getIdea(1) << std::endl;
		std::cout << "Dog " << dog3.getBrain()->getIdea(2) << std::endl;
		std::cout << "Dog " << dog3.getBrain()->getIdea(-1) << std::endl;
	  } catch (std::out_of_range &e) {
		std::cerr << "Index out of range" << std::endl;
	  }
	  delete dog1;
	  delete dog2;
	}
	{
	  std::cout << "--------------------------CAT--------------------------" << std::endl;
	  Cat *cat1 = new Cat();
	  cat1->getBrain()->setIdea(0, "SLEEPY!");
	  Cat *cat2 = new Cat(*cat1);
	  Cat cat3;
	  cat3 = *cat2;
	  try {
		std::cout << "Cat " << cat1->getBrain()->getIdea(0) << std::endl;
		std::cout << "Cat " << cat2->getBrain()->getIdea(1) << std::endl;
		std::cout << "Cat " << cat3.getBrain()->getIdea(2) << std::endl;
		std::cout << "Cat " << cat3.getBrain()->getIdea(-1) << std::endl;
	  } catch (std::out_of_range &e) {
		std::cerr << "Index out of range" << std::endl;
	  }
	  delete cat1;
	  delete cat2;
	}
  }
  return (0);
}
