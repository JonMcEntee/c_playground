// 2-9. Write a program that asks the user to enter two numbers and tells
// the user which number is larger than the other.
#include <iostream>
#include <string>

// say what standard-library names we use
using std::cout;	using std::endl;
using std::cin;	

int main()
{
	// explain purpose of the program to user
	cout << "This program compares two integers and determines which "
	<< "is larger. To begin please enter the first number: ";

	// accept first value
	int first_number;
	if ((cin >> first_number) == false)
	{
		cout << "ERROR: You must input an integer" << endl;
		return 1;
	}

	// prompt user for second value
	cout << endl << "Please enter the second number: ";

	// accept second value
	int second_number;
	if ((cin >> second_number) == false)
	{
		cout << "ERROR: You must input an integer" << endl;
		return 1;
	}

	// put space between input line and the output
	cout << endl;

	// if the first number is greater than the second number produce an
	// output to that effect
	if (first_number > second_number)
	{
		cout << first_number << " is larger than " << second_number << "."
		<< endl;
	}
	// vice-versa
	else if (second_number > first_number)
	{
		cout << second_number << " is larger than " << first_number << "."
		<< endl;
	}
	// otherwise the numbers must be equal
	else if (first_number == second_number)
	{
		cout << first_number << " is equal to " << second_number << "."
		<< endl;
	}
	// if somehow the numbers are neither equal nor inequal, something has
	// gone horribly wrong.
	else
	{
		cout << "ERROR: cannot compare these two values" << endl;
		return 1;
	}

	return 0;
}
