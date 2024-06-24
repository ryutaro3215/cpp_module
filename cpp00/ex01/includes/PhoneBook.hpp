#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <ios>
#include <iomanip>
#include <string>
#include "Contact.hpp"

class	PhoneBook
{
	private:
		Contact	contact[8];
		int	contact_number;
		int	index_ptr;
	public:
		PhoneBook();
		void	add_contact();
		void	search_contact();
};

#endif

