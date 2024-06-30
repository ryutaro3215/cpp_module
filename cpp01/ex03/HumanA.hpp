/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 14:47:09 by rmatsuba          #+#    #+#             */
/*   Updated: 2024/06/29 19:03:47 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

class	HumanA
{
	private:
		std::string	name;
		Weapon&	weapon;
	public:
		HumanA(std::string name, Weapon &weapon);
		~HumanA();
		void	attack(void);
};

#endif
