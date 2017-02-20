// 3-2. write a program to compute and print the quartiles (that is, the
// quarter of the numbers with the largest values, the next highest quarter,
// and so on) of a set of integers.
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

// say what standard-library names we use
using std::cin; 	using std::cout;
using std::endl; 	using std::vector;
using std::string; 	using std::sort;

int main()
{
	// the vector in which we will store values;
	vector<double> dataset;

	// populate the dataset using a for loop
	for (int i = 0; i < 100; ++i)
	{
		// should produce values from 1 to 100
		dataset.push_back(i + 1);
	}

	// calculate the size of the homework array
	typedef vector<double>::size_type vector_size;
	vector_size dataset_vector_size = dataset.size();

	// sort the dataset vector
	sort(dataset.begin(), dataset.end());

	// ask for which quartile to output
	int quartile_input;
	cout << "Please input the quartile you wish to view (1: first quartile, "
	"2: second quartile, 3: third quartile, 4: fourth quartile): ";
	// check for correct input
	if ((cin >> quartile_input) == false
		|| quartile_input > 4
		|| quartile_input < 1)
	{
		cout << "ERROR: input must be an integer between 1 and 4" << endl;
		return 1;
	}

	// calculate quartile index
	const double quartile_fraction = quartile_input / 4.0;
	const int quartile_index = quartile_fraction * (dataset_vector_size - 1);

	// output result
	cout << quartile_fraction * 100 << "% of values are below " << 
	dataset[quartile_index] << endl;

	return 0;
}
