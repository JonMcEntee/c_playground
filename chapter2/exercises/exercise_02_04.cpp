// 2-4. The framing program writes the mostly blank lines that separate the
// borders from the greeting one character at a time. Change the program so 
// that it writes all the spaces needed in a single output expression.
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
			// if the row is the middle row (# pad + 1), the write the
			// greeting
			if (row == pad + 1 && column == pad + 1)
			{
				cout << greeting;
				column += greeting.size();
			}
			// put asterisks on the border of the greeting
			else if(row == 0 || row == rows - 1 || 
					column == 0 || column == columns - 1)
			{
				cout << "*";
				++column;
			}
			// if the row contains the greeting add a number of spaces
			// equal to the pad constant.
			else if (row == pad + 1)
			{
				const string spaces(pad, ' ');
				cout << spaces;
				column += pad;
			}
			// if the above conditions are not met, then this must be the
			// inner area of a blank row. insert a number of spaces equal
			// to columns - 2 (excluding the two asterisk columns).
			else
			{
				const string spaces(columns - 2, ' ');
				cout << spaces;
				column += columns - 2;
			}
		}
		// move to next line
		cout << endl;
		++row;
	}

	return 0;
}
