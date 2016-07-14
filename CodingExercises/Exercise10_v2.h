#pragma once
#include "stdafx.h"
#include "Exercise10.h"
#include <functional>
#include <map>

//EXERCISE 10
//
//Write a program that is able to compute some operations on an integer.The program writes the value of the integer and writes the following menu :
//
//1. Add 1
//2. Multiply by 2
//3. Subtract 4
//4. Quit
//
//The programs ask the user to type a value between 1 and 4. If the user types a value from 1 to 3 the operation is computed, the integer is written and the menu is displayed again.If the user types 4, the program quits.

typedef std::function<int(int)> FunctionRef;

struct BoundCommand
{
public:
	BoundCommand() {};
	BoundCommand(FunctionRef i_funcRef, std::string i_desc)
	{
		m_functionRef = i_funcRef;
		m_description = i_desc;
	}

	FunctionRef m_functionRef;
	std::string m_description;
};

class ExerciseInputHandler
{
public:
	ExerciseInputHandler();

	void addCommand(char i_input, const FunctionRef &i_methodToExecute, const std::string i_commandDescription);
	void updateMenuDescription();

	// executes method mapped to the input
	// returns true if the user wants to quit
	bool handleInput(int &i_number);

	const std::string getCommandDescription() const
	{
		return m_menuDescription;
	}
	bool checkWantsToQuit() const { return m_wantsToQuit; }
	void setWantsToQuit() { m_wantsToQuit = true; }

	int quit(int i_number)
	{
		m_wantsToQuit = true;
		return i_number;
	}

	std::map<char, BoundCommand> m_commandMap;
	std::string m_menuDescription;
	bool m_wantsToQuit;
};

class IOHandler;
class Exercise10_v2 : Exercise10
{
public:
	// C'tor
	Exercise10_v2();

	void mySolution();

private:
	void initCommandMap();

	// too simple to unit test
	int addOne(int i_number)
	{
		return i_number + 1;
	}

	int multiplyByTwo(int i_number)
	{
		return i_number * 2;
	}

	int subtractFour(int i_number)
	{
		return i_number - 4;
	}

	IOHandler* m_ioHandler;
	ExerciseInputHandler* m_exerciseInputHandler;
};
