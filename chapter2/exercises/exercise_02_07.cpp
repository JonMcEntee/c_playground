// 2-7. write a program to count down from 10 to -5 .
#include <iostream>

// functions that will be used
using std::cout;	using std::endl;

int main()
{
	// use a for loop to count down from [10, -5] (inclusive)
	// and output at each step
	for (int i = 10; i >= -5; --i)
	{
		cout << i << endl;
	}

	return 0;
}
