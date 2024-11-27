/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 18:41:40 by rmatsuba          #+#    #+#             */
/*   Updated: 2024/11/27 19:14:33 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

#include <string>

class Data {
	private:
		int m_number;
		std::string m_name;
	public:
		Data();
		~Data();
		Data(const Data &src);
		Data &operator=(const Data &src);
};

#endif

