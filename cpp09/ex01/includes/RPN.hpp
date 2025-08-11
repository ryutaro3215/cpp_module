#ifndef  RPN_HPP
# define RPN_HPP

#include <iostream>

typedef enum {
	NUM,
	OPR,
	ERR,
} type;

typedef enum {
	PLUS,
	MINUX,
	PROD,
	DIVI,
	EXCE,
} ope;

class rpn {
	private:
		std::stack<std::string> _stack;
		size_t _count;
	public:
		rpn();
		~rpn();
		rpn(const rpn& other);
		rpn &operator=(const rpn& other);
		std::string getElement(std::string& input);
		void calculate(std::string el);
		void execRPN(std::string input);
		type checkElType(std::string el);
		ope checkOperator(std::string op);
		size_t count_element(const std::string& input);
	class invalid_expression : public std::exception {
		public:
			virtual const char* what() const throw(); 
	};
	class invalid_argument : public std::exception {
		public:
			virtual const char* what() const throw(); 
	};
	class int_overflow : public std::exception {
		public:
			virtual const char* what() const throw(); 
	};
};



#endif
