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
	std::cout << "success add_contact!!" << std::endl;
}

void	PhoneBook::print_contact()
{
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
}

void	PhoneBook::search_contact()
{
	int	index_input;
	if (contact_number == 0)
	{
		std::cout << "No contact to search" << std::endl;
		return ;
	}
	print_contact();
	while (true)
	{
		std::cout << "Enter the index of the contact you want to search: >> ";
		std::cin >> index_input;
		if (std::cin.fail())
		{
			std::cout << "Invalid input, please input a number" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue ;
		}
		if (index_input > 0 && index_input <= contact_number && !std::cin.fail())
		{
			Contact& current_contact = contact[index_input - 1];
			std::cout << "Firstname: " << current_contact.get_firstname() << std::endl; 
			std::cout << "Lastname: " << current_contact.get_lastname() << std::endl;
			std::cout << "Nickname: " << current_contact.get_nickname() << std::endl;
			std::cout << "Phonenumber: " << current_contact.get_phonenumber() << std::endl;
			std::cout << "Darkest Secret: " << current_contact.get_darkestsecret() << std::endl;
			break ;
		}
		else
		{
			std::cout << "Invalid index, please input between 1 to " << contact_number << std::endl;
			continue ;
		}
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return ;
}
