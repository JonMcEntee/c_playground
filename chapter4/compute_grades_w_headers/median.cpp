// source file for median function
#include <algorithm>    // to get declaration of sort
#include <stdexcept>    // to get declaration of domain_error
#include <vector>       // to get declaration of vector

using std::domain_error;    using std::sort;    using std::vector;

double median(vector<double> vec)
{
    // calculate the size of the vector
	typedef vector<double>::size_type vector_size;
	vector_size size = vec.size();

	// check that there's information in the vector. if not, throw a
	// domain error
	if (size == 0)
		throw domain_error("median of an empty vector");

	// sort the vector
	sort(vec.begin(), vec.end());

	// compute median
	// if the vector has an even amount of elements, add the two
	// middle elements together and divide by two. if the vector has
	// an odd number of elements, select the middle element
	vector_size mid = size / 2;
	return size % 2 == 0 ? (vec[mid] + vec[mid - 1]) / 2 : vec[mid];
}