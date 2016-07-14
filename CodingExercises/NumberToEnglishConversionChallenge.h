#pragma once
#include "stdafx.h"
#include "Exercise.h"
#include <string>

//Integer to english number conversion
//
//Write a program that takes an integer and displays the English name of that value.
//
//You should support both positive and negative numbers, in the range supported by a 32 - bit integer(approximately - 2 billion to 2 billion).
//
//Examples:
//
//10->ten
//121->one hundred twenty one
//1032->one thousand thirty two
//11043->eleven thousand forty three
//1200000->one million two hundred thousand

class NumberToEnglishConversionChallenge : Exercise
{
public:
	void mySolution();
	std::string describeNumber(const int i_number) const;
	std::string handleNegativeNumber(const int i_number) const;
	std::string getNumberDescription(const int i_number) const;
	std::string getSingleDigitDescription(const int i_number) const;
	std::string getDoubleDigitDescription(const int i_number) const;
	std::string getTripleDigitDescription(const int i_number) const;
};
