// 0-2. write a program that, when run, writes "This (") is a quote, and this (\) is a backslash."
#include <iostream>

int main()
{
	//since the quote and backslash are special characters and must use the escape character '\'
	std::cout << "This (\") is a quote, and this (\\) is a backslash." << std::endl;
}
