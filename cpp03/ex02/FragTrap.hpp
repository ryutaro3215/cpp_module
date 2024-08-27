/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 18:20:02 by rmatsuba          #+#    #+#             */
/*   Updated: 2024/07/15 18:29:07 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class	FragTrap : public ClapTrap
{
	public:
		FragTrap(std::string _name);
		FragTrap(const FragTrap &other);
		FragTrap &operator=(const FragTrap &other);
		~FragTrap();
		void	attack(const std::string &target);
		void	highFivesGuys(void);
};

#endif
