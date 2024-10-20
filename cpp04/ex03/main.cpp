/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryutaro320515 <marvin@42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:02:33 by ryutaro320515     #+#    #+#             */
/*   Updated: 2024/10/18 11:42:53 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Ice.hpp"
#include "includes/Cure.hpp"

int	main(void) {
	AMateria *ice = new Ice();
	AMateria *cure = new Cure();
	/* AMateria tmp; */
	/* tmp = ice->clone(); */

	/* (void)tmp; */
	std::cout << "Ice type: " << ice->getType() << std::endl;
	std::cout << "Cure type: " << cure->getType() << std::endl;
	/* std::cout << "Ice clone type: " << tmp->getType() << std::endl; */
}
