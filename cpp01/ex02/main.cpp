/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 20:54:20 by rmatsuba          #+#    #+#             */
/*   Updated: 2024/06/27 21:03:10 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>


int	main(void)
{
	std::string	brain = "HI THIS IS BRAIN";
	std::string	*stringPTR = &brain;
	std::string &stringREF = brain;

	std::cout << "-----address-----" << std::endl;
	std::cout << "The memory address of the string valiables is " << &brain << std::endl;
	std::cout << "The memory address held by stringPTR is " << stringPTR << std::endl;
	std::cout << "The memory address held by stringREF is " << &stringREF << std::endl;
	std::cout << "-----value-----" << std::endl;
	std::cout << "Brain value is " << brain << std::endl;
	std::cout << "The value pointed by stringPTR is " << brain << std::endl;
	std::cout << "Brain value pointed by stringREF is " << brain << std::endl;
}
