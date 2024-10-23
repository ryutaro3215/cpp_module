/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 19:21:52 by rmatsuba          #+#    #+#             */
/*   Updated: 2024/10/23 20:06:57 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : counter_(0) {
	std::cout << "MateriaSource default constructor called" << std::endl;
	for (int i = 0; i < 4; i++) {
		source_[i] = NULL;
	}
}

MateriaSource::MateriaSource(const MateriaSource &other) {
	std::cout << "MateriaSource copy constructor called" << std::endl;
	counter_ = other.counter_;
	for (int i = 0; i < other.counter_; i++) {
			source_[i] = other.source_[i]->clone();
		}
}

MateriaSource::~MateriaSource() {
	std::cout << "MateriaSource destructor called" << std::endl;
	for (int i = 0; i < counter_; i++) {
		if (source_[i] != NULL) {
			delete source_[i];
			source_[i] = NULL;
		}
	}
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other) {
	std::cout << "MateriaSource assignment operator called" << std::endl;
	if (this == &other)
		return *this;
	counter_ = other.counter_;
	for (int i = 0; i < other.counter_; i++) {
		source_[i] = other.source_[i]->clone();
	}
	return *this;
}

void	MateriaSource::learnMateria(AMateria *m) {
	if (m == NULL) {
		std::cout << "Invalid materia" << std::endl;
	}
	else if (counter_ >= 4) {
		std::cout << "MateriaSource is full" << std::endl;
	}
	else {
		source_[counter_] = m;
		counter_++;
		std::cout << "learning " << m->getType() << " materia" << std::endl;
	}
}

AMateria *MateriaSource::createMateria(std::string const &type) {
	for (int i = 0; i < counter_; i++) {
		if (source_[i]->getType() == type) {
			std::cout << "creating " << source_[i]->getType() << " materia" << std::endl;
			return source_[i]->clone();
		}
	}
	std::cout << "Materia " << type << " is not found" << std::endl;
	return NULL;
}

