#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iostream>
#include <limits>
#include <cstdlib>

class	Contact
{
	private:
		std::string	firstname;
		std::string	lastname;
		std::string	nickname;
		std::string	phonenumber;
		std::string	darkestsecret;
	public:
		Contact();
		void	add_firstname(Contact& current_contact);
		void	add_lastname(Contact& current_contact);
		void	add_nickname(Contact& current_contact);
		void	add_phonenumber(Contact& current_contact);
		void	add_darkestsecret(Contact& current_contact);
		std::string	get_firstname();
		std::string	get_lastname();
		std::string	get_nickname();
		std::string	get_phonenumber();
		std::string	get_darkestsecret();
};


#endif

