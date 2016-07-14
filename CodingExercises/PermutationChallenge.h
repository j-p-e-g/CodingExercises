#pragma once
#include "stdafx.h"
#include "Exercise.h"
#include <vector>
#include <string>

//String Permutation Challenge
//
//Here is another mathematical problem, where the trick is as much to discover the algorithm as it is to write the code : write a program to display all possible permutations of a given input string--if the string contains duplicate characters, you may have multiple repeated results.Input should be of the form
//
//permute string
//
//and output should be a word per line.
//
//Here is a sample for the input cat
//
//cat (000)
//cta (010)
//act (100)
//atc (110)
//tac (210)
//tca (200)
//http://www.cprogramming.com/challenges/

class PermutationChallenge : Exercise
{
public:
	void mySolution();
	std::vector<std::string> getAllPermutations(const std::string &i_string) const;
	std::vector<std::string> getAllPermutationsWithoutIndices(const std::string &i_string) const;
	std::vector<std::vector<int>> getAllIndexPermutations(const int i_size) const;

	std::string getSinglePermutation(const std::string &i_string, const std::vector<int> &i_charIndices) const;
	void recursivelyAddIndex(std::vector<std::vector<int>> &io_indexPermutations, std::vector<int> &io_result, const int i_idx, const int i_max) const;
	void recursivelyAddChar(std::vector<std::string> &io_indexPermutations, const std::string &i_permutationStart, const std::string &io_remainingLetters) const;
};
