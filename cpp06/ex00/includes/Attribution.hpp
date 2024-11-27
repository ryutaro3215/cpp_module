/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Attribution.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 21:27:13 by rmatsuba          #+#    #+#             */
/*   Updated: 2024/11/27 15:57:46 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXCEPTION_CPP
#define EXCEPTION_CPP

#include <string>
enum Attr {
			CHAR,
			INT,
			FLOAT,
			DOUBLE,
			NANORINF,
			IMP,
			NUM,
	};

class Attribution {
	private:
		Attr m_attr;
	public:
		Attribution();
		Attribution(Attr errorkind);
		~Attribution();
		Attr getAttrKind() const;
		Attribution(const Attribution &other);
		Attribution &operator=(const Attribution &other);
};

#endif
