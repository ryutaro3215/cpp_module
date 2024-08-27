/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 10:36:58 by rmatsuba          #+#    #+#             */
/*   Updated: 2024/07/17 11:26:30 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Animal.hpp"

class Cat : public Animal
{
	public:
		Cat();
		~Cat();
		Cat(const Cat &other);
		Cat &operator=(const Cat &other);
		void	makeSound() const;
};
