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
	
	// the amount of spaces padding the greeting message
	const int pad = 1;

	// the amount of rows is based on the padding
	const int rows = pad * 2 + 3;

	// the amount of columns
	// length of greeting plus padding and asterisks on both sides
	const std::string::size_type columns = greeting.size() + pad * 2 + 2;

	// seperate output from input
	std::cout << std::endl;

	// write rows
	int row = 0;

	// invariant: we have written row rows so far
	while(row < rows)
	{
		// write columns
		std::string::size_type column = 0;

		// invariant: we have written column columns so far
		while(column < columns)
		{
			// put asterisks on the border of the greeting
			if(row == 0 || row == rows - 1 || 
			column == 0 || column == columns - 1)
			{
				std::cout << "*";
				++column;
			}
			// write the greeting
			else if (row == pad + 1 && column == pad + 1)
			{
				std::cout << greeting;
				column += greeting.size();
			}
			else
			{
				std::cout << " ";
				++column;
			}
		}
		// move to next line
		std::cout << std::endl;
		++row;
	}

	return 0;
}
