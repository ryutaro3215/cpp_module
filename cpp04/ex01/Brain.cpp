/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 19:52:49 by rmatsuba          #+#    #+#             */
/*   Updated: 2024/10/27 19:53:02 by rmatsuba         ###   ########.fr       */
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
		this->ideas_[i] = other.ideas_[i];
	}
}

Brain &Brain::operator=(const Brain &other) {
	std::cout << "Brain assignment operator called" << std::endl;
	if (this == &other)
		return *this;
	for (int i = 0; i < 100; i++) {
		this->ideas_[i] = other.ideas_[i];
	}
	return (*this);
}

void	Brain::setIdea(int index, std::string idea) {
	if (index < 0 || index >= 100) {
		std::cout << "Invalid index" << std::endl;
		return ;
	}
	this->ideas_[index] = idea;
}

std::string Brain::getIdea(int index) {
	if (index < 0 || index >= 100) {
		std::cout << "Invalid index" << std::endl;
	}
	else
		return this->ideas_[index];
	return "";
}
