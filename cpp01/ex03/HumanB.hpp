/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 18:00:12 by rmatsuba          #+#    #+#             */
/*   Updated: 2024/06/29 19:04:18 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

class	HumanB
{
	private:
		std::string	name;
		Weapon	*weapon;
	public:
		HumanB(std::string name, Weapon &weapon);
		HumanB(std::string name);
		~HumanB();
		void	attack(void);
		void	setWeapon(Weapon &weapon);
};

#endif
