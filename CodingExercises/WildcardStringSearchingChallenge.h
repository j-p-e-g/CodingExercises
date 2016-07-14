#pragma once
#include "stdafx.h"
#include "Exercise.h"
#include <string>
#include <vector>

//String Searching Challenge
//
//Write a program that takes two arguments at the command line, both strings.The program checks to see whether or not the second string is a substring of the first(without using the substr-- or any other library -- function).One caveat : any * in the second string can match zero or more characters in the first string, so if the input were abcd and the substring were a*c, then it would count as a substring.Also, include functionality to allow an asterisk to be taken literally if preceded by a \, and a \ is taken literally except when preceding an asterisk.

class WildcardStringSearchingChallenge : Exercise
{
public:
	void mySolution();
	bool isPatternInString(const std::string &i_string, const std::string &i_pattern) const;
	std::vector<std::string> splitPattern(const std::string &i_pattern) const;
	bool containsSubstring(const std::string &i_string, const std::string &i_pattern) const;
};
