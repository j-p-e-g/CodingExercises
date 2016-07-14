#include "stdafx.h"
#include "Exercise10_v2.h"
#include "InputOutputHandler.h"
#include <functional>
#include <conio.h>

ExerciseInputHandler::ExerciseInputHandler() :
	m_wantsToQuit(false),
	m_menuDescription("")
{
}

void ExerciseInputHandler::addCommand(char i_inputKey, const FunctionRef &i_methodToExecute, const std::string i_commandDescription)
{
	m_commandMap[i_inputKey] = BoundCommand(i_methodToExecute, i_commandDescription);
}

void ExerciseInputHandler::updateMenuDescription()
{
	m_menuDescription = "";
	for (std::map<char, BoundCommand>::iterator it = m_commandMap.begin(), end = m_commandMap.end(); it != end; it++)
	{
		char desc[100];
		snprintf(desc, sizeof(desc), "(%c) to %s\n", it->first, it->second.m_description.c_str());
		m_menuDescription.append(desc);
	}
}

bool ExerciseInputHandler::handleInput(int &io_currValue)
{
	std::cout << getCommandDescription();

	char c = _getch();
	if (m_commandMap.find(c) != m_commandMap.end())
	{
		io_currValue = m_commandMap[c].m_functionRef(io_currValue);
		if (checkWantsToQuit())
		{
			return true;
		}
		std::cout << "Current value: " << io_currValue << std::endl;
	}
	else
	{
		std::cout << "Invalid input!\n";
	}
	return false;
}

Exercise10_v2::Exercise10_v2()
{
	m_ioHandler = new IOHandler();
	m_exerciseInputHandler = new ExerciseInputHandler();
	initCommandMap();
}

void Exercise10_v2::initCommandMap()
{
	m_exerciseInputHandler->addCommand('1', std::bind(&Exercise10_v2::addOne, this, std::placeholders::_1), "add 1");
	m_exerciseInputHandler->addCommand('2', std::bind(&Exercise10_v2::multiplyByTwo, this, std::placeholders::_1), "multiply by 2");
	m_exerciseInputHandler->addCommand('3', std::bind(&Exercise10_v2::subtractFour, this, std::placeholders::_1), "subtract 4");
	m_exerciseInputHandler->addCommand('4', std::bind(&ExerciseInputHandler::quit, m_exerciseInputHandler, std::placeholders::_1), "quit");

	m_exerciseInputHandler->updateMenuDescription();
}

void Exercise10_v2::mySolution()
{
	int number;
	do
	{
		std::cout << "Please enter a number: ";
	} while (!m_ioHandler->getNumberInput(number));

	bool quit = false;
	do
	{
		quit = m_exerciseInputHandler->handleInput(number);
	} while (!quit);
	system("pause");
}
