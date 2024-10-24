/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryutaro320515 <marvin@42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:02:33 by ryutaro320515     #+#    #+#             */
/*   Updated: 2024/10/24 13:55:47 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Ice.hpp"
#include "includes/Cure.hpp"
#include "includes/Character.hpp"
#include "includes/MateriaSource.hpp"

int	main(void) {
	std::cout << "========== MateriaSource is made ==========" << std::endl;
	IMateriaSource *src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());

	std::cout << "========== Characters are made ==========" << std::endl;
	ICharacter *me = new Character("me");
	ICharacter *bob = new Character("bob");

	std::cout << "========== me is equipped some Materia ==========" << std::endl;
	AMateria *tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	std::cout << "========== bob is equipped some Materia ==========" << std::endl;
	bob->equip(src->createMateria("ice"));
	bob->equip(src->createMateria("cure"));

	std::cout << "========== me uses Materia on bob ==========" << std::endl;
	me->use(0, *bob);
	me->use(1, *bob);
	std::cout << "========== bob uses Materia on me ==========" << std::endl;
	/* bob->use(0, *me); */
	/* bob->use(1, *me); */

	delete bob;
	delete me;
	delete src;
	return 0;
}
