/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 10:24:37 by rmatsuba          #+#    #+#             */
/*   Updated: 2024/10/23 12:32:10 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Character.hpp"
#include <iostream>

Character::Character() : name_("default") {
	std::cout << "Character default constructor called" << std::endl;
	for (int i = 0; i < 4; i++) {
		inventory_[i] = NULL;
		is_equipped_[i] = false;
	}
}

Character::Character(std::string name) : name_(name) {
	std::cout << "Character constructor called" << std::endl;
	for (int i = 0; i < 4; i++) {
		inventory_[i] = NULL;
		is_equipped_[i] = false;
	}
}

Character::Character(const Character &other) : name_(other.name_) {
	std::cout << "Character copy constructor called" << std::endl;
	for (int i = 0; i < 4; i++) {
		if (other.is_equipped_[i]) {
			inventory_[i] = other.inventory_[i]->clone();
			is_equipped_[i] = true;
		} else {
			inventory_[i] = NULL;
			is_equipped_[i] = false;
		}
	}
}

Character &Character::operator=(const Character &other) {
	std::cout << "Character assignment operator called" << std::endl;
	if (this == &other)
		return *this;
	name_ = other.getName();
	for (int i = 0; i < 4; i++) {
		AMateria *tmp = NULL;
		bool tmp_is_equipped = false;
		if (other.is_equipped_[i]) {
			tmp = other.inventory_[i]->clone();
			tmp_is_equipped = true;
			delete inventory_[i];
			is_equipped_[i] = false;
		} 
		inventory_[i] = tmp;
		is_equipped_[i] = tmp_is_equipped;
	}
	return *this;
}

Character::~Character() {
	std::cout << "Character destructor called" << std::endl;
	for (int i = 0; i < 4; i++) {
		if (inventory_[i] != NULL) {
			delete inventory_[i];
			inventory_[i] = NULL;
		}
	}
}

std::string const &Character::getName() const {
	return name_;
}

void	Character::equip(AMateria *m) {
	for (int i = 0; i < 4; i++) {
		if (!inventory_[i]) {
			std::cout << getName() << " equips " << m->getType()
				<< " materia" << std::endl; 
			inventory_[i] = m;
			is_equipped_[i] = true;
			break ;
		}
	}	
}

void	Character::unequip(int idx) {
	if (idx < 0 || idx >= 4) {
		std::cout << "Invalid index" << std::endl;
	}
	else if (!is_equipped_[idx]) {
		std::cout << "No materia equipped at this index"
			<< std::endl;
	}
	else {
		std::cout << getName() << " unequips "
			<< inventory_[idx]->getType() << " materia" << std::endl;  
		inventory_[idx] = NULL;
		is_equipped_[idx] = false;
	}
}

void	Character::use(int idx, ICharacter &target) {
	if (idx < 0 || idx >= 4) {
		std::cout << "Invalid index" << std::endl;
	}
	else if (!is_equipped_[idx]) {
		std::cout << getName() << "No materia equipped at this index"
			<< std::endl;
	} 
	else {
		std::cout << getName() << " uses "
			<< inventory_[idx]->getType()
			<< " materia on " << target.getName() << std::endl;
		inventory_[idx]->use(target);
	}
}


