// 3-5. write a program that will keep track of grades for several students at
// once. The program could keep two vectors in sync: The first should hold the
// student's names, and the second the final grades that can be computed as
// input is read. For now, you should assume a fixed number of homework grades.
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>

// say what standard-library names we use
using std::cin; 	using std::cout;
using std::endl; 	using std::setprecision;
using std::string; 	using std::streamsize;
using std::vector;

int main()
{
	// create vectors for storing names and grades;
	vector<string> names_vector;
	vector<double> grades_vector;

	while (true)
	{
		// provide instructions for quitting the program
		cout << "Enter 'q' to quit" << endl;

		// provide instructions for printing contents of vectors
		cout << "Enter 'p' to print all stored grade data" << endl;

		// ask for and read student's name
		string name;
		cout << "Please enter your first name: ";
		cin >> name;

		// if 'q' is entered, quit the program
		if (name == "q")
		{
			cout << "Logging out..." << endl;
			break;
		}
		else if (name == "p")
		{
			// print data in the names and grades vectors
			if (names_vector.size() != 0)
			{
				// original precision of the cout stream
				streamsize original_precision = cout.precision();

				cout << "Grades:" << endl;
				for (int i = 0; i < names_vector.size(); ++i)
				{
					cout << " - " << names_vector[i] << ": "
					<< setprecision(3) << grades_vector[i]
					<< setprecision(original_precision) << endl;
				}
				// put some space between the last line and the
				// new user prompt
				cout << endl;
				continue;
			}
			// if there is no data, let the user know there is no data
			else if (names_vector.size() == 0)
			{
				cout << "No data to print" << endl;
				continue;
			}
			// if there is both data and no data, something has gone horribly
			// wrong
			else
			{
				cout << "ERROR: Cannot determine size of names vector."
				<< endl;
				return 1;
			}
		}

		// print a greeting
		cout << "Hello, " << name << "!" << endl;

		// produce variables for tracking the user's index in the
		// names and grades vectors
		vector<string>::size_type name_index;
		vector<double>::size_type grade_index;

		// check the names vector to see if user already has data stored
		bool prev_entry = false;
		for (int i = 0; i < names_vector.size(); ++i)
		{
			// if there's a previous entry, that's where we'll store the new
			// grade
			if (names_vector[i] == name)
			{
				prev_entry = true;
				name_index = i;
				grade_index = i;
				break;
			}
		}
		// otherwise create a new element in the vector
		if (prev_entry == false)
		{
			names_vector.push_back(name);
			grades_vector.push_back(0);

			// set the name index and grade index to the ends of the vectors
			name_index = names_vector.size() - 1;
			grade_index = name_index;
		}
		// ask for and read midterm and final grades
		cout << "Please enter your midterm and final exam grades: ";
		double midterm, final;
		cin >> midterm >> final;

		// the number of homework assignments to be graded
		const int num_of_grades = 3;

		// ask for homework grades
		cout << "Enter all " << num_of_grades << " of your homework grades"
		<< endl;

		// the sum of grades
		double sum = 0;

		double grade;
		for (int i = 0; i < num_of_grades; ++i)
		{
			cout << "Enter grade " << i + 1 << ": ";
			cin >> grade;
			sum += grade;
		}

		// calculate the final score
		// final is worth 40%, midterm is worth 20%,
		// and homework is worth 40%
		double final_grade = final * 0.4 + midterm * 0.2
							 + sum / num_of_grades * 0.4;

		// store the final grade in the grades vector
		grades_vector[grade_index] = final_grade;

		// write the result
		streamsize original_precision = cout.precision();
		cout << "Your final grade is " << setprecision(3)
			<< final_grade << setprecision(original_precision)
			<< endl;
	} 

	return 0;
}
