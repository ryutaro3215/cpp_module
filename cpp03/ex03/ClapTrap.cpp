/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 19:32:54 by rmatsuba          #+#    #+#             */
/*   Updated: 2024/09/25 00:06:19 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string _name) : _name(_name), _hit_point(10), _energy_point(10), _attack_damage(0) {
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout	<< "Destructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) {
	setName(other._name);
	setHitPoint(other._hit_point);
	setEnergyPoint(other._energy_point);
	setAttackDamage(other._attack_damage);
	std::cout << "Copy constructor called" << std::endl;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap& other) {
	std::cout << "Assignation operator called" << std::endl;
	if (this == &other)
		return (*this);
	setName(other._name);
	setHitPoint(other._hit_point);
	setEnergyPoint(other._energy_point);
	setAttackDamage(other._attack_damage);
	return (*this);
}

void	ClapTrap::attack(const std::string &target) {
	if (getHitPoint() == 0) {
		std::cout << getName() << " is already dead" << std::endl;
		return ;
	}
	else if (getEnergyPoint() == 0) {
		std::cout << "energy point is zero." << std::endl;
		return ;
	}
	else {
		setEnergyPoint(getEnergyPoint() - 1);
		std::cout << "ClapTrap " << getName() << " attacks " << target << " , causing "
			<< getAttackDamage() << " points of damage" << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (getHitPoint() == 0) {
		std::cout << getName() << " is already dead" << std::endl;
		return ;
	}
	else if (getHitPoint() < amount) {
		setHitPoint(0);
		std::cout << "ClapTrap " << getName() << " taked " << amount << " damage, "
			<< getName() << " has " << getHitPoint() <<  "now" << std::endl;
	}
	else {
		setHitPoint(getHitPoint() - amount);
		std::cout << "ClapTrap " << getName() <<  " taked " << amount << " damage, "
			<< getName() << " has " << getHitPoint() <<  "now" << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (getEnergyPoint() == 0)
	{
		std::cout << "energy point is zero." << std::endl;
		return ;
	}
	else
	{
		setEnergyPoint(getEnergyPoint() - 1);
		setHitPoint(getHitPoint() + amount);
		std::cout << getName() << " repaired " << amount << " hit point." << std::endl;
	}
}

void	ClapTrap::setName(std::string _name) {
	this->_name = _name;
}

void	ClapTrap::setHitPoint(unsigned int _hit_point) {
	this->_hit_point = _hit_point;
}

void	ClapTrap::setEnergyPoint(unsigned int _energy_point) {
	this->_energy_point = _energy_point;
}

void	ClapTrap::setAttackDamage(unsigned int _attack_damage) {
	this->_attack_damage = _attack_damage;
}

std::string	ClapTrap::getName() const {
	return (this->_name);
}

unsigned int	ClapTrap::getHitPoint() const {
	return (this->_hit_point);
}

unsigned int	ClapTrap::getEnergyPoint() const {
	return (this->_energy_point);
}

unsigned int	ClapTrap::getAttackDamage() const {
	return (this->_attack_damage);
}
