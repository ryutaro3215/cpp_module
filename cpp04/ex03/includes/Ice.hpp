/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 19:54:34 by rmatsuba          #+#    #+#             */
/*   Updated: 2024/10/18 10:37:41 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria {
	public:
		Ice();
		Ice(const Ice &other);
		~Ice();
		Ice &operator=(const Ice &other);
		AMateria *clone() const;
		/* void use(ICharacter &target); */
};

#endif
