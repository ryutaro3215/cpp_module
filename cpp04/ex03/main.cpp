/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryutaro320515 <marvin@42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:02:33 by ryutaro320515     #+#    #+#             */
/*   Updated: 2024/10/23 20:07:56 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Ice.hpp"
#include "includes/Cure.hpp"
#include "includes/Character.hpp"
#include "includes/MateriaSource.hpp"

int	main(void) {
	Character me = Character("me");
	Character you = Character("you");
	Ice *ice = new Ice();
	/* Ice *ice2 = new Ice(); */
	Cure *cure = new Cure();
	/* Cure *cure2 = new Cure(); */
	AMateria *tmp;
	MateriaSource *src = new MateriaSource();

	src->learnMateria(ice);
	src->learnMateria(cure);
	tmp = src->createMateria("ice");
	me.equip(tmp);
	/* you.equip(cure2); */
	you.use(0, me);
	return 0;
}
