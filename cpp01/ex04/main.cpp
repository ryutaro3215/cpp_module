/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 20:15:02 by rmatsuba          #+#    #+#             */
/*   Updated: 2024/06/30 00:54:09 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <sstream>
void	replace_string(std::string &str, std::string s1, std::string s2)
{
	size_t	pos = 0;

	while ((pos = str.find(s1, pos)) != std::string::npos)
	{
		str = str.substr(0, pos) + s2 + str.substr(pos + s1.length());
		pos += s2.length();
	}
}

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Usage: ./sed filename s1 s2" << std::endl;
		return (1);
	}
	std::ifstream ifs(argv[1]);
	std::ofstream ofs(argv[1] + std::string(".replace"));
	std::ostringstream oss;
	std::string str;

	oss << ifs.rdbuf();
	str = oss.str();
	replace_string(str, argv[2], argv[3]);
	ofs << str;
	return (0);
}
