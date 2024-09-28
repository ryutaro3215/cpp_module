/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 16:09:51 by rmatsuba          #+#    #+#             */
/*   Updated: 2024/09/28 21:40:29 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Brain.hpp"

Brain::Brain() {
	std::cout << "Brain constructor called" << std::endl;
}

Brain::~Brain() {
	std::cout << "Brain destructo called" << std::endl;
}

Brain::Brain(const Brain &other) {
	std::cout << "Brain copy constructor called" << std::endl;
	for (int i = 0; i < 100; i++) {
		this->_ideas[i] = other._ideas[i];
	}
}

Brain &Brain::operator=(const Brain &other) {
	std::cout << "Brain assignment operator called" << std::endl;
	if (this == &other)
		return *this;
	for (int i = 0; i < 100; i++) {
		this->_ideas[i] = other._ideas[i];
	}
	return (*this);
}

void	Brain::setIdea(int index, std::string idea) {
	if (index < 0 || index >= 100) {
		std::cout << "Invalid index" << std::endl;
		return ;
	}
	this->_ideas[index] = idea;
}

std::string Brain::getIdea(int index) {
	if (index < 0 || index >= 100) {
		std::cout << "Invalid index" << std::endl;
	}
	else
		return this->_ideas[index];
	return "";
}
