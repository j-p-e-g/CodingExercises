#pragma once
#include "stdafx.h"
#include "Exercise.h"

//EXERCISE 25
//The country A has 50M inhabitants, and its population grows 3 % per year.The country B, 70M and grows 2 % per year.Tell in how many years A will surpass B.

class Exercise25 : Exercise
{
public:
	void mySolution();
	int calculateTimeWhenAExceedsB(const long i_initialValueA, const float i_percentGrowthA, const long i_initialValueB, const float i_percentGrowthB, long &o_finalValueA, long &o_finalValueB);
	int calculateTimeWhenAExceedsB_logCalc(const long i_initialValueA, const float i_percentGrowthA, const long i_initialValueB, const float i_percentGrowthB);
	long calculateExponentialGrowth(const long i_initialNumber, const float i_growthPercentage, const int i_years);
	float calculateExponential(const float i_base, const float i_exponential);
};
