// computes a students grade using their midterm, final, and homework scores.
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>

// say what standard-library names we use
using std::cin; 	using std::cout;
using std::endl; 	using std::setprecision;
using std::string; 	using std::streamsize;

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

	// the number and sum of grades read so far;
	int count = 0;
	double sum = 0;

	// invariant:
	// we have read count grades so far, and
	// sum is the sum of the first count grades
	double homework_grade;
	while (cin >> homework_grade)
	{
		++count;
		sum += homework_grade;
	}		

	// calculate the final score
	// final is worth 40%, midterm is worth 20%,
	// and homework is worth 40%
	double final_grade = final * 0.4 + midterm * 0.2 + sum / count * 0.4;

	// write the result
	streamsize original_precision = cout.precision();
	cout << "Your final grade is " << setprecision(3)
		 << final_grade << setprecision(original_precision)
		 << endl; 

	return 0;
}
