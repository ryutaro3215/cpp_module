#include "includes/PhoneBook.hpp"
#include "includes/Contact.hpp"

int main(void)
{
	std::string	input;
	PhoneBook	phonebook;

	while (true)
	{
		std::cout << "Enter a input: >> ";
		std::getline(std::cin, input);
		if (input == "EXIT")
			break ;
		else if (input == "ADD")
			phonebook.add_contact();
		else if (input == "SEARCH")
			phonebook.search_contact();
		else
			std::cout << "Invalid input, please input ADD or SEARCH or EXIT!!" << std::endl;
	}
	return (0);
}
