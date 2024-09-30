/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 19:23:09 by rmatsuba          #+#    #+#             */
/*   Updated: 2024/09/30 11:33:59 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap
{
	protected:
		std::string 	name_;
		unsigned int	hit_point_;
		unsigned int	energy_point_;
		unsigned int	attack_damage_;
	public:
		ClapTrap();
		ClapTrap(std::string name_);
		~ClapTrap();
		ClapTrap(const ClapTrap& other);
		ClapTrap& operator=(const ClapTrap& other);
		void	attack(const std::string &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		void	setName(std::string name);
		void	setHitPoint(unsigned int hit_point);
		void	setEnergyPoint(unsigned int energy_point);
		void	setAttackDamage(unsigned int attack_damage);
		std::string getName() const;
		unsigned int getHitPoint() const;
		unsigned int getEnergyPoint() const;
		unsigned int getAttackDamage() const;
};

#endif
