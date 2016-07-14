#include "stdafx.h"
#include "SubArraySumChallenge.h"
#include <iostream>

void SubArraySumChallenge::mySolution()
{
	const std::vector<int> numbers = { 2, -3, 5, -1, 2, -3, -1, 4, -2, 1 };
	const int subArraySum = getMaxSubArraySum(numbers);
	std::cout << "The maximum sum of a sub-array is " << subArraySum << ".\n";
	system("pause");
}

int SubArraySumChallenge::getMaxSubArraySum(const std::vector<int> &i_numbers) const
{
	// init with zero because that's the sum of the empty sub array
	int sum = 0;
	int maxSum = 0;

	for (std::vector<int>::const_iterator it = i_numbers.begin(), end = i_numbers.end(); it != end; it++)
	{
		if (sum < 0)
		{
			sum = *it;
		}
		else
		{
			sum += *it;
		}

		if (sum > maxSum)
		{
			maxSum = sum;
		}
	}
	return maxSum;
}

