/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 19:11:58 by rmatsuba          #+#    #+#             */
/*   Updated: 2024/07/05 00:06:19 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>

class	Fixed
{
	private:
		int	value;
		static const int frac_bits = 8;
	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed& other);
		Fixed& operator =(const Fixed& other);
		int		getRawBits() const;
		void	setRawBits(int const raw);
};

#endif
