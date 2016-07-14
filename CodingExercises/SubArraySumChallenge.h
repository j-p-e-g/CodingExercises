#pragma once
#include "stdafx.h"
#include "Exercise.h"
#include <vector>

//In this challenge, given an array of integers, the goal is to efficiently find the subarray that has the greatest value when all of its elements are summed together.Note that because some elements of the array may be negative, the problem is not solved by simply picking the start and end elements of the array to be the subarrray, and summing the entire array.
//
//For example, given the array
//
//{1, 2, -5, 4, -3, 2}
//
//
//The maximum sum of a subarray is 4. It is possible for the subarray to be zero elements in length(if every element of the array were negative).

class SubArraySumChallenge : Exercise
{
public: 
	void mySolution();
	int getMaxSubArraySum(const std::vector<int> &i_numbers) const;
};
