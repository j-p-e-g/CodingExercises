#include "stdafx.h"
#include "Exercise28.h"
#include <iostream>
#include <conio.h>

void Exercise28::mySolution()
{
	std::cout << "Enter a string: ";
	std::string inputString;
	std::cin >> inputString;
	std::cout << "Enter a character: ";
	const char ch = _getch();

	const int count = countNumberOfOccurencesInString(inputString, ch);
	std::cout << std::endl << inputString << " contains " << count << " occurences of " << ch << std::endl;

	system("pause");
}

int Exercise28::countNumberOfOccurencesInString(const std::string &i_string, const char i_char) const
{
	int count = 0;
	for (std::string::const_iterator it = i_string.begin(), end = i_string.end(); it != end; it++)
	{
		if (*it == i_char)
		{
			count++;
		}
	}
	return count;
}
