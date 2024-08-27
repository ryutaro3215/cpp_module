/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 11:00:37 by rmatsuba          #+#    #+#             */
/*   Updated: 2024/07/17 11:25:45 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Animal.hpp"
# include "Dog.hpp"
# include "Cat.hpp"

int	main(void)
{
	const Animal* meta = new Animal();
	const Animal* pag = new Dog();
	const Animal* tom = new Cat();

	std::cout << meta->getType() << " " << std::endl;
	std::cout << pag->getType() << " " << std::endl;
	std::cout << tom->getType() << " " << std::endl;
	meta->makeSound();
	pag->makeSound();
	tom->makeSound();
	delete meta;
	delete pag;
	delete tom;
}
