/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 11:51:37 by rmatsuba          #+#    #+#             */
/*   Updated: 2024/10/27 20:00:33 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
	private:
		Brain *brain_;
	public:
		Dog();
		~Dog();
		Dog(const Dog &other);
		Dog	&operator=(const Dog &other);
		void	makeSound() const;
		Brain *getBrain() const;
		void	setBrain(Brain *brain);
};

#endif
