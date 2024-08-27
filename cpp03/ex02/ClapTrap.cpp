/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 19:32:54 by rmatsuba          #+#    #+#             */
/*   Updated: 2024/07/10 17:15:04 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string _name)
{
	std::cout << "Parametar constructor called" << std::endl;
	this->_name = _name;
	this->_hit_point = 10;
	this->_energy_point = 10;
	this->_attack_damage = 0;
}

ClapTrap::~ClapTrap()
{
	std::cout	<< "Destructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	this->_name = other._name;
	this->_hit_point = other._hit_point;
	this->_energy_point = other._energy_point;
	this->_attack_damage = other._attack_damage;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap& other)
{
	if (this == &other)
		return (*this);
	this->_name = other._name;
	this->_hit_point = other._hit_point;
	this->_energy_point = other._energy_point;
	this->_attack_damage = other._attack_damage;
	return (*this);
}

void	ClapTrap::attack(const std::string &target)
{
	if (this->_energy_point == 0)
		std::cout << "energy point is zero." << std::endl;
	this->_energy_point--;
	std::cout << "ClapTrap " << this->_name << " attacks " << target << " , causing "
		<< this->_attack_damage << " points of damage" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (_hit_point == 0)
	{
		std::cout << this->_name << " is already dead" << std::endl;
		return ;
	}
	else
		this->_hit_point -= amount;
	std::cout << "ClapTrap " << this->_name <<  " taked " << amount << " damage, "
		<< this->_name << " has " << this->_hit_point <<  "now" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energy_point == 0)
	{
		std::cout << "energy point is zero." << std::endl;
		return ;
	}
	else
	{
		_energy_point--;
		_hit_point += amount;
		std::cout << this->_name << " repaired " << amount << " hit point." << std::endl;
	}
}
