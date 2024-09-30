/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 00:13:27 by rmatsuba          #+#    #+#             */
/*   Updated: 2024/09/30 11:44:27 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
	setHitPoint(100);
	setEnergyPoint(100);
	setAttackDamage(30);
	std::cout << "FragTrap " << getName() << " created." << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	setHitPoint(100);
	setEnergyPoint(100);
	setAttackDamage(30);
	std::cout << "FragTrap " << getName() << " created." << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << getName() << " destroyed." << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other) {
	std::cout << "FragTrap " << getName() << " created." << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap &other) {
	std::cout << "FragTrap copy assignment operator called" << std::endl;
	if (this == &other)
		return *this;
	ClapTrap::operator=(other);
	return *this;
}

void	FragTrap::highFivesGuys(void) {
	if (getHitPoint() == 0) {
		std::cout << "FragTrap " << getName() << " is dead." << std::endl;
		return ;
	}
	else if (getEnergyPoint() == 0) {
		std::cout << "FragTrap " << getName() << " is out of energy." << std::endl;
		return ;
	}
	else {
		std::cout << "FragTrap " << getName() << " requests a high five." << std::endl;
		return ;
	}
}
