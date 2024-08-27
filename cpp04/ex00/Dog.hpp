/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 10:23:50 by rmatsuba          #+#    #+#             */
/*   Updated: 2024/07/17 10:35:47 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Animal.hpp"

class	Dog : public Animal
{
	public:
		Dog();
		~Dog();
		Dog(const Dog &other);
		Dog &operator=(const Dog &other);
		void	makeSound() const;
};
