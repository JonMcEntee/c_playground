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

	// dimensions of rectangle
	const int rectangle_length = 40;
	const int rectangle_height = 10;

	// dimensions of triangle
	const int triangle_base = 31;

	// compensate for the way text is output in the terminal for square height
	const int square_height = square_size / 2;

	// output a square
	for (int row = 0; row < square_height; ++row)
	{
		// if this is the top or bottom row of the square, output a line of
		// asterisks
		if (row == 0 || row == square_height - 1)
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

	// seperate the square and the rectangle
	cout << endl;

	// output a rectangle
	for (int row = 0; row < rectangle_height; ++row)
	{
		// if this is the top or bottom row of the rectangle, output a line of
		// asterisks
		if (row == 0 || row == rectangle_height - 1)
		{
			const string output_string(rectangle_length, '*');
			cout << output_string;
		}
		// otherwise output a rectangle_length - 2 long string of spaces with
		// an asterisk on both ends
		else
		{
			string output_string(rectangle_length - 2, ' ');
			output_string = "*" + output_string + "*";
			cout << output_string;
		}
		// end line and move to the next loop
		cout << endl;
	}

	//seperate rectangle and triangle
	cout << endl;

	// since the top of the triangle should be one asterisk, situated
	// perfectly in the middle, the base of the triangle must have a length
	// that is an odd number. here we check to make sure the base is an odd
	// number.
	if (triangle_base % 2 == 0)
	{
		cout << 
		"ERROR: Triangle must have a base with an odd number as its length"
		<< endl;
		return 1;
	}

	// calculate triangle's height. the height must be a very specific number
	// to allow for smooth slopes made of asterisks.
	const int triangle_height = triangle_base / 2 + 1;

	// output a triangle
	for (int row = 0; row < triangle_height; ++row)
	{
		// if it's the tip of the triangle, place an asterisk in the center
		if (row == 0)
		{
			string output_string(triangle_base / 2, ' ');
			output_string = output_string + "*";
			cout << output_string;
		}
		// if it's the bottom of the triangle draw a line of asterisks
		else if (row == triangle_height - 1)
		{
			const string output_string(triangle_base, '*');
			cout << output_string;
		}
		// otherwise draw two appropriately spaced asterisks
		else
		{
			const string left_space_string(triangle_base / 2 - row, ' ');
			const string middle_space_string(row * 2 - 1, ' ');
			const string output_string = left_space_string + "*" +
										 middle_space_string + "*";
			cout << output_string;
		}
		// end line and move to the next loop
		cout << endl;
	}

	return 0;
}
