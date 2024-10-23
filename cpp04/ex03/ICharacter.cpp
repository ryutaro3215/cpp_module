/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 14:55:23 by rmatsuba          #+#    #+#             */
/*   Updated: 2024/10/20 14:56:29 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ICharacter.hpp"

ICharacter::~ICharacter() {
	std::cout << "ICharacter destructor called" << std::endl;
}
