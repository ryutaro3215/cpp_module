/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 12:46:50 by rmatsuba          #+#    #+#             */
/*   Updated: 2024/09/25 16:57:22 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_crap_name"), ScavTrap(name), FragTrap(name), _name(name) {
	std::cout << "DiamondTrap constructor called" << std::endl;
	setHitPoint(FragTrap::getHitPoint());
	setEnergyPoint(ScavTrap::getEnergyPoint());
	setAttackDamage(FragTrap::getAttackDamage());
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap destructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other), ScavTrap(other), FragTrap(other) {
	std::cout << "DiamondTrap copy constructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other) {
	std::cout << "DiamondTrap assignment operator called" << std::endl;
	if (this == &other)
		return *this;
	ClapTrap::operator=(other);
	FragTrap::operator=(other);
	ScavTrap::operator=(other);
	return *this;
}

void	DiamondTrap::attack(std::string const &target) {
	if (getHitPoint() == 0) {
		std::cout << getName() << " is already dead" << std::endl;
	}
	else if (getEnergyPoint() == 0) {
		std::cout << getName() << " is out of energy" << std::endl;
	}
	else {
		ScavTrap::attack(target);
	}
	return ;
}

void	DiamondTrap::whoAmI() {
	if (getHitPoint() == 0) {
		std::cout << getName() << " is already dead" << std::endl;
	}
	else if (getEnergyPoint() == 0) {
		std::cout << getName() << " is out of energy" << std::endl;
	}
	else {
		std::cout << "My name is " << getName() << " and my ClapTrap name is " 
			<< ClapTrap::getName() << std::endl;
	}
	return ;
}
