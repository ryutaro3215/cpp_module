/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 19:54:34 by rmatsuba          #+#    #+#             */
/*   Updated: 2024/10/16 19:56:42 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria {
	public:
		Ice();
		Ice(const Ice &other);
		virtual ~Ice();
		Ice &operator=(const Ice &other);
		AMateria *clone() const;
		void use(ICharacter &target);
}

#endif
