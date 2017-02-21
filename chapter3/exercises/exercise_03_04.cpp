// 3-4. write a program to report the length of the longest and shortest
// string in its input.
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

// say what standard-library names we use
using std::cin; 	using std::cout;
using std::endl; 	using std::vector;
using std::string; 	using std::sort;


int main()
{
	// prompt user to input a string
	vector<string> input_string;
	string input_word;
	cout << "Type a string to be analyzed, and press the end of file key on "
	"the next line: ";
	while (cin >> input_word)
	{
		input_string.push_back(input_word);
	}

	// find the size of the inputted vector
	typedef vector<string>::size_type vector_size;
	vector_size input_amount = input_string.size();

	// find the shortest and longest strings;
	string longest_string = input_string[0];
	string shortest_string = input_string[0];
	for (int word = 1; word < input_amount; ++word)
	{
		if (input_string[word].size() > longest_string.size())
		{
			longest_string = input_string[word];
		}
		if (input_string[word].size() < shortest_string.size())
		{
			shortest_string = input_string[word];
		}
	}
	
	// output results
	cout << "The longest word in the string is \"" << longest_string
	<< "\" and the shortest word in the string is \"" << shortest_string
	<< "\"." << endl;

	return 0;
}