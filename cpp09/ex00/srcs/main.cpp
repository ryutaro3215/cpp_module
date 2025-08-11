#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "Error: invalid argument number" << std::endl;
		return 0;
	}
	std::map<std::string, float> rate_data;
	try {
		rate_data = read_date_csv();
		printBitcoinAmount(argv[1],rate_data);
	} catch (std::exception &e) {
		std::cerr << "Error: could not open file" << std::endl;
	}
	return 0;
}
