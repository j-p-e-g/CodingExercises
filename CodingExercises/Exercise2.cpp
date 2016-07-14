#include "stdafx.h"
#include "Exercise2.h"
#include "InputOutputHandler.h"
#include <iostream>
#include <string>
#include <vector>

void Exercise2::fail1()
{
	int a = 8;
	int number;
	std::cout << "Enter all the numbers from 8 - 23.\n";
	for (; a < 24;)
	{
		std::cin >> number;
		if (number == a)
		{
			a++;
			std::cout << "Next number:\n";
		}
		else
			std::cout << "?";
	}
}

void Exercise2::fail2()
{
	std::cout << "Insert numbers from 8 to 23, both included.\n";
	for (int i = 8; i <= 23; ++i) {
		std::string suffix;
		if (i == 8)
			suffix.assign("st");
		else if (i == 9)
			suffix.assign("nd");
		else if (i == 10)
			suffix.assign("rd");
		else
			suffix.assign("th");

		std::cout << "Insert the " << i - 7 << suffix << " number.\n";
		int inp;
		std::cin >> inp;
		if (inp != i) {
			do {
				std::cout << "Wrong answer, you must enter: " << i << "\n";
				std::cin >> inp;
			} while (inp != i);
		}
		else {}
	}
	std::cout << "You did it!\n";
	system("pause");
}

void Exercise2::mySolution()
{
	const int FIRST_VALUE = 8;
	const int LAST_VALUE = 23;

	IOHandler* ioHandler = new IOHandler();

	std::cout << "Please enter the numbers between " << FIRST_VALUE << " and " << LAST_VALUE << " (inclusive)\n\n";

	int number;
	for (int k = FIRST_VALUE; k <= LAST_VALUE; k++)
	{
		do
		{
			std::cout << "Enter " << k << std::endl;
		}
		while (!ioHandler->getNumberInput(number) || number != k);
	}
	std::cout << "Well done!\n";
	system("pause");
}

void Exercise2::mySolutionImprovedUI()
{
	const int FIRST_VALUE = 8;
	const int LAST_VALUE = 23;
	const int SIZE = LAST_VALUE - FIRST_VALUE + 1;

	// init array
	int fullRange[SIZE];
	for (int k = 0; k < SIZE; k++)
	{
		fullRange[k] = FIRST_VALUE + k;
	}

	IOHandler* ioHandler = new IOHandler();

	int remainingNumbers = SIZE;
	while (remainingNumbers > 0)
	{
		std::cout << "Enter these numbers:\n";
		for (int k = 0; k < SIZE; k++)
		{
			if (fullRange[k] == 0)
			{
				std::cout << "   \t";
			}
			else
			{
				std::cout << fullRange[k] << "\t";
			}
		}
		std::cout << "\n";

		int number;
		if (ioHandler->getNumberInput(number))
		{
			const int index = number - 8;
			if (index >= 0 && index < SIZE)
			{
				if (fullRange[index] > 0)
				{
					fullRange[index] = 0;
					remainingNumbers--;
				}
				else
				{
					std::cout << "You already entered that number!\n";
				}
			}
			else
			{
				std::cout << "That number lies outside the specified range!\n";
			}
		}
		else
		{
			std::cout << "Invalid input!\n";
		}
	}
	std::cout << "Well done!\n";
	system("pause");
}
