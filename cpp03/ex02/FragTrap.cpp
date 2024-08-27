/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 18:26:39 by rmatsuba          #+#    #+#             */
/*   Updated: 2024/07/17 10:06:07 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "FragTrap.hpp"

FragTrap::FragTrap(std::string _name) : ClapTrap(_name)
{
	std::cout << "Parametar constructor called" << std::endl;
	this->_name = _name;
	this->_hit_point = 100;
	this->_energy_point = 100;
	this->_attack_damage = 30;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_name = other._name;
	this->_hit_point = other._hit_point;
	this->_energy_point = other._energy_point;
	this->_attack_damage = other._attack_damage;
}

FragTrap& FragTrap::operator=(const FragTrap &other)
{
	std::cout << "Assignation operator called" << std::endl;
	if (this == &other)
		return *this;
	this->_name = other._name;
	this->_hit_point = other._hit_point;
	this->_energy_point = other._energy_point;
	this->_attack_damage = other._attack_damage;
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "Destructor called" << std::endl;
}

void	FragTrap::attack(const std::string &target)
{
	if (this->_energy_point > 0 && this->_hit_point > 0)
	{
		std::cout << "FragTrap " << _name << " attacks " << target <<
			", causing " << _attack_damage << " points of damage!" << std::endl;
		_energy_point -= 1;
	}
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << _name << " high fives guys!" << std::endl;
}

