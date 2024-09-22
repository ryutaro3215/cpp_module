/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 14:42:58 by rmatsuba          #+#    #+#             */
/*   Updated: 2024/09/20 16:22:20 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Harl.hpp"

Harl::Harl()
{

}

Harl::~Harl()
{

}

void	Harl::complain(std::string level)
{
	void	(Harl::*function[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string	level_list[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int	i = 0;

	while (i < 4)
	{
		if (level == level_list[i])
			break ;
		i++;
	}
	if (i == 4)
	{
		std::cout << "Invalid level" << std::endl;
		return ;
	}
	switch (i)
	{
		case 0:
			(this->*function[0])();
		case 1:
			(this->*function[1])();
		case 2:
			(this->*function[2])();
		case 3:
			(this->*function[3])();
	}
}

void	Harl::debug(void)
{
	std::cout << "this is debug" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "this is info" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "this is warning" << std::endl;
}

void	Harl::error(void)
{
	std::cout << "this is error" << std::endl;
}
