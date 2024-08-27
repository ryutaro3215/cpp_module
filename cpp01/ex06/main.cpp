/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 16:20:51 by rmatsuba          #+#    #+#             */
/*   Updated: 2024/08/27 12:14:14 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Harl.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: Invalid number of arguments" << std::endl;
		return (1);
	}
	Harl harl;

	harl.complain(argv[1]);
	return (0);
}
