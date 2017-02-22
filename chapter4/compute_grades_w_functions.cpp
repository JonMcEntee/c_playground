// The same program as compute_grades_median.cpp from chapter 3, but much of
// the code is now organized into functions.
#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

// say what standard-library names we use
using std::cin; 	using std::cout;
using std::endl; 	using std::setprecision;
using std::string; 	using std::streamsize;
using std::vector;	using std::sort;
using std::istream;	using std::domain_error;

double median(vector<double> vec)
{
	// calculate the size of the homework array
	typedef vector<double>::size_type vector_size;
	vector_size size = vec.size();

	// check that there's information in the array. if not, throw a
	// domain error
	if (size == 0)
		throw domain_error("median of an empty vector");

	// sort the vec vector
	sort(vec.begin(), vec.end());

	// compute median
	// if the homework vector has an even amount of elements, add the two
	// middle elements together and divide by two. if the homework vector has
	// odd number of elements, select the middle element
	vector_size mid = size / 2;
	return size % 2 == 0 ? (vec[mid] + vec[mid - 1]) / 2
											: vec[mid];
}

// calculate the final grade based on final, midterm and homework scores
double grade(double final, double midterm, double homework)
{
	return final * 0.4 + midterm * 0.2 + homework * 0.4;
}

// overloaded function for grading with a homework vector
// in this function the hw vector is a reference, saving the overhead of
// copying the vector into a new container
double grade(double final, double midterm, const vector<double>& homework)
{
	if (homework.size() == 0)
		throw domain_error("student has done no homework");
	return grade(final, midterm, median(homework));
}

// function for reading homework into the homework vector
// this function also contains a reference, but since it's not marked as
// a constant, the referenced vector can be directly modified
istream& read_homework(istream& in, vector<double>& homework)
{
	if (in)
	{
		// get rid of previous contents
		homework.clear();

		// read homework grades
		double grade;
		while (in >> grade)
			homework.push_back(grade);

		// clear the stream of errors so that the next grade can be input
		cin.clear();	
	}

	return in;
}

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
	vector<double> homework;

	// read homework grades into vector
	read_homework(cin, homework);

	try
	{
		// calculate the final score
		// final is worth 40%, midterm is worth 20%,
		// and homework is worth 40%
		double final_grade = grade(final, midterm, homework);

		// write the result
		streamsize original_precision = cout.precision();
		cout << "Your final grade is " << setprecision(3)
			<< final_grade << setprecision(original_precision)
			<< endl; 
	}
	catch (domain_error)
	{
		cout << "You must enter your grades. "
		"Please try again." << endl;
		return 1;
	}
	return 0;
}
