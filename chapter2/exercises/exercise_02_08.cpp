// 2-8. write a program to generate the product of the numbers in the
// range [1, 10) .
#include <iostream>

// standard library names to be used
using std::cout;	using std::endl;

int main()
{
	int sum = 0;

	// use a for loop to sum together integers in the range [1, 10)
	for (int i = 1; i < 10; ++i)
	{
		sum += i;
	}
	
	// output result
	cout << "The sum of the integers in range [1, 10) is: " << sum << endl;
	
	return 0;
}
