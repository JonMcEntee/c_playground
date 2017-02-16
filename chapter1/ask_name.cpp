// Ask for a person's name, then greet them.
// This program makes use of the cin operand and the string
// variable type.
#include <iostream>
#include <string>

int main()
{
	// ask for the person's name
	std::cout << "Please enter your first name: ";

	// read the name
	std::string name;	//declare a string variable
	std::cin >> name;	//pipes user input into variable

	// write a greeting
	std::cout << "Hello, " << name << "!" << std::endl;
	return 0;
}
