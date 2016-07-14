#include "stdafx.h"
#include "Exercise4.h"
#include <iostream>
#include "InputOutputHandler.h"

void Exercise4::myInitialSolution()
{
	const int NUM_VALUES = 10;

	std::cout << "Enter " << NUM_VALUES << " numbers to calculate their sum\n";

	const IOHandler* ioHandler = new IOHandler();

	int sum = 0;
	int number;
	for (int k = 0; k < NUM_VALUES; k++)
	{
		do
		{
			std::cout << "Enter a number: ";
		} 
		while (!ioHandler->getNumberInput(number));

		sum += number;
	}

	std::cout << "The sum of these numbers is " << sum << std::endl;
	system("pause");
}

const std::vector<int> Exercise4::getNumbersFromUser(const int i_amount) const
{
	const IOHandler* ioHandler = new IOHandler();

	std::cout << "Enter " << i_amount << " numbers\n";

	int number;
	std::vector<int> numbers;
	numbers.reserve(i_amount);
	while ((int) numbers.size() < i_amount)
	{
		std::cout << "Enter a number: ";
		if (ioHandler->getNumberInput(number))
		{
			numbers.push_back(number);
		}
		else
		{
			std::cout << "Invalid input!\n";
		}
	}

	return numbers;
}

const int Exercise4::calculateSum(const std::vector<int> &i_numbers) const
{
	int sum = 0;
	for (std::vector<int>::const_iterator it = i_numbers.begin(), end = i_numbers.end(); it != end; it++)
	{
		sum += *it;
	}
	return sum;
}

void Exercise4::mySolution()
{
	const int NUM_VALUES = 10;
	const std::vector<int> numbers = getNumbersFromUser(NUM_VALUES);

	std::cout << "\n\nRESULT\n";
	const size_t size = numbers.size();
	for (size_t k = 0; k < size; k++)
	{
		if (k > 0)
		{
			std::cout << " + ";
		}
		std::cout << numbers[k];
	}

	const int sum = calculateSum(numbers);
	std::cout << " = " << sum << std::endl;
	system("pause");
}