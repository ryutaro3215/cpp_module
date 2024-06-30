/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 00:31:16 by rmatsuba          #+#    #+#             */
/*   Updated: 2024/06/27 20:21:58 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.hpp"

Zombie::Zombie()
{
}

Zombie::~Zombie()
{
}

void	Zombie::setName(std::string name)
{
	this->name = name;
}

void	Zombie::announce()
{
		std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
