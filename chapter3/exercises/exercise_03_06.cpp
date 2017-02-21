// 3-6. The average-grade computation in §3.1/36 might divide by zero if the
// student didn't enter any grades. Division by zero is undefined in C++, which
// means that the implementation is permitted to do anything it likes. What
// does your C++ implementation do in this case? Rewrite the program so that
// its behavior does not depend on how the implementation treats division
// by zero

// NOTE: I solved this problem in the following way: if the user enters no
// homework grades, the final grade is simply calculated without homework
// included. So if there's no homework the final becomes 2/3rds of the grade
// and the midterm becomes 1/3rd of the grade. If the user enters homework
// grades, then the original ratios apply.
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
	double final_grade;
	if (count > 0)
	{
		final_grade = final * 0.4 + midterm * 0.2 + sum / count * 0.4;
	}
	else if (count == 0)
	{
		final_grade = final * 0.66 + midterm * 0.34;
	}
	else
	{
		cout << "ERROR: count variable must be assigned a non-negative integer"
		<< endl;
		return 1;
	}

	// write the result
	streamsize original_precision = cout.precision();
	cout << "Your final grade is " << setprecision(3)
		 << final_grade << setprecision(original_precision)
		 << endl; 

	return 0;
}
