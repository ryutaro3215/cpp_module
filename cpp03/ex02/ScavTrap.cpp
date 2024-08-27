/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 17:17:49 by rmatsuba          #+#    #+#             */
/*   Updated: 2024/07/12 00:34:33 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

ScavTrap::ScavTrap(std::string _name) : ClapTrap(_name)
{
	std::cout << "ScavTrap " << _name << " created." << std::endl;
	_hit_point = 100;
	_energy_point = 50;
	_attack_damage = 20;
	_guard_gate = false;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << _name << " destoroyed." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	std::cout << "ScavTrap copy constructor  called." << std::endl;
	_name = other._name;
	_hit_point = other._hit_point;
	_energy_point = other._energy_point;
	_attack_damage = other._attack_damage;
	_guard_gate = other._guard_gate;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &other)
{
	std::cout << "ScavTrap copy assignment operator called." << std::endl;
	if (this == &other)
		return *this;
	_name = other._name;
	_hit_point = other._hit_point;
	_energy_point = other._energy_point;
	_attack_damage = other._attack_damage;
	_guard_gate = other._guard_gate;
	return *this;
}

void	ScavTrap::attack(const std::string &target)
{
	if (this->_energy_point > 0 && this->_hit_point > 0)
	{
		std::cout << "ScavTrap " << _name << " attacks " << target <<
			", causing " << _attack_damage << " points of damage!" << std::endl;
		_energy_point -= 1;
	}
	else if (this->_energy_point == 0)
		std::cout << "ScavTrap " << _name << " is out of energy." << std::endl;
	else
		std::cout << "ScavTrap " << _name << " is dead." << std::endl;
}

void	ScavTrap::guardGate()
{
	if (_guard_gate)
	{
		std::cout << "ScavTrap " << _name << " has already guarded the gate." << std::endl;
		return ;
	}
	_guard_gate = true;
	std::cout << "ScavTrap " << _name << " has guarded the gate." << std::endl;
}
