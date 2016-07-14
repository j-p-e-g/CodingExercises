#include "stdafx.h"
#include "NumberToEnglishConversionChallenge.h"
#include "InputOutputHandler.h"
#include <vector>
#include <iostream>

void NumberToEnglishConversionChallenge::mySolution()
{
	IOHandler* ioHandler = new IOHandler();
	int number;

	do
	{
		std::cout << "Enter a number: ";
	}
	while (!ioHandler->getNumberInput(number));

	std::cout << "That's " << describeNumber(number) << ".\n";
	system("pause");
}

std::string NumberToEnglishConversionChallenge::describeNumber(const int i_number) const
{
	return handleNegativeNumber(i_number);
}

std::string NumberToEnglishConversionChallenge::handleNegativeNumber(const int i_number) const
{
	if (i_number < 0)
	{
		return "minus " + getNumberDescription(-i_number);
	}
	return getNumberDescription(i_number);
}

std::string NumberToEnglishConversionChallenge::getNumberDescription(const int i_number) const
{
	const int millionBlock = i_number / 1000000;
	const int thousandBlock = (i_number % 1000000) / 1000;
	const int rest = i_number % 1000;

	std::string desc = "";
	if (millionBlock > 0)
	{
		desc = getTripleDigitDescription(millionBlock) + " million";
	}

	if (thousandBlock > 0)
	{
		const std::string thousandDesc = getTripleDigitDescription(thousandBlock) + " thousand";
		if (!desc.empty())
		{
			desc += " ";
		}
		desc += thousandDesc;
	}

	if (rest > 0 || desc.empty())
	{
		std::string restDesc = getTripleDigitDescription(rest);
		if (!desc.empty())
		{
			if (rest < 100)
			{
				desc += " and ";
			}
			else
			{
				desc += " ";
			}
		}
		desc += restDesc;
	}
	return desc;
}

std::string NumberToEnglishConversionChallenge::getTripleDigitDescription(const int i_number) const
{
	const int hundredDigit = i_number / 100;
	std::string desc = "";
	if (hundredDigit > 0)
	{
		desc = getSingleDigitDescription(hundredDigit) + " hundred";
	}

	const int rest = i_number % 100;
	if (rest > 0 || hundredDigit == 0)
	{
		const std::string doubleDigitDesc = getDoubleDigitDescription(rest);
		if (desc.empty())
		{
			return doubleDigitDesc;
		}
		else
		{
			if (rest / 10 == 0)
			{
				return desc + " and " + doubleDigitDesc;
			}
		}
		return desc + " " + doubleDigitDesc;
	}
	return desc;
}

std::string NumberToEnglishConversionChallenge::getDoubleDigitDescription(const int i_number) const
{
	const std::vector<std::string> teenDigitNames = { "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" };
	const std::vector<std::string> tenMultipleNames = { "", "ten", "twenty", "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninety" };

	if (i_number < 10)
	{
		return getSingleDigitDescription(i_number);
	}
	else if (i_number < 20)
	{
		return teenDigitNames[i_number - 10];
	}
	else if (i_number < 100)
	{
		const int tenIndex = i_number / 10;
		const int singleIndex = i_number % 10;
		if (singleIndex == 0)
		{
			return tenMultipleNames[tenIndex];
		}
		return tenMultipleNames[tenIndex] + "-" + getSingleDigitDescription(singleIndex);
	}
	return "";
}

std::string NumberToEnglishConversionChallenge::getSingleDigitDescription(const int i_number) const
{
	const std::vector<std::string> singleDigitNames = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

	if (i_number >= 0 && i_number < (int)singleDigitNames.size())
	{
		return singleDigitNames[i_number];
	}
	return "";
}

