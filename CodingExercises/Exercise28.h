#pragma once
#include "stdafx.h"
#include "Exercise.h"
#include <string>

//EXERCISE 28
//Write a program for finding the amount of a specific character inside a string.

class Exercise28 : Exercise
{
public:
	void mySolution();
	int countNumberOfOccurencesInString(const std::string &i_string, const char i_char) const;
};
