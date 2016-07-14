#pragma once
#include "stdafx.h"
#include <iostream>
#include <string>
#include <ctype.h>

class IOHandler
{
public:
	void askUserInput(const std::string i_message, std::string &o_input) const
	{
		std::cout << i_message;
		std::cin >> o_input;
	}

	bool getNumberInput(int &o_number) const
	{
		std::string input;
		std::cin >> input;
		if (isNumber(input))
		{
			o_number = atoi(input.c_str());
			return true;
		}
		return false;
	}

	bool isNumber(const std::string& i_string) const
	{
		bool first = true;
		for (std::string::const_iterator it = i_string.begin(), end = i_string.end(); it != end; it++)
		{
			// allow a minus sign at the start
			if (!isdigit(*it) && (!first || *it != '-'))
			{
				return false;
			}
			first = false;
		}

		return !i_string.empty();
	}
};