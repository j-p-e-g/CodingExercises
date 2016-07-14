#include "stdafx.h"
#include "FactorialTrailingZeroesChallenge.h"
#include <iostream>
#include "InputOutputHandler.h"

void FactorialTrailingZeroesChallenge::mySolution()
{
	IOHandler* ioHandler = new IOHandler();
	int number;
	do
	{
		std::cout << "Enter a number: ";
	}
	while (!ioHandler->getNumberInput(number));

	std::cout << number << "! has " << getNumOfTrailingZeroesForFactorial(number) << " trailing zeroes.\n";
	system("pause");
}

int FactorialTrailingZeroesChallenge::getNumOfTrailingZeroesForFactorial(int i_num) const
{
	// The number of trailing zeroes is directly determined by the number of 
	// factors that combine to form a product of _ten_.
	// Ten has only two prime factors: 2 and 5.
	// In a given sequence of continuous numbers, multiples of 5 are rarer.
	// That means, that the number of trailing zeroes can be determined by the 
	// number of times the prime factor 5 turns up in the sequence.
	
	int countFactor5 = 0;
	// We only need to worry about multiples of 5
	for (int k = 5; k <= i_num; k += 5)
	{
		int temp = k;
		while (temp % 5 == 0) // multiple of 5
		{
			countFactor5++;
			temp /= 5;
		}
	}

	return countFactor5;
}