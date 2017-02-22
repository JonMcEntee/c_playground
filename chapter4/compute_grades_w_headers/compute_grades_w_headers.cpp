// a program that stores multiple grades for multiple students, but seperates
// its code into multiple files.
#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include "grade.h"
#include "Student_info.h"

using std::cin;             using std::setprecision;
using std::cout;            using std::sort;
using std::domain_error;    using std::streamsize;
using std::endl;            using std::string;
using std::max;             using std::vector;

int main()
{
    vector<Student_info> students;
    Student_info record;
    string::size_type maxlen = 0;   //keeps track of the longest name string

    // read and store all student data
    while (read(cin, record))
    {
        // find length of longest name
        maxlen = max(maxlen, record.name.size());
        students.push_back(record);
    }

    // alphabetize the student records
    sort(students.begin(), students.end(), compare);

    // write the names and grades
    for (vector<Student_info>::size_type i = 0;
    i < students.size(); ++i) {

        // write the name, padded on the right to maxlen + 1 characters
        cout << students[i].name
        << string(maxlen + 1 - students[i].name.size(), ' ');

        try {
            double final_grade = grade(students[i]);
            streamsize original_prec = cout.precision();
            cout << setprecision(3) << final_grade
            << setprecision(original_prec);
        } catch (domain_error caught_error)
        {
            cout << caught_error.what();
        }
        cout << endl;
    }

    return 0;
}