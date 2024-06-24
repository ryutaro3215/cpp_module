#include "includes/PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	contact_number = 0;
	index_ptr = 0;
}

void	PhoneBook::add_contact()
{
	if (index_ptr == 8)
		index_ptr = 0;
	Contact& current_contact = contact[index_ptr];
	current_contact.add_firstname(current_contact);
	current_contact.add_lastname(current_contact);
	current_contact.add_nickname(current_contact);
	current_contact.add_phonenumber(current_contact);
	current_contact.add_darkestsecret(current_contact);
	if (contact_number < 8)
		contact_number++;
	index_ptr++;
	std::cout << index_ptr << std::endl;
	std::cout << "success add_contact!!" << std::endl;
}

void	PhoneBook::search_contact()
{
	if (contact_number == 0)
	{
		std::cout << "No contact available" << std::endl;
		return ;
	}
	std::cout << std::setw(45) << std::setfill('-') << '-' << std::endl;
	std::cout << "|     Index| Firstname|  Lastname|  Nickname|" << std::endl;
	for (int i = 0; i < contact_number; i++)
	{
		if (i >= 4)
			break ;
		Contact& current_contact = contact[i];
		std::cout << "|";
		std::cout << std::setw(10) << i + 1;
		std::cout << "|";
		std::cout << std::setw(10) << current_contact.get_firstname().substr(0, 10);
		std::cout << "|";
		std::cout << std::setw(10) << current_contact.get_lastname().substr(0, 10);
		std::cout << "|";
		std::cout << std::setw(10) << current_contact.get_nickname().substr(0, 10);
		std::cout << "|";
		std::cout << std::endl;
	}
	std::cout << std::setw(45) << std::setfill('-') << '-' << std::endl;
	return ;
}
