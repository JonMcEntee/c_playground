// Ask for a person's name, then generate a framed greeting.
#include <iostream>
#include <string>

int main()
{
	// ask for the person's name
	std::cout << "Please enter your first name: ";

	// read the name
	std::string name;	//declare a string variable
	std::cin >> name;	//pipes user input into variable

	// build the message that we intend to write
	const std::string greeting = "Hello, " + name + "!";
	const std::string starred_greeting = "*  " + greeting + "  *";
	
	// build the second and fourth lines of output
	const std::string spaces(greeting.size(), ' ');
	const std::string second = "*  " + spaces + "  *";

	// build the first and fifth lines of output
	const std::string first(second.size(), '*');

	// write
	std::cout << std::endl;
	std::cout << first << std::endl;
	std::cout << second << std::endl;
	std::cout << starred_greeting << std::endl;
	std::cout << second << std::endl;
	std::cout << first << std::endl;

	return 0;
}
