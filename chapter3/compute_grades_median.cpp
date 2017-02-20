// the same as compute_grades_mean, except the program computes the homework
// scores average using the median rather than the mean. This requires a
// slightly more complicated code.
#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>

// say what standard-library names we use
using std::cin; 	using std::cout;
using std::endl; 	using std::setprecision;
using std::string; 	using std::streamsize;
using std::vector;	using std::sort;

int main()
{
	// ask for and read student's name
	string name;
	cout << "Please enter your first name: ";
	cin >> name;
	cout << "Hello, " << name << "!" << endl;

	// ask for and read midterm and final grades
	cout << "Please enter your midterm and final exam grades: ";
	double midterm, final;
	cin >> midterm >> final;

	// ask for homework grades
	cout << "Enter all of your homework grades, "
			"followed by the end-of-file: ";

	// the vector in which we will store the homework grades;
	vector<double> homework_grades;

	double homework_grade;
	while (cin >> homework_grade)
	{
		homework_grades.push_back(homework_grade);
	}

	// calculate the size of the homework array
	typedef vector<double>::size_type vector_size;
	vector_size homework_vector_size = homework_grades.size();

	// check that there's information in the array
	if (homework_vector_size == 0)
	{
		cout << "ERROR: You must input at least one homework grade"
		<< endl;
		return 1;
	}

	// sort the homework_grades vector
	sort(homework_grades.begin(), homework_grades.end());

	// compute median
	// if the homework vector has an even amount of elements, add the two
	// middle elements together and divide by two. if the homework vector has
	// odd number of elements, select the middle element
	vector_size middle_index = homework_vector_size / 2;
	double homework_median = homework_vector_size % 2 == 0
							 ? (homework_grades[middle_index] +
							 homework_grades[middle_index - 1]) / 2
							 : homework_grades[middle_index];

	// calculate the final score
	// final is worth 40%, midterm is worth 20%,
	// and homework is worth 40%
	double final_grade = final * 0.4 + midterm * 0.2 + homework_median * 0.4;

	// write the result
	streamsize original_precision = cout.precision();
	cout << "Your final grade is " << setprecision(3)
		 << final_grade << setprecision(original_precision)
		 << endl; 

	return 0;
}
