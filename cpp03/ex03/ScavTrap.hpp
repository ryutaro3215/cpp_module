/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 17:18:00 by rmatsuba          #+#    #+#             */
/*   Updated: 2024/09/25 16:13:48 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

class	ScavTrap : virtual public ClapTrap
{
	private:
		bool	_guard_gate;
	public:
		ScavTrap(std::string _name);
		~ScavTrap();
		ScavTrap(const ScavTrap &other);
		ScavTrap& operator=(const ScavTrap &other);
		void	attack(const std::string &target);
		void	guardGate();
		void	setGuardGate(bool guard_gate);
		bool	getGuardGate() const;
};
