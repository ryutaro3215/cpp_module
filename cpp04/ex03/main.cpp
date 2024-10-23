/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryutaro320515 <marvin@42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:02:33 by ryutaro320515     #+#    #+#             */
/*   Updated: 2024/10/23 12:23:35 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Ice.hpp"
#include "includes/Cure.hpp"
#include "includes/Character.hpp"

int	main(void) {
	AMateria *ice = new Ice();
	AMateria *cure = new Cure();
	Character *bob = new Character("Bob");
	/* AMateria tmp; */
	/* tmp = ice->clone(); */

	bob->equip(ice);
	bob->equip(cure);
	bob->equip(ice);
	bob->equip(cure);
	Character *tmp = new Character("tmp");
	tmp = bob;
	std::cout << "tmp name: " << tmp->getName() << std::endl;
	bob->use(0, *tmp);
	bob->unequip(0);
	tmp->use(0, *bob);
	/* (void)tmp; */
	/* std::cout << "Ice type: " << ice->getType() << std::endl; */
	/* std::cout << "Cure type: " << cure->getType() << std::endl; */
	/* std::cout << "Ice clone type: " << tmp->getType() << std::endl; */
}
