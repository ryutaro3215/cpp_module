#include <iostream>

int	main(int argc, char **argv)
{
	int	i = 1;

	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	}
	while (i < argc)
	{
		std::cout << argv[i];
		i++;
	}
	std::cout << std::endl;
	return (0);
}
