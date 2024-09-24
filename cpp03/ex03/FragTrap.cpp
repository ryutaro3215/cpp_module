/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 00:13:27 by rmatsuba          #+#    #+#             */
/*   Updated: 2024/09/25 00:22:24 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string _name) : ClapTrap(_name) {
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
	if (this == &other)
		return *this;
	ClapTrap::operator=(other);
	return *this;
}

void	FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap " << getName() << " requests a high five." << std::endl;
}
