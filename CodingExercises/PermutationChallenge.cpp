#include "stdafx.h"
#include "PermutationChallenge.h"
#include <iostream>

void PermutationChallenge::mySolution()
{
	std::cout << "Enter a string: ";
	std::string inputString;
	std::cin >> inputString;

	std::vector<std::string> permutations = getAllPermutations(inputString);
	for (std::vector<std::string>::iterator it = permutations.begin(), end = permutations.end(); it != end; it++)
	{
		std::cout << *it << std::endl;
	}
	system("pause");
}

std::vector<std::string> PermutationChallenge::getAllPermutations(const std::string &i_string) const
{
	std::vector<std::string> result;

	const std::vector<std::vector<int>> indexPermutations = getAllIndexPermutations(i_string.size());
	for (size_t j = 0; j < indexPermutations.size(); j++)
	{
		result.push_back(getSinglePermutation(i_string, indexPermutations[j]));
	}
	return result;
}

std::string PermutationChallenge::getSinglePermutation(const std::string &i_string, const std::vector<int> &i_charIndices) const
{
	std::string temp = i_string;
	std::string newPermutation;
	for (size_t k = 0; k < i_charIndices.size(); k++)
	{
		const int index = i_charIndices[k];
		newPermutation += temp[index];
		temp.erase(index, 1);
	}
	return newPermutation;
}

std::vector<std::vector<int>> PermutationChallenge::getAllIndexPermutations(const int i_size) const
{
	std::vector<std::vector<int>> indexPermutations;
	std::vector<int> indices;
	indices.resize(i_size);
	recursivelyAddIndex(indexPermutations, indices, 0, i_size);
	return indexPermutations;
}

void PermutationChallenge::recursivelyAddIndex(std::vector<std::vector<int>> &io_indexPermutations, std::vector<int> &io_result, const int i_idx, const int i_max) const
{
	if (i_max < 1)
	{
		io_indexPermutations.push_back(io_result);
	}
	else
	{
		for (int k = 0; k < i_max; k++)
		{
			io_result[i_idx] = k;
			recursivelyAddIndex(io_indexPermutations, io_result, i_idx + 1, i_max - 1);
		}
	}
}

std::vector<std::string> PermutationChallenge::getAllPermutationsWithoutIndices(const std::string &i_string) const
{
	std::vector<std::string> result;
	recursivelyAddChar(result, "", i_string);
	return result;
}

void PermutationChallenge::recursivelyAddChar(std::vector<std::string> &io_permutations, const std::string &i_permutationStart, const std::string &i_remainingLetters) const
{
	const int NUM_REMAINING_LETTERS = i_remainingLetters.size();
	if (NUM_REMAINING_LETTERS == 1)
	{
		io_permutations.push_back(i_permutationStart + i_remainingLetters);
	}
	else
	{
		for (int k = 0; k < NUM_REMAINING_LETTERS; k++)
		{
			// copy strings into new variables to pass into the recursion
			const std::string permutationStart = i_permutationStart + i_remainingLetters[k];

			// edit out the removed letter
			std::string remainingLetters = "";
			if (k > 0)
			{
				remainingLetters += i_remainingLetters.substr(0, k);
			}
			if (k < NUM_REMAINING_LETTERS - 1)
			{
				remainingLetters += i_remainingLetters.substr(k + 1, NUM_REMAINING_LETTERS - k - 1);
			}
			recursivelyAddChar(io_permutations, permutationStart, remainingLetters);
		}
	}
}
