/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 10:56:39 by rmatsuba          #+#    #+#             */
/*   Updated: 2024/09/30 11:17:25 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>
#include <limits>

int main() {
	// DiamondTrap taro("taro");
	// DiamondTrap jiro("jiro");
	DiamondTrap saburo;
	DiamondTrap tmp;
	tmp = saburo;

	// taro.whoAmI();
	// saburo.whoAmI();
	tmp.whoAmI();
	return 0;
}
