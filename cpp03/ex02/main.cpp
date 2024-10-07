/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 10:56:39 by rmatsuba          #+#    #+#             */
/*   Updated: 2024/10/07 15:59:03 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>
#include <limits>

int main() {
	FragTrap ft("FragTrap");
	FragTrap ft2("FragTrap2");
	FragTrap copy(ft);
	FragTrap assgin;
	assgin = ft;
  return 0;
}
