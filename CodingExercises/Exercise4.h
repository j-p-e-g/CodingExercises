#pragma once
#include "stdafx.h"
#include "Exercise.h"
#include <vector>

//EXERCISE 4
//Write a program that asks the user to type 10 integers and writes the sum of these integers.

class Exercise4 : Exercise
{
public:
	Exercise4() {};

	void myInitialSolution();
	void mySolution();
	const int calculateSum(const std::vector<int> &i_numbers) const;

private:
	const std::vector<int> getNumbersFromUser(const int i_amount) const;
};