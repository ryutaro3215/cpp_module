/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 18:13:55 by rmatsuba          #+#    #+#             */
/*   Updated: 2024/06/29 20:08:50 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name), weapon(nullptr)
{
}

HumanB::HumanB(std::string name, Weapon &weapon) : name(name), weapon(&weapon)
{
}

HumanB::~HumanB()
{
}

void	HumanB::attack(void)
{
	if (this->weapon == nullptr)
	{
		std::cout << this->name << " has no weapon" << std::endl;
	}
	else
	{
		std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
	}
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}


