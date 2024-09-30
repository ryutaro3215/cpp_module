/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 19:32:54 by rmatsuba          #+#    #+#             */
/*   Updated: 2024/09/30 11:42:11 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name_("default"), hit_point_(10), energy_point_(10), attack_damage_(0) {
	std::cout << "ClapTrap Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name_(name), hit_point_(10), energy_point_(10), attack_damage_(0) {
	std::cout << "ClapTrap constructor called" << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout	<< "ClapTrap Destructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) {
	setName(other.name_);
	setHitPoint(other.hit_point_);
	setEnergyPoint(other.energy_point_);
	setAttackDamage(other.attack_damage_);
	std::cout << "ClapTrap Copy constructor called" << std::endl;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap& other) {
	std::cout << "ClapTrap Assignation operator called" << std::endl;
	if (this == &other)
		return (*this);
	setName(other.name_);
	setHitPoint(other.hit_point_);
	setEnergyPoint(other.energy_point_);
	setAttackDamage(other.attack_damage_);
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

void	ClapTrap::setName(std::string name) {
	this->name_ = name;
}

void	ClapTrap::setHitPoint(unsigned int hit_point) {
	this->hit_point_ = hit_point;
}

void	ClapTrap::setEnergyPoint(unsigned int energy_point) {
	this->energy_point_ = energy_point;
}

void	ClapTrap::setAttackDamage(unsigned int attack_damage) {
	this->attack_damage_ = attack_damage;
}

std::string	ClapTrap::getName() const {
	return (this->name_);
}

unsigned int	ClapTrap::getHitPoint() const {
	return (this->hit_point_);
}

unsigned int	ClapTrap::getEnergyPoint() const {
	return (this->energy_point_);
}

unsigned int	ClapTrap::getAttackDamage() const {
	return (this->attack_damage_);
}
