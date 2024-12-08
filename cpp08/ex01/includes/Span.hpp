/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 14:52:59 by rmatsuba          #+#    #+#             */
/*   Updated: 2024/12/06 19:40:24 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iterator>
# include <string>
# include <vector>

class Span {
	private:
		unsigned int m_max_size;
		std::vector<int> *m_array;
		Span();
	public:
		Span(unsigned int n);
		~Span();
		Span(const Span &copy);
		Span &operator=(const Span &copy);
		void addNumber(int num);
		void addMultipleNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		unsigned int shortestSpan();
		unsigned int longestSpan();
		std::vector<int>& getArray() const;
};

#endif
