// 2-5. write a set of "*" characters so that they form a square, a rectangle,
// and a triangle.
#include <iostream>
#include <string>

// say what standard-library names we use
using std::cout;	using std::endl;
using std::cin;		using std::string;

int main()
{
	// put an empty line between the terminal prompt and the shapes
	cout << endl;

	// size of square (side length)
	const int square_size = 20;

	// output a square
	for (int row = 0; row < square_size; ++row)
	{
		// if this is the top or bottom row of the square, output a line of
		// asterisks
		if (row == 0 || row == square_size - 1)
		{
			const string output_string(square_size, '*');
			cout << output_string;
		}
		// otherwise output a square_size - 2 long string of spaces with an
		// asterisk on both ends
		else
		{
			string output_string(square_size - 2, ' ');
			output_string = "*" + output_string + "*";
			cout << output_string;
		}
		// end line and move to the next loop
		cout << endl;
	}

	return 0;
}
