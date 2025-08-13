/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 19:52:07 by rmatsuba          #+#    #+#             */
/*   Updated: 2024/11/29 16:56:06 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Inherited.hpp"
#include "Base.hpp"
#include <iostream>

int main(void) {
	Base *base = generate();
	identify(base);
	identify(*base);
	delete base;
	return 0;
}
