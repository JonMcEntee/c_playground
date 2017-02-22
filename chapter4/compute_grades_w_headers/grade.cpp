#include <stdexcept>
#include <vector>
#include "grade.h"
#include "median.h"
#include "Student_info.h"

using std::vector;  using std::domain_error;

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

// another overloaded function which works using the Student_info class
double grade(const Student_info& student)
{
    return grade(student.final, student.midterm, student.homework);
}