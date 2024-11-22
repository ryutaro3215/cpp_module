/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:32:42 by rmatsuba          #+#    #+#             */
/*   Updated: 2024/11/22 18:25:03 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ScalarConverter.hpp"
#include <iostream>


int main(int argc, char **argv)
{
	(void)argv;
	if (argc != 2)
	{
		std::cerr << "Error: Invalid number of arguments" << std::endl;
		return 1;
	}
	ScalarConverter::convert(argv[1]);
}
