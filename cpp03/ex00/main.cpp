/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 10:56:39 by rmatsuba          #+#    #+#             */
/*   Updated: 2024/07/08 23:48:44 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap taro("Taro");
	ClapTrap jiro("Jiro");

	taro.attack("Jiro");
	jiro.takeDamage(5);
	jiro.beRepaired(3);
	return (0);
}
