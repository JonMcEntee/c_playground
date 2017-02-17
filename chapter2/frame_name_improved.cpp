// Ask for a person's name, then generate a framed greeting.
#include <iostream>
#include <string>

// say what standard-library names we use
using std::cout;	using std::endl;
using std::cin;		using std::string;

int main()
{
	// ask for the person's name
	cout << "Please enter your first name: ";

	// read the name
	string name;	//declare a string variable
	cin >> name;	//pipes user input into variable

	// build the message that we intend to write
	const string greeting = "Hello, " + name + "!";
	
	// the amount of spaces padding the greeting message
	const int pad = 1;

	// the amount of rows is based on the padding
	const int rows = pad * 2 + 3;

	// the amount of columns
	// length of greeting plus padding and asterisks on both sides
	const string::size_type columns = greeting.size() + pad * 2 + 2;

	// seperate output from input
	cout << endl;

	// write rows
	int row = 0;

	// invariant: we have written row rows so far
	while(row < rows)
	{
		// write columns
		string::size_type column = 0;

		// invariant: we have written column columns so far
		while(column < columns)
		{
			if (row == pad + 1 && column == pad + 1)
			{
				cout << greeting;
				column += greeting.size();
			}
			else
			{
				// put asterisks on the border of the greeting
				if(row == 0 || row == rows - 1 || 
				column == 0 || column == columns - 1)
				{
					cout << "*";
				}
				// write the greeting
				else
				{
					cout << " ";
				}
				// in all cases within this statement the column
				// iterates by one
				++column;
			}
		}
		// move to next line
		cout << endl;
		++row;
	}

	return 0;
}
