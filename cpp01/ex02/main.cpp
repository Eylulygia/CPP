#include <iostream>
#include <string>

#define YELLOW "\033[33m"
#define CYAN   "\033[36m"
#define RESET  "\033[0m"

int main(void)
{
	std::string originalString = "HI THIS IS BRAIN";

	std::string* stringPTR = &originalString;

	std::string& stringREF = originalString;

	std::cout << YELLOW << "--- MEMORY ADDRESSES ---" << RESET << std::endl;
	
	std::cout << "Address of variable:     " << &originalString << std::endl;

	std::cout << "Address held by PTR:     " << stringPTR << std::endl;

	std::cout << "Address held by REF:     " << &stringREF << std::endl;

	std::cout << "\n" << CYAN << "--- VALUES ---" << RESET << std::endl;

	std::cout << "Value of variable:       " << originalString << std::endl;

	std::cout << "Value pointed by PTR:    " << *stringPTR << std::endl;

	std::cout << "Value pointed by REF:    " << stringREF << std::endl;

	return (0);
}
