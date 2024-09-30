/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 10:56:39 by rmatsuba          #+#    #+#             */
/*   Updated: 2024/09/29 14:44:56 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>
#include <limits>

int main() {
  {
	std::cout << std::endl;
	std::cout << "===========================NORMAL TEST===========================" << std::endl;
	std::cout << "===========================ATTACK===========================" << std::endl;
	FragTrap tmp("Taro");
	FragTrap frag_trap(tmp);
	frag_trap = tmp;
	frag_trap.attack("Jiro");
	frag_trap.attack("Saburo");
	std::cout << "===========================DAMAGE===========================" << std::endl;
	frag_trap.takeDamage(2);
	frag_trap.takeDamage(3);
	std::cout << "===========================REPAIR===========================" << std::endl;
	frag_trap.beRepaired(2);
	frag_trap.beRepaired(10);
	std::cout << "===========================HIGH FIVE GUYS===========================" << std::endl;
	frag_trap.highFivesGuys();
	frag_trap.highFivesGuys();
  }
  {
	std::cout << std::endl;
	std::cout << "===========================ENERGY TEST===========================" << std::endl;
	std::cout << "===========================ATTACK===========================" << std::endl;
	FragTrap frag_trap("Taro");
	for (int i = 0; i < 101; ++i) {
	  frag_trap.attack("Jiro");
	}
	std::cout << "===========================DAMAGE===========================" << std::endl;
	frag_trap.takeDamage(2);
	frag_trap.takeDamage(3);
	std::cout << "===========================REPAIR===========================" << std::endl;
	frag_trap.beRepaired(2);
	std::cout << "===========================HIGH FIVE GUYS===========================" << std::endl;
	frag_trap.highFivesGuys();
	frag_trap.highFivesGuys();
  }
  {
	std::cout << std::endl;
	std::cout << "===========================HP TEST1===========================" << std::endl;
	std::cout << "===========================ATTACK===========================" << std::endl;
	FragTrap frag_trap("Taro");
	std::cout << "===========================DAMAGE===========================" << std::endl;
	frag_trap.takeDamage(std::numeric_limits<unsigned int>::max());
	frag_trap.takeDamage(30);
	std::cout << "===========================REPAIR===========================" << std::endl;
	frag_trap.beRepaired(2);
	frag_trap.beRepaired(2);
	std::cout << "===========================HIGH FIVE GUYS===========================" << std::endl;
	frag_trap.highFivesGuys();
	frag_trap.highFivesGuys();
  }
  {
	std::cout << std::endl;
	std::cout << "===========================HP TEST2===========================" << std::endl;
	std::cout << "===========================ATTACK===========================" << std::endl;
	FragTrap frag_trap("Taro");
	std::cout << "===========================DAMAGE===========================" << std::endl;
	frag_trap.takeDamage(2);
	std::cout << "===========================REPAIR===========================" << std::endl;
	frag_trap.beRepaired(2);
	frag_trap.beRepaired(std::numeric_limits<unsigned int>::max());
	frag_trap.beRepaired(std::numeric_limits<unsigned int>::max());
	std::cout << "===========================HIGH FIVE GUYS===========================" << std::endl;
	frag_trap.highFivesGuys();
	frag_trap.highFivesGuys();
  }
  return 0;
}
