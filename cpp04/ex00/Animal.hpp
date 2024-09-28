/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 10:58:50 by rmatsuba          #+#    #+#             */
/*   Updated: 2024/09/28 19:45:22 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class	Animal
{
	protected:
		std::string _type;
	public:
		Animal();
		~Animal();
		Animal(const Animal &other);
		Animal &operator=(const Animal &other);
		void	setType(std::string type);
		std::string getType() const;
		virtual void	makeSound() const;
};

#endif