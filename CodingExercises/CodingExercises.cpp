// CodingExercises.cpp : Some programming exercises/challenges
// https://en.wikibooks.org/wiki/C%2B%2B_Programming/Exercises/Iterations
// http://www.cprogramming.com/challenge.html
//

#include "stdafx.h"
#include "FactorialTrailingZeroesChallenge.h"

int main()
{
	//Exercise *ex = reinterpret_cast<Exercise*>(new FactorialTrailingZeroesChallenge());
	Exercise *ex = (Exercise*) new FactorialTrailingZeroesChallenge();
	ex->mySolution();

    return 0;
}

