/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Inherited.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 19:41:56 by rmatsuba          #+#    #+#             */
/*   Updated: 2024/11/27 20:15:57 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INHERITED_HPP
# define INHERITED_HPP

#include "Base.hpp"
#include <string>

class A : public Base {
	private:
		std::string m_name;
	public:
		const std::string &getName(void) const;
};
class B : public Base {
	private:
		std::string m_name;
	public:
		const std::string &getName(void) const;
};
class C : public Base {
	private:
		std::string m_name;
	public:
		const std::string &getName(void) const;
};

Inherited.cpp:16:4: error: 'A' is missing exception specification 'noexcept'
A::A() : m_name("A") {}
   ^
       noexcept
includes/Inherited.hpp:19:7: note: previous declaration is here
class A : public Base {
      ^
Inherited.cpp:20:4: error: 'B' is missing exception specification 'noexcept'
B::B() : m_name("B") {}
   ^
       noexcept
includes/Inherited.hpp:25:7: note: previous declaration is here
class B : public Base {
      ^
Inherited.cpp:25:4: error: 'C' is missing exception specification 'noexcept'
C::C() : m_name("C") {}
   ^
       noexcept
includes/Inherited.hpp:31:7: note: previous declaration is here
class C : public Base {
      ^
3 errors generated.
Base *generate(void);
void identify(Base *p);
void identify(Base &p);

#endif
