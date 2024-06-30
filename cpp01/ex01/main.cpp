/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 18:15:17 by rmatsuba          #+#    #+#             */
/*   Updated: 2024/06/27 20:44:02 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"


int	main(void)
{
	int	zombie_num = 0;
	std::string	zombie_name;
	Zombie	*zombie;

	std::cout << "Set zombie number and name!!" << std::endl;;
	std::cout << "put number of zombie: ";
	std::cin >> zombie_num;
	std::cout << "put name of zombie: ";
	std::cin >> zombie_name;
	zombie = zombieHorde(zombie_num, zombie_name);
	for (int i = 0; i < zombie_num; i++)
		zombie[i].announce();
	delete[] zombie;
	return (0);
}
