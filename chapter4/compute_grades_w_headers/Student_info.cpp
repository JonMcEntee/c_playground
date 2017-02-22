// source file for Student_info related functions
#include "Student_info.h"

using std::istream; using std::vector;

bool compare(const Student_info& x, const Student_info& y)
{
    return x.name < y.name;
}

// read homework grades from an input stream into a 'vector'
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
		in.clear();	
	}

	return in;
}

istream& read(istream& in, Student_info& student)
{
    // read and store the student's name and midterm/final scores
    in >> student.name >> student.final >> student.midterm;
	
	read_homework(in, student.homework);
    return in;
}