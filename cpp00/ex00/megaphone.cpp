#include <iostream>
#include <string>
#include <cctype>

int	main(int argc, char **argv)
{
	int	i = 1;
	std::string str;

	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	}
	while (i < argc)
	{
		str = argv[i];
		for (int j = 0; str[j]; j++)
		{
			str[j] = std::toupper(str[j]);
		}
		std::cout << str;
		i++;
	}
	std::cout << std::endl;
	return (0);
}
