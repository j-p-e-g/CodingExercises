#include "stdafx.h"
#include "WildcardStringSearchingChallenge.h"
#include <iostream>

void WildcardStringSearchingChallenge::mySolution()
{
	std::string baseString, pattern;
	std::cout << "Enter a string: ";
	std::cin >> baseString;
	std::cout << "Enter a pattern: ";
	std::cin >> pattern;
	std::cout << baseString << (isPatternInString(baseString, pattern) ? " contains " : " doesn't contain ") << pattern << std::endl;
	std::cout << baseString << (containsSubstring(baseString, pattern) ? " contains " : " doesn't contain ") << pattern << std::endl;
	system("pause");
}

bool WildcardStringSearchingChallenge::isPatternInString(const std::string &i_string, const std::string &i_pattern) const
{
	if (i_string.empty() || i_pattern.empty())
	{
		return false;
	}
	const std::vector<std::string> patternElements = splitPattern(i_pattern);
	if (patternElements.empty())
	{
		// contains only wildcards
		return true;
	}

	size_t stringPos = 0;
	for (std::vector<std::string>::const_iterator it = patternElements.begin(), end = patternElements.end(); it != end; it++)
	{
		stringPos = i_string.find(*it, stringPos);
		if (stringPos == std::string::npos)
		{
			return false;
		}
	}
	return true;
}

std::vector<std::string> WildcardStringSearchingChallenge::splitPattern(const std::string &i_pattern) const
{
	std::vector<std::string> patternElements;
	size_t patternPos = 0;
	std::string temp = "";
	while (true)
	{
		size_t wildcardPos = i_pattern.find("*", patternPos);
		if (wildcardPos == std::string::npos)
		{
			if (patternPos < i_pattern.size())
			{
				temp += i_pattern.substr(patternPos);
				patternElements.push_back(temp);
				temp = "";
			}
			break;
		}
		else
		{
			std::string subst = i_pattern.substr(patternPos, wildcardPos - patternPos);
			if (wildcardPos == 0 || i_pattern[wildcardPos - 1] != '\\')
			{
				temp += subst;
				if (!temp.empty())
				{
					patternElements.push_back(temp);
					temp = "";
				}
			}
			else
			{
				subst.replace(wildcardPos - patternPos - 1, 2, "*");
				temp += subst;
			}
			patternPos = wildcardPos + 1;
		}
	}
	if (!temp.empty())
	{
		patternElements.push_back(temp);
		temp = "";
	}
	return patternElements;
}

// NOTE: This doesn't cover all cases!
// Use dynamic programming instead.
bool WildcardStringSearchingChallenge::containsSubstring(const std::string &i_string, const std::string &i_pattern) const
{
	if (i_string.empty() || i_pattern.empty()) return false;

	size_t patternPos = 0;
	while (patternPos < i_pattern.size() && i_pattern[patternPos] == '*')
	{
		patternPos++;
	}

	for (std::string::const_iterator it = i_string.begin(), end = i_string.end(); it != end; it++)
	{
		char patternChar = i_pattern[patternPos];
		if (*it == patternChar || patternChar == '*' && (patternPos == 0 || i_pattern[patternPos-1] != '\\'))
		{
			if (++patternPos == i_pattern.size())
			{
				return true;
			}
		}
		else if (patternPos > 0)
		{
			patternPos = 0;
		}
	}

	if (patternPos > 0)
	{
		while (i_pattern[patternPos] == '*')
		{
			if (++patternPos == i_pattern.size())
			{
				return true;
			}
		}
	}

	return containsSubstring(i_string.substr(1), i_pattern);
}
