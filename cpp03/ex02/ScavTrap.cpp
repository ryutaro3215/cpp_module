/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 17:17:49 by rmatsuba          #+#    #+#             */
/*   Updated: 2024/09/25 00:07:24 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

ScavTrap::ScavTrap(std::string _name) : ClapTrap(_name), _guard_gate(false) {
	setHitPoint(100);
	setEnergyPoint(50);
	setAttackDamage(20);
	std::cout << "ScavTrap " << getName() << " created." << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << getName() << " destoroyed." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other) {
	std::cout << "ScavTrap copy constructor  called." << std::endl;
	setGuardGate(other._guard_gate);
}

ScavTrap& ScavTrap::operator=(const ScavTrap &other) {
	std::cout << "ScavTrap copy assignment operator called." << std::endl;
	if (this == &other)
		return *this;
	setName(other.getName());
	setHitPoint(other.getHitPoint());
	setEnergyPoint(other.getEnergyPoint());
	setAttackDamage(other.getAttackDamage());
	setGuardGate(other._guard_gate);
	return *this;
}

void	ScavTrap::attack(const std::string &target) {
	if (getEnergyPoint() > 0 && getHitPoint() > 0)
	{
		std::cout << "ScavTrap " << getName() << " attacks " << target <<
			", causing " << getAttackDamage() << " points of damage!" << std::endl;
		setEnergyPoint(getEnergyPoint() - 1);
	}
	else if (getEnergyPoint()== 0)
		std::cout << "ScavTrap " << getName()<< " is out of energy." << std::endl;
	else
		std::cout << "ScavTrap " << getName() << " is already dead. can't attack" << std::endl;
}

void	ScavTrap::guardGate() {
	if (getGuardGate())
	{
		std::cout << "ScavTrap " << getName() << " has already guarded the gate." << std::endl;
		return ;
	}
	setGuardGate(true);
	std::cout << "ScavTrap " << getName()<< " has guarded the gate." << std::endl;
}

void	ScavTrap::setGuardGate(bool guard_gate) {
	this->_guard_gate = guard_gate;
}

bool	ScavTrap::getGuardGate() const {
	return _guard_gate;
}

