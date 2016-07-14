#include "stdafx.h"
#include "Exercise10.h"
#include <iostream>
#include <conio.h>
#include "InputOutputHandler.h"

void Exercise10::mySolution()
{
	IOHandler* ioHandler = new IOHandler();
	int number;
	do
	{
		std::cout << "Please enter a number: ";
	}
	while (!ioHandler->getNumberInput(number));

	bool quit = false;
	do
	{
		quit = handleInput(number);
	}
	while (!quit);
	system("pause");
}

bool Exercise10::handleInput(int &io_currValue)
{
	std::cout << "Press (1) to add 1\n";
	std::cout << "Press (2) to multiply by 2\n";
	std::cout << "Press (3) to subtract 4\n";
	std::cout << "Press (4) to quit\n";

	bool invalidInput = false;
	const char input = _getch();
	switch (input)
	{
	case '1':
		io_currValue++;
		break;
	case '2':
		io_currValue *= 2;
		break;
	case '3':
		io_currValue -= 4;
		break;
	case '4':
		// quit
		return true;
	default:
		std::cout << "Invalid input!\n";
		return false;
	}

	std::cout << "Current value: " << io_currValue << std::endl;
	return false;
}
