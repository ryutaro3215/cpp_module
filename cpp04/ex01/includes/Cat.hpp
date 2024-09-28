/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 11:27:07 by rmatsuba          #+#    #+#             */
/*   Updated: 2024/09/28 21:08:14 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal {
	private:
		Brain *_brain;
	public:
		Cat();
		~Cat();
		Cat(const Cat &other);
		Cat &operator=(const Cat &other);
		void	makeSound() const;
		Brain *getBrain() const;
		void	setBrain(Brain *brain);
};

#endif
