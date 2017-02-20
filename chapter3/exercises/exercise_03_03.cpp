// 3-3. Write a program to count how many times each distinct word appears
// in its input.
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

	// count the number of times each word appears
	vector<string> stored_words;
	vector<int> number_of_occurrences;
	for (int word = 0; word < input_amount; ++word)
	{
		//find size of stored_words vector
		vector_size words_vector_size = stored_words.size();

		// if the stored_words vector is empty, no use searching it
		if (words_vector_size == 0)
		{
			stored_words.push_back(input_string[word]);
			number_of_occurrences.push_back(1);
		}
		// otherwise check to see if the word in question has been
		// encountered before
		else
		{
			bool previously_encountered = false;
			for (int prev_word = 0; prev_word < words_vector_size; ++prev_word)
			{
				// if the word has been encountered before, increase
				// the counter on that word
				if (input_string[word] == stored_words[prev_word])
				{
					++number_of_occurrences[prev_word];
					previously_encountered = true;
					break;
				}
			}
			if (!previously_encountered)
			{
				stored_words.push_back(input_string[word]);
				number_of_occurrences.push_back(1);
			}
		}
	}
	
	// output results
	cout << "Results:" << endl;
	vector_size words_vector_size = stored_words.size();

	for (int word = 0; word < words_vector_size; ++word)
	{
		cout << " - " << stored_words[word] << ": "
		<< number_of_occurrences[word] << endl;
	}

	return 0;
}
