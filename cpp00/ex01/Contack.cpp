#include "includes/Contact.hpp"
#include "includes/PhoneBook.hpp"

Contact::Contact()
{

}

void	Contact::add_firstname(Contact& current_contact)
{
	std::string	first_name;

	while (true)
	{
		std::cout << "Enter first name: ";
		std::getline(std::cin, first_name);
		if (std::cin.eof())
		{
			std::cout << "EOF detected. Exiting program..." << std::endl;
			std::exit(0);
		}
		if (first_name.empty())
			std::cout << "First name is empty. Please enter a valid first name." << std::endl;
		else
		{
			current_contact.firstname = first_name;
			break ;
		}
	}
}

void	Contact::add_lastname(Contact& current_contact)
{
	std::string	last_name;

	while (true)
	{
		std::cout << "Enter last name: ";
		std::getline(std::cin, last_name);
		if (std::cin.eof())
		{
			std::cout << "EOF detected. Exiting program..." << std::endl;
			std::exit(0);
		}
		if (last_name.empty())
			std::cout << "Last name is empty. Please enter a valid last name." << std::endl;
		else
		{
			current_contact.lastname = last_name;
			break ;
		}
	}
}

void	Contact::add_nickname(Contact& current_contact)
{
	std::string	nick_name;

	while (true)
	{
		std::cout << "Enter nickname: ";
		std::getline(std::cin, nick_name);
		if (std::cin.eof())
		{
			std::cout << "EOF detected. Exiting program..." << std::endl;
			std::exit(0);
		}
		if (nick_name.empty())
			std::cout << "Nickname is empty. Please enter a valid nickname." << std::endl;
		else
		{
			current_contact.nickname = nick_name;
			break ;
		}
	}
}

void	Contact::add_phonenumber(Contact& current_contact)
{
	std::string	phone_number;

	while (true)
	{
		std::cout << "Enter phone number: ";
		std::getline(std::cin, phone_number);
		if (std::cin.eof())
		{
			std::cout << "EOF detected. Exiting program..." << std::endl;
			std::exit(0);
		}
		if (phone_number.empty())
			std::cout << "Phone number is empty. Please enter a valid phone number." << std::endl;
		else
		{
			current_contact.phonenumber = phone_number;
			break ;
		}
	}
}

void	Contact::add_darkestsecret(Contact& current_contact)
{
	std::string	darkest_secret;

	while (true)
	{
		std::cout << "Enter darkestsecret: ";
		std::getline(std::cin, darkest_secret);
		if (std::cin.eof())
		{
			std::cout << "EOF detected. Exiting program..." << std::endl;
			std::exit(0);
		}
		if (darkest_secret.empty())
			std::cout << "Darkest secret is empty. Please enter a valid darkest secret." << std::endl;
		else
		{
			current_contact.darkestsecret = darkest_secret;
			break ;
		}
	}
}

std::string	Contact::get_firstname()
{
	return (firstname);
}

std::string	Contact::get_lastname()
{
	return (lastname);
}

std::string	Contact::get_nickname()
{
	return (nickname);
}

std::string	Contact::get_phonenumber()
{
	return (phonenumber);
}

std::string	Contact::get_darkestsecret()
{
	return (darkestsecret);
}
