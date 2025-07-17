/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Inherited.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 19:41:56 by rmatsuba          #+#    #+#             */
/*   Updated: 2024/11/29 16:52:46 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INHERITED_HPP
# define INHERITED_HPP

#include "Base.hpp"
#include <string>
#include <typeinfo> 

class A : public Base {};
class B : public Base {};
class C : public Base {};

Base *generate(void);
void identify(Base *p);
void identify(Base &p);

#endif
