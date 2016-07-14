#pragma once
#include "stdafx.h"
#include "Exercise.h"

//Factorial Challenge
//
//Here's a challenge that's a bit more mathematical in nature.Write a program that determines the number of trailing zeros at the end of X!(X factorial), where X is an arbitrary number.For instance, 5!is 120, so it has one trailing zero. (How can you handle extremely values, such as 100!? ) The input format should be that the program asks the user to enter a number, minus the !.
// http://www.cprogramming.com/challenge.html

class FactorialTrailingZeroesChallenge : Exercise
{
public:
	void mySolution();
	int getNumOfTrailingZeroesForFactorial(int i_num) const;
};
