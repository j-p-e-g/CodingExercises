#include "stdafx.h"
#include "Exercise18.h"
#include "InputOutputHandler.h"

void Exercise18::mySolution()
{
	int number = askUserForNumber();
	std::string triangle = createTriangleString(number);
	outputString(triangle);
	system("pause");
}

int Exercise18::askUserForNumber()
{
	IOHandler* ioHandler = new IOHandler();
	int number;
	do
	{
		std::cout << "Enter the size of the triangle!\n";
	}
	while (!ioHandler->getNumberInput(number));

	return number;
}

std::string Exercise18::createTriangleString(const int i_num)
{
	std::string triangle;
	for (int j = i_num; j > 0; j--)
	{
		for (int k = 0; k < j; k++)
		{
			triangle += "*";
		}
		triangle += "\n";
	}
	return triangle;
}

void Exercise18::outputString(const std::string &i_string)
{
	std::cout << i_string;
}
