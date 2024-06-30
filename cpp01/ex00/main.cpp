/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 20:13:16 by rmatsuba          #+#    #+#             */
/*   Updated: 2024/06/27 00:03:20 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.hpp"

int	main(void)
{
	std::cout << "----These zombies are made by stack----" << std::endl;
	Zombie	zombie("Bob");
	randomChump("randomchump");
	std::cout << "----These zombies are made by head----" << std::endl;
	Zombie	*heapzombie;
	heapzombie = newZombie("heap");
	delete (heapzombie);
	return (0);
}
