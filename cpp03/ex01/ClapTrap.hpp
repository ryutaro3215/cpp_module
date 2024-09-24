/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 19:23:09 by rmatsuba          #+#    #+#             */
/*   Updated: 2024/09/24 23:34:58 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap
{
	private:
		std::string 	_name;
		unsigned int	_hit_point;
		unsigned int	_energy_point;
		unsigned int	_attack_damage;
	public:
		ClapTrap();
		ClapTrap(std::string _name);
		~ClapTrap();
		ClapTrap(const ClapTrap& other);
		ClapTrap& operator=(const ClapTrap& other);
		void	attack(const std::string &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		void	setName(std::string _name);
		void	setHitPoint(unsigned int _hit_point);
		void	setEnergyPoint(unsigned int _energy_point);
		void	setAttackDamage(unsigned int _attack_damage);
		std::string getName() const;
		unsigned int getHitPoint() const;
		unsigned int getEnergyPoint() const;
		unsigned int getAttackDamage() const;
};

#endif
