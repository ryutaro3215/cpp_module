/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:54:12 by rmatsuba          #+#    #+#             */
/*   Updated: 2024/12/04 17:09:39 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_HPP
# define TEST_HPP

#include <string>
#include <iostream>

class Test {
	private:
		int _value;
		std::string _name;
	public:
		Test();
		Test(int value, std::string name);
		~Test();
		Test(const Test &other);
		Test &operator=(const Test &other);
		int getValue() const;
		std::string getName() const;
};

std::ostream &operator<<(std::ostream &os, const Test &test);

#endif
