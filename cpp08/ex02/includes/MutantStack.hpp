/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 11:11:57 by rmatsuba          #+#    #+#             */
/*   Updated: 2024/12/08 17:54:28 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {
	public:
		//detects the container type of the stack
		typedef typename std::stack<T, Container>::container_type container_type;
		//iterator type of the container
		typedef typename container_type::iterator iterator;
		typedef typename container_type::reverse_iterator reverse_iterator;
		MutantStack();
		~MutantStack();
		MutantStack(const MutantStack &other);
		MutantStack &operator=(const MutantStack &other);
		iterator begin();
		iterator end();
		reverse_iterator rbegin();
		reverse_iterator rend();
};

#include "../MutantStack.tpp"

#endif
